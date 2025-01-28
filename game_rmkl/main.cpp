//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
//!
//}=======================================================================

#include "TXLib.h"

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

int main()
{
txCreateWindow (640, 480);
string PAGE = "menu";
Button btn[4];

btn[0] = {100, 100, 200, 40, "Старт", true};
btn[1] = {100, 150, 200, 40, "Правила игры", true};
btn[2] = {100, 200, 200, 40, "Выход", true};
btn[3] = {0, 0, 200, 40, "Назад", true};
HDC fon = txLoadImage("pixelarts/fon.bmp");

while(!btn[2].click())
{

    txBegin();
    txClear();
    txSetFillColor (TX_YELLOW);
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

    if(PAGE == "rules")
    {
        txBitBlt(txDC(), 0, 0, 800, 600, fon);
        btn[3].draw();
        if(btn[3].click())
        {
            PAGE = "menu";
        }
        btn[2].visible = false;

        txSetFillColor (TX_YELLOW);
    }
    if(PAGE == "game")
    {

    }
        txEnd();
    txSleep(1);

}
txDeleteDC(fon);
}


