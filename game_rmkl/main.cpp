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
//classi_start
class Character
{
private:
    int sech [12];
    sech[0] = 00;
    sech[1] = 10;
    sech[2] = 20;
    sech[3] = 01;
    sech[4] = 11;
    sech[5] = 21;
    sech[6] = 02;
    sech[7] = 12;
    sech[8] = 22;
    sech[9] = 03;
    sech[10] = 13;
    sech[11] = 23;
    int a = 0;
    int b = 0;
    public:
    int x;
    int y;
    int clectka_x;
    int clectka_y;
    int index;
    HDC blits;
    bool vizible;
    bool r;
    bool l;
    bool u;
    bool d;
       void draw()
    {
        if (vizible == true)
        {
        if (index == 1)
        {
            a = 0;
        }
        if (index == 2)
        {
            a = 4;
        }
        if (index == 3)
        {
            a = 8;
        }
        if (r == true)
        {
            b = 1;
        }
        if (l == true)
        {
            b = 2;
        }
        if (u == true)
        {
            b = 3;
        }
        if (d == true)
        {
            b = 0;
        }
        clectka_x = sech[a+b] / 10;
        clectka_y = sech[a+b] % 10;
        txTransparentBlt(txDC(), x, y, 96, 96, blits, 96*clectka_x, 96*clectka_x,TX_WHITE);
        }
    }
};
//classi_konec
//function_start




//function_konec
int main()
{
txCreateWindow (672, 480);
string PAGE = "menu";
Vizual vizual = {0 , txLoadImage("pixelarts/New Piskel (3).bmp") ,0 ,0 ,0 ,0};
//knopki_sart
Button btn[4];

btn[0] = {100, 100, 200, 40, "�����", true};
btn[1] = {100, 150, 200, 40, "������� ����", true};
btn[2] = {100, 200, 200, 40, "�����", true};
btn[3] = {0, 0, 200, 40, "�����", true};
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
    //karta_i_otrisovka_start
int karta [35];

karta[0] = 20;
karta[1] = 20;
karta[2] = 20;
karta[3] = 20;
karta[4] = 20;
karta[5] = 20;
karta[6] = 20;

karta[7] = 20;
karta[8] = 00;
karta[9] = 00;
karta[10] = 00;
karta[11] = 00;
karta[12] = 00;
karta[13] = 20;

karta[14] = 20;
karta[15] = 00;
karta[16] = 00;
karta[17] = 03;
karta[18] = 00;
karta[19] = 00;
karta[20] = 20;

karta[21] = 20;
karta[22] = 00;
karta[23] = 00;
karta[24] = 00;
karta[25] = 00;
karta[26] = 00;
karta[27] = 20;

karta[28] = 20;
karta[29] = 20;
karta[30] = 20;
karta[31] = 20;
karta[32] = 20;
karta[33] = 20;
karta[34] = 20;
//karta_i_otrisovka_konec
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
            //vizual.vid();
            vizual.clectka_x = vizual.vid_nom / 10;
            vizual.clectka_y = vizual.vid_nom % 10;
            if (x_otrisovki > 6)
            {
                x_otrisovki = 0;
                y_otrisovki += 1;
                if (y_otrisovki > 4)
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


