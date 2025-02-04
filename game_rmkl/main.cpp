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
struct vizual
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
        txTransparentBlt(txDC(), x, y, 32, 32, blits, 32*clectka_x, 32*clectka_y, TX_WHITE);
    }

};
//structuri_konec
int main()
{
txCreateWindow (640, 480);
string PAGE = "menu";
//knopki_sart
Button btn[4];

btn[0] = {100, 100, 200, 40, "Старт", true};
btn[1] = {100, 150, 200, 40, "Правила игры", true};
btn[2] = {100, 200, 200, 40, "Выход", true};
btn[3] = {0, 0, 200, 40, "Назад", true};
//knopki_konec
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
        txBitBlt(txDC(), 0, 0, 800, 600, fon);
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

    }
    //game_start
    //chastoptimiz_start
        txEnd();
    txSleep(1);
    //chastoptimiz_konec
}
txDeleteDC(fon);
}


