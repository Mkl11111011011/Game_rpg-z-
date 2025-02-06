#include "TXLib.h"
//structuri_start
struct Button
{

    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

    void draw()
    {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (TX_YELLOW);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_RED);
        txDrawText(x, y, x+w, y+h, text);
    }

    bool click()
    {
        return(txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1 && visible);
    }
};
struct Vizual
{
    int vid_nom;
    HDC blits;
    // = txLoadImage("pixelarts/New Piskel(3).bmp")
    int clectka_x;
    int clectka_y;
    int x;
    int y;
    void vid()
    {
        clectka_x = vid_nom / 10;
        clectka_y = vid_nom % 10;
    }
    void draw()
    {
        txTransparentBlt(txDC(), x, y, 96, 96, blits, 96*clectka_x, 96*clectka_y,TX_WHITE);
    }

};

//structuri_konec
//function_start




//function_konec
int main()
{
txCreateWindow (672, 480);
string PAGE = "menu";
Vizual vizual = {0 , txLoadImage("pixelarts/New Piskel (3).bmp") ,0 ,0 ,0 ,0};
//karta_i_otrisovka_start
int karta [35];

karta[0],karta[1],karta[2],karta[3],karta[4],karta[5],karta[6] =        23 , 23 , 23 , 23 , 23 , 23 , 23;
karta[7],karta[8],karta[9],karta[10],karta[11],karta[12],karta[13] =    23 , 22 , 22 , 22 , 22 , 22 , 23;
karta[14],karta[15],karta[16],karta[17],karta[18],karta[19],karta[20] = 23 , 22 , 22 , 34 , 22 , 22 , 23;
karta[21],karta[22],karta[23],karta[24],karta[25],karta[26],karta[27] = 23 , 22 , 22 , 22 , 22 , 22 , 23;
karta[28],karta[29],karta[30],karta[31],karta[32],karta[33],karta[34] = 23 , 23 , 23 , 23 , 23 , 23 , 23;
//karta_i_otrisovka_konec
//knopki_sart
Button btn[4];

btn[0] = {100, 100, 200, 40, "Старт", true};
btn[1] = {100, 150, 200, 40, "Правила игры", true};
btn[2] = {100, 200, 200, 40, "Выход", true};
btn[3] = {0, 0, 200, 40, "Назад", true};
//knopki_konec
//peremennie_start
int timer = 0;
int x_otrisovki = 0;
int y_otrisovki = 0;
//peremennie_konec
//podgruzca_kartinok_start
HDC fon = txLoadImage("pixelarts/fon.bmp");
//podgruzca_kartinok_start
//glavnicikl
while(!btn[2].click())
{
    //chastoptimiz_start
    txBegin();
    txClear();
    //chastoptimiz_konec
    txSetFillColor (TX_YELLOW);
    //menu_start
    if(PAGE == "menu")
    {
        txBitBlt(txDC(), 0, 0, 672, 480, fon);
        btn[0].draw();
        btn[1].draw();
        btn[2].draw();
        btn[2].visible = true;
        if(btn[0].click())
        {
            PAGE = "game";
        }
        if(btn[1].click())
        {
            PAGE = "rules";
        }

        txSetFillColor (TX_BLACK);
    }
    //menu_konec
    //rules_start
    if(PAGE == "rules")
    {
        txBitBlt(txDC(), 0, 0, 800, 600, fon);
        btn[3].draw();
        txSelectFont ("Times", 20);
        txTextOut (50, 60, "W,A,S,D - dvigenie;");
        txTextOut (50, 90, "8+(4,2,6) - v period;");
        txTextOut (50, 120, "2+(8,6,4) - nazad;");
        txTextOut (50, 150, "6+(8,4,2) - na pravo;");
        txTextOut (50, 180, "4+(8,6,2) - na levo;");
        txTextOut (50, 210, "levaia knopka vzaimodeisvii - dialog;");
        txTextOut (50, 240, "pravaia knopka vzaimodeisvii - ataka;");
        txTextOut (50, 270, "zadniaa knopka vzaimodeisvii - dash;");
        if(btn[3].click())
        {
            PAGE = "menu";
        }
        btn[2].visible = false;

        txSetFillColor (TX_YELLOW);
    }
    //rules_konec
    //game_start
    if(PAGE == "game")
    {
        while(timer != 35)
        {
            vizual.vid_nom = karta[timer];
            vizual.vid();
            if (x_otrisovki >= 8)
            {
                x_otrisovki = 0;
                y_otrisovki += 1;
                if (y_otrisovki >= 5)
                {
                    y_otrisovki = 0;
                }
            }
            vizual.x = 96 * x_otrisovki;
            vizual.y = 96 * y_otrisovki;
            vizual.draw();
            timer = timer + 1;
            x_otrisovki += 1;
        }
        timer = 0;



    }
    //game_start
    //chastoptimiz_start
        txEnd();
    txSleep(1);
    //chastoptimiz_konec
}
txDeleteDC(fon);
}


