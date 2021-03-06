#include "sfx.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "Dice.h"
#include "GamePiece.h"
#include <stdio.h>

int GSx[20];
int GSy[20];

void DrawRect(int x, int y, int size, int color) {
    if (color == 1) {
        glColor3ub(0, 0, 0); // black
    }
    else if (color == 2) {
        glColor3ub(255, 215, 0); // gold
    }
    else if (color == 3) {
        glColor3ub(255, 140, 0);
    }
    else if (color == 4) {
        glColor3ub(255, 165, 0);
    }
    else if (color == 5) {
        glColor3ub(27, 132, 44);
    }
    else if (color == 6) {
        glColor3ub(255, 255, 255);
    }
    else {
        glColor3ub(222, 13, 13);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_1(int x, int y, int size, int color) {
    if (color == 1) {
        glColor3ub(0, 0, 0); // black
    }
    else if (color == 2) {
        glColor3ub(153, 255, 255); // tiffany blue
    }
    else if (color == 3) {
        glColor3ub(255, 153, 153); // pink roof
    }
    else if (color == 4)         // white window
    {
        glColor3ub(255, 255, 255);
    }
    else // background grey
    {
        glColor3ub(224, 224, 224);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_2(int x, int y, int size, int color) {
    if (color == 1) {
        glColor3ub(0, 0, 0); // black
    }
    else if (color == 2) {
        glColor3ub(153, 153, 255); // tiffany blue
    }
    else if (color == 3) {
        glColor3ub(255, 0, 0); // pink roof
    }
    else if (color == 4)     // white window
    {
        glColor3ub(102, 178, 255);
    }
    else // background grey
    {
        glColor3ub(224, 224, 224);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_3(int x, int y, int size, int color) {
    if (color == 1) // black 1
    {
        glColor3ub(0, 0, 0); // black
    }
    else if (color == 2)   // blue roof @
    {
        glColor3ub(0, 76, 152);
    }
    else if (color == 3) // garage /
    {
        glColor3ub(153, 76, 0);
    }
    else if (color == 4) // side roof .
    {
        glColor3ub(51, 153, 255);
    }
    else if (color == 5) // background grey $
    {
        glColor3ub(224, 224, 224);
    }
    else if (color == 6) // windon !
    {
        glColor3ub(204, 255, 255);
    }
    else // ' '
    {
        glColor3ub(255, 102, 102);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_4(int x, int y, int size, int color) {
    if (color == 1) // black 1
    {
        glColor3ub(0, 0, 0);
    }
    else if (color == 2) // pink roof $
    {
        glColor3ub(255, 102, 102);
    }
    else if (color == 3) // white window .
    {
        glColor3ub(255, 255, 255);
    }
    else if (color == 4) // background grey @
    {
        glColor3ub(224, 224, 224);
    }
    else if (color == 5) // door !
    {
        glColor3ub(255, 0, 0);
    }

    else // purple
    {
        glColor3ub(178, 102, 255);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_5(int x, int y, int size, int color) {
    if (color == 1) // black 1
    {
        glColor3ub(0, 0, 0);
    }
    else if (color == 2) // roof /
    {
        glColor3ub(102, 51, 0);
    }
    else if (color == 3) // white window .
    {
        glColor3ub(255, 255, 255);
    }
    else if (color == 4) // background grey @
    {
        glColor3ub(224, 224, 224);
    }
    else if (color == 5) // door !
    {
        glColor3ub(255, 0, 0);
    }
    else {
        glColor3ub(255, 204, 153);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawRect_6(int x, int y, int size, int color) {
    if (color == 1) // black 1
    {
        glColor3ub(0, 0, 0);
    }
    else if (color == 2) // roof .
    {
        glColor3ub(102, 51, 0);
    }
    else if (color == 3) // !
    {
        glColor3ub(255, 0, 0);
    }
    else {
        glColor3ub(255, 215, 56);
    }
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void DrawCoin(int i, int j) {
    unsigned char pattern[] = {

        "   11111   "
        "  1.....1  "
        " 1..@@@@@1 "
        "1..@@@@@@/1"
        "1..11@@1@/1"
        "1.11@1@11@1"
        "1..1@@11@/1"
        "1..@@@@@@/1"
        " 1.@@@@@/1 "
        "  1/////1  "
        "   11111   "

    };
    int x, y;
    glBegin(GL_POLYGON);
    for (x = 0; x < 11; x++) {
        for (y = 0; y < 11; y++) {

            int index = x * 11 + y;
            if (i != 0 && j == 0) {
                int a = i + (x * 11);
                int b = y * 11;

                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else {
                    DrawRect(a, b, 11, 5);
                }
            }
            else if (i != 0 && j != 0) {
                int a = i + (x * 11);
                int b = j + (y * 11);

                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else {
                    DrawRect(a, b, 11, 5);
                }
            }
            else {
                int a = x * 11;
                int b = j + (y * 11);
                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else {
                    DrawRect(a, b, 11, 5);
                }
            }
        }
    }
    //glEnd();
    glFlush();
}

void DrawBrokenCoin(int i, int j) {
    unsigned char pattern[] = {

        "   11!!1   "
        "  1.!!..1  "
        " 1.!!@@@@1 "
        "1.!!!@@@@/1"
        "1..!!@@1@/1"
        "1.11!!@11@1"
        "1..1@!!1@/1"
        "1..@@!!!@/1"
        " 1.@@!!@/1 "
        "  1/!!//1  "
        "   11!!1   "

    };
    int x, y;
    glBegin(GL_POLYGON);
    for (x = 0; x < 11; x++) {
        for (y = 0; y < 11; y++) {

            int index = x * 11 + y;
            if (i != 0 && j == 0) {
                int a = i + (x * 11);
                int b = y * 11;

                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else if ('!' == pattern[index]) {
                    DrawRect(a, b, 11, 0);
                }
                else {
                    DrawRect(a, b, 11, 0);
                }
            }
            else if (i != 0 && j != 0) {
                int a = i + (x * 11);
                int b = j + (y * 11);

                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else if ('!' == pattern[index]) {
                    DrawRect(a, b, 11, 0);
                }
                else {
                    DrawRect(a, b, 11, 0);
                }
            }
            else {
                int a = x * 11;
                int b = j + (y * 11);
                if ('1' == pattern[index]) {
                    DrawRect(a, b, 11, 1);
                }
                else if ('.' == pattern[index]) {
                    DrawRect(a, b, 11, 2);
                }
                else if ('/' == pattern[index]) {
                    DrawRect(a, b, 11, 3);
                }
                else if ('@' == pattern[index]) {
                    DrawRect(a, b, 11, 4);
                }
                else if ('!' == pattern[index]) {
                    DrawRect(a, b, 11, 0);
                }
                else {
                    DrawRect(a, b, 11, 0);
                }
            }
        }
    }
    //glEnd();
    glFlush();
}

void DrawProp_1(int i, int j) {
    char pattern[] = {

        "     1     "
        "    111111 "
        "   11@...1 "
        "  11@@...1 "
        " 11@@@//.1 "
        "11@@@@//.1 "
        " 11@@@//.1 "
        "  11@@...1 "
        "   11@...1 "
        "    111111 "
        "     1     "

    };

    int size = 11;
    glBegin(GL_POLYGON);
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = i + (size * x);
            int b = size * y;
            if ('1' == pattern[index]) {
                DrawRect_1(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_1(a, b, size, 2);
            }
            else if ('/' == pattern[index]) {
                DrawRect_1(a, b, size, 4);
            }
            else if ('@' == pattern[index]) {
                DrawRect_1(a, b, size, 3);
            }
            else {
                DrawRect_1(a, b, size, 0);
            }
        }
    }
    //glEnd();
    glFlush();
}

void DrawProp_2(int i, int j) {
    char pattern[] = { "           "
                      " 1111111111"
                      " 1        1"
                      " 1 ./  ./ 1"
                      " 1 /.  /. 1"
                      " 1        1"
                      " 1 ./  ./ 1"
                      " 1 /.  /. 1"
                      " 1        1"
                      " 1111111111"
                      "           "

    };
    int size = 11;
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = i + (size * x);
            int b = size * y;
            if ('1' == pattern[index]) {
                DrawRect_2(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_2(a, b, size, 2);
            }
            else if ('/' == pattern[index]) {
                DrawRect_2(a, b, size, 4);
            }
            else if ('@' == pattern[index]) {
                DrawRect_2(a, b, size, 3);
            }
            else {
                DrawRect_2(a, b, size, 0);
            }
        }
    }
    glFlush();
}

void DrawProp_3(int i, int j) {
    char pattern[] = { "$@@@111111$"
                      "$@.@  ///1$"
                      "$@.@  ///1$"
                      "$@.@  ///1$"
                      "$@@@111111$"
                      "$@@@     1$"
                      "$@@@!!   1$"
                      "@@@@!! 111$"
                      "$@@@!!   1$"
                      "$$@@     1$"
                      "$$$@111111$" };
    int size = 11;
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = i + (size * x);
            int b = j + (size * y);
            if ('1' == pattern[index]) {
                DrawRect_3(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_3(a, b, size, 4);
            }
            else if ('/' == pattern[index]) {
                DrawRect_3(a, b, size, 3);
            }
            else if ('@' == pattern[index]) {
                DrawRect_3(a, b, size, 2);
            }
            else if ('!' == pattern[index]) {
                DrawRect_3(a, b, size, 6);
            }
            else if ('$' == pattern[index]) {
                DrawRect_3(a, b, size, 5);
            }
            else {
                DrawRect_3(a, b, size, 0);
            }
        }
    }
    glFlush();
}

void DrawProp_4(int i, int j) {
    char pattern[] = { "@@@@@@@@@@@"
                      "@@@11111111"
                      "@@11 1 1  1"
                      "@1$1 1 1  1"
                      "1$$1 1 1  1"
                      "1$$1.1.1!!1"
                      "1$$1.1.1!!1"
                      "1$$1 1 1  1"
                      "@1$1 1 1  1"
                      "@@11 1 1  1"
                      "@@@11111111" };
    int size = 11;
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = i + (size * x);
            int b = j + (size * y);
            if ('1' == pattern[index]) {
                DrawRect_4(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_4(a, b, size, 3);
            }
            else if ('@' == pattern[index]) {
                DrawRect_4(a, b, size, 4);
            }
            else if ('!' == pattern[index]) {
                DrawRect_4(a, b, size, 5);
            }
            else if ('$' == pattern[index]) {
                DrawRect_4(a, b, size, 2);
            }
            else {
                DrawRect_4(a, b, size, 0);
            }
        }
    }
    glFlush();
}

void DrawProp_5(int i, int j) {
    char pattern[] = { "@@111111111"
                      "@@1//1    1"
                      "111//1... 1"
                      "111//1... 1"
                      "@@1//1  !!!"
                      "@@1//1  !!!"
                      "@@1//1  !!!"
                      "@@1//1... 1"
                      "@@1//1... 1"
                      "@@1//1    1"
                      "@@111111111" };
    int size = 11;
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = size * x;
            int b = j + (size * y);
            if ('1' == pattern[index]) {
                DrawRect_5(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_5(a, b, size, 3);
            }
            else if ('@' == pattern[index]) {
                DrawRect_5(a, b, size, 4);
            }
            else if ('!' == pattern[index]) {
                DrawRect_5(a, b, size, 5);
            }
            else if ('/' == pattern[index]) {
                DrawRect_5(a, b, size, 2);
            }
            else {
                DrawRect_5(a, b, size, 0);
            }
        }
    }
    glFlush();
}

void DrawStart(int i, int j) {
    char pattern[] = { "           "
                      "   !       "
                      "  !!       "
                      " !!!  111  "
                      " !!!  111  "
                      " .....111  "
                      " .....111  "
                      "      111  "
                      "      111  "
                      "           "
                      "           " };
    int size = 11;
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            int index = x * 11 + y;
            int a = i + (size * x);
            int b = j + (size * y);
            if ('1' == pattern[index]) {
                DrawRect_6(a, b, size, 1);
            }
            else if ('.' == pattern[index]) {
                DrawRect_6(a, b, size, 2);
            }
            else if ('!' == pattern[index]) {
                DrawRect_6(a, b, size, 3);
            }
            else {
                DrawRect_6(a, b, size, 0);
            }
        }
    }
    glFlush();
}

void DrawRectangle(int x, int y, int dx, int dy, int r, int g,
    int b) // x and y given by top left corner
{
    glColor3ub(r, g, b);

    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + dx, y);
    glVertex2i(x + dx, y + dy);
    glVertex2i(x, y + dy);
    glEnd();
}

void DrawGamePieces(const std::vector<Player>& players, Game& game, int* done) {
    for (const Player& p : players) {
        int playerID = p.getID();
        int playerPos = p.getPosition();
        int totalSteps = p.getTotalSteps();
        int lastPlayerPos = p.getLastPosition();
        int lastTotalSteps = p.getLastTotalSteps();
        if (lastTotalSteps < totalSteps) {
            lastPlayerPos = (lastPlayerPos + 1) % 20;
            lastTotalSteps++;
            game.setLastLocation(playerID, lastPlayerPos, lastTotalSteps);
            playerPos = lastPlayerPos;
            if (lastTotalSteps >= totalSteps) {
                *done = 1;
            }
        }
        GamePiece gp(playerID + 1);
        int x = 0;
        int y = 0;
        if (playerID == 0) {
            x = GSx[playerPos] + 8;
            y = GSy[playerPos] + 8;
        }
        else if (playerID == 1) {
            x = GSx[playerPos] + 66;
            y = GSy[playerPos] + 8;
        }
        else if (playerID == 2) {
            x = GSx[playerPos] + 8;
            y = GSy[playerPos] + 66;
        }
        else if (playerID == 3) {
            x = GSx[playerPos] + 66;
            y = GSy[playerPos] + 66;
        }
        gp.Draw(x, y);
    }
}



void DrawGameSpaces() // PropertySoldState)
{
    /*int GSx[20];
    int GSy[20];*/

    int GSdeltax = 125;
    int GSdeltay = 125;

    // int GSr[20], GSg[20], Gsb[20];

    for (int i = 0; i < 20; ++i) {
        GSx[i] = 0;
        GSy[i] = 0;
        // GSr[i] = 0;
        // GSg[i] = 0;
        // Gsb[i] = 0;
    }

    for (int i = 0; i <= 6; ++i) // top row
    {
        GSx[i] = i * GSdeltax;
        GSy[i] = 0; // not needed, included for clarity
    }

    for (int i = 7; i <= 9; ++i) // right side, excluding top and bottom
    {
        GSx[i] = 6 * GSdeltax;
        GSy[i] = GSdeltay * (i - 6);
    }

    for (int i = 10; i <= 16; ++i) // bottom row
    {
        GSx[i] = GSx[6] - GSdeltax * (i - 10);
        GSy[i] = GSdeltay * 4;
    }

    for (int i = 17; i <= 19; ++i) // left side, exlcuding top and bottom
    {
        GSx[i] = 0; // not needed, included for clarity
        GSy[i] = GSy[16] - GSdeltay * (i - 16);
    }

    // setting color standards

    int STARTr = 255;
    int STARTg = 215;
    int STARTb = 56;

    int BLANKr = 56;
    int BLANKg = 126;
    int BLANKb = 255;

    int PROPAVAILr = 224;
    int PROPAVAILg = 224;
    int PROPAVAILb = 224;

    int PROPSOLDr = 115;
    int PROPSOLDg = 115;
    int PROPSOLDb = 115;

    int PLUSMONEYr = 27;
    int PLUSMONEYg = 132;
    int PLUSMONEYb = 44;

    int MINUSMONEYr = 222;
    int MINUSMONEYg = 13;
    int MINUSMONEYb = 13;

    // need state of properties to appropriately determine color

    int GSr[20] = { STARTr,     PLUSMONEYr,  PROPAVAILr, BLANKr,
                   PLUSMONEYr, BLANKr,      PROPAVAILr, MINUSMONEYr,
                   BLANKr,     PROPAVAILr,  MINUSMONEYr, BLANKr,
                   PLUSMONEYr, MINUSMONEYr, BLANKr,     PROPAVAILr,
                   PLUSMONEYr, BLANKr,      PROPAVAILr, MINUSMONEYr };

    int GSg[20] = { STARTg,     PLUSMONEYg,  PROPAVAILg, BLANKg,
                   PLUSMONEYg, BLANKg,      PROPAVAILg, MINUSMONEYg,
                   BLANKg,     PROPAVAILg,  MINUSMONEYg, BLANKg,
                   PLUSMONEYg, MINUSMONEYg, BLANKg,     PROPAVAILg,
                   PLUSMONEYg, BLANKg,      PROPAVAILg, MINUSMONEYg };

    int GSb[20] = { STARTb,     PLUSMONEYb,  PROPAVAILb, BLANKb,
                   PLUSMONEYb, BLANKb,      PROPAVAILb, MINUSMONEYb,
                   BLANKb,     PROPAVAILb,  MINUSMONEYb, BLANKb,
                   PLUSMONEYb, MINUSMONEYb, BLANKb,     PROPAVAILb,
                   PLUSMONEYb, BLANKb,      PROPAVAILb, MINUSMONEYb };

    // if (Property 1 owned)//repeat for each property
    //{
    //	GSr[2] = PROPSOLDr;
    //	GSg[2] = PROPSOLDg;
    //	GSb[2] = PROPSOLDb;
    //}

    for (int i = 0; i < 20; ++i) {
        DrawRectangle(GSx[i], GSy[i], GSdeltax, GSdeltay, GSr[i], GSg[i],
            GSb[i]);
    }

    for (int i = 0; i < 20; ++i) {
        DrawRectangle(GSx[i], GSy[i], GSdeltax, GSdeltay, GSr[i], GSg[i],
            GSb[i]);
        if (GSx[i] == 0 && GSy[i] == 0) {
            DrawStart(0, 0);
        }
        // coins
        else if (GSx[i] == 125 && GSy[i] == 0) {
            DrawCoin(125, 0);
        }
        else if (GSx[i] == 500 && GSy[i] == 0) {
            DrawCoin(500, 0);
        }
        else if (GSx[i] == 0 && GSy[i] == 500) {
            DrawCoin(0, 500);
        }
        else if (GSx[i] == 500 && GSy[i] == 500) {
            DrawCoin(500, 500);
        }
        else if (GSx[i] == 750 && GSy[i] == 500) {
            DrawBrokenCoin(750, 500);
        }
        else if (GSx[i] == 0 && GSy[i] == 125) {
            DrawBrokenCoin(0, 125);
        }
        else if (GSx[i] == 750 && GSy[i] == 125) {
            DrawBrokenCoin(750, 125);
        }
        else if (GSx[i] == 375 && GSy[i] == 500) {
            DrawBrokenCoin(375, 500);
        }
        // property 1
        else if (GSx[i] == 250 && GSy[i] == 0) {
            DrawProp_1(250, 0);
        }
        // property 2
        else if (GSx[i] == 750 && GSy[i] == 0) {
            DrawProp_2(750, 0);
        }
        // property 3
        else if (GSx[i] == 750 && GSy[i] == 375) {
            DrawProp_3(750, 375);
        }
        // property 4
        else if (GSx[i] == 125 && GSy[i] == 500) {
            DrawProp_4(125, 500);
        }
        // property 5
        else if (GSx[i] == 0 && GSy[i] == 250) {
            DrawProp_5(0, 250);
        }
    }

}

void DrawPlayerStats(const std::vector<Player>& players,
    const std::vector<Property>& properties) {
    int x = 150;
    int y = 150;
    int spacing = 150;
    int width = 125;
    int height = 325;

    char Properties[100] = "Properties:";

    for (int i = 0; i < 4; ++i) {
        // background block
        DrawRectangle(x, y, width, height, 56, 126, 255);

        Player currPlayer = players.at(i);

        // Write Player#
        char PlayerNum[100];
        sprintf(PlayerNum, "%s", currPlayer.getPlayerName().c_str());
        glColor3ub(255, 255, 255);
        glRasterPos2i(x + 5, y + 15);
        YsGlDrawFontBitmap10x14(PlayerNum);

        // Write money
        char PlayerMoney[100];
        sprintf(PlayerMoney, "Money: $%d", currPlayer.getBalance());
        glColor3ub(255, 255, 255);
        glRasterPos2i(x + 5, y + 35);
        YsGlDrawFontBitmap10x14(PlayerMoney);

        // Write properties owned

        glColor3ub(255, 255, 255);
        glRasterPos2i(x + 5, y + 55);
        YsGlDrawFontBitmap10x14(Properties);

        if (properties.at(0).getOwnerID() == i) {
            glColor3ub(255, 255, 255);
            glRasterPos2i(x + 5, y + 75);
            YsGlDrawFontBitmap10x14(properties.at(0).getName().c_str());
        }

        if (properties.at(1).getOwnerID() == i) {
            glColor3ub(255, 255, 255);
            glRasterPos2i(x + 5, y + 95);
            YsGlDrawFontBitmap10x14(properties.at(1).getName().c_str());
        }

        if (properties.at(2).getOwnerID() == i) {
            glColor3ub(255, 255, 255);
            glRasterPos2i(x + 5, y + 115);
            YsGlDrawFontBitmap10x14(properties.at(2).getName().c_str());
        }

        if (properties.at(3).getOwnerID() == i) {
            glColor3ub(255, 255, 255);
            glRasterPos2i(x + 5, y + 135);
            YsGlDrawFontBitmap10x14(properties.at(3).getName().c_str());
        }

        if (properties.at(4).getOwnerID() == i) {
            glColor3ub(255, 255, 255);
            glRasterPos2i(x + 5, y + 155);
            YsGlDrawFontBitmap10x14(properties.at(4).getName().c_str());
        }

        x += spacing;
    }
}

void DrawWhoseTurn(const std::vector<Player> &players,
                   int playerID) // check data type to be given
{
    // call only if it is time for next player to roll
    
    char RollMessage[100];
    for (int i = 0; i < 4; ++i) {
        Player currPlayer = players.at(i);
        if (i == playerID) {
            sprintf(RollMessage, "%s, please roll.", 
                currPlayer.getPlayerName().c_str());
        }
    }
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 300);
    YsGlDrawFontBitmap10x14(RollMessage);
}

void DrawBuyButtons(int price, std::string name) {
    // call only if player lands on buyable space
    char BuyMessage[100];
    sprintf(BuyMessage, "Will you buy %s", name.c_str());
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 450);
    YsGlDrawFontBitmap10x14(BuyMessage);
    char BuyMessage2[100];
    sprintf(BuyMessage2, "for $%d?", price);
    glRasterPos2i(900, 465);
    YsGlDrawFontBitmap10x14(BuyMessage2);

    int WidB = 88;
    int HeiB = 40;
    int yesX1 = 925;
    int yesY1 = 500;
    int noX1 = 1063;
    int noY1 = 500;
    // yes button
    DrawRectangle(yesX1, yesY1, WidB, HeiB, 150, 150, 150);
    glColor3ub(0, 0, 0);
    glRasterPos2i(955, 527);
    YsGlDrawFontBitmap10x14("Yes");

    // no button
    DrawRectangle(noX1, noY1, WidB, HeiB, 150, 150, 150);
    glColor3ub(0, 0, 0);
    glRasterPos2i((GLint)1097.5, 527);
    YsGlDrawFontBitmap10x14("No");
}

int CheckButtonPressed(int mx, int my) // call when left button clicked
{
    int WidB = 88;
    int HeiB = 40;
    int yesX1 = 925;
    int yesY1 = 500;
    int noX1 = 1063;
    int noY1 = 500;
    if (mx >= yesX1 && mx <= yesX1 + WidB && my >= yesY1 &&
        my <= yesY1 + HeiB) {
        // std::cout << "Pressed yes" << std::endl;
        return 1; // 1 for yes?
    }

    if (mx >= noX1 && mx <= noX1 + WidB && my >= noY1 && my <= noY1 + HeiB) {
        // std::cout << "Pressed no" << std::endl;
        return 2; // 2 for no
    }

    else // neither button clicked, i.e. stray click
    {
        return 0;
    }
}

void DrawLoseMoney(const std::vector<Player> &players, const int playerID,
                   const int MoneyLost) {
    char Summary[150];
    for (int i = 0; i < 4; ++i) {
        Player currPlayer = players.at(i);
        if (i == playerID) {
            sprintf(Summary, "%s lost $%d.",
                    currPlayer.getPlayerName().c_str(), MoneyLost);
        }
    }
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 475);
    YsGlDrawFontBitmap10x14(Summary);
}

void DrawGainMoney(const std::vector<Player> &players, const int playerID,
                   const int MoneyGained) {
    char Summary[150];
    for (int i = 0; i < 4; ++i) {
        Player currPlayer = players.at(i);
        if (i == playerID) {
            sprintf(Summary, "%s gained $%d.", currPlayer.getPlayerName().c_str(),
                    MoneyGained);
        }
    }
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 475);
    YsGlDrawFontBitmap10x14(Summary);
}

void DrawPayMoney(const std::vector<Player> &players, const int PlayerNumLose,
                  const int PlayerNumGained, const int MoneyPaid) {
    char Summary[150];
    Player payer, owner;
    for (int i = 0; i < 4; ++i) {
        Player currPlayer = players.at(i);
        if (i == PlayerNumLose) {
            payer = currPlayer;
        }
        if (i == PlayerNumGained) {
            owner = currPlayer;
        }
    }
    sprintf(Summary, "%s paid %s $%d", payer.getPlayerName().c_str(),
        owner.getPlayerName().c_str(), MoneyPaid);
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 475);
    YsGlDrawFontBitmap10x14(Summary);
}

int main(void) {
    FsOpenWindow(16, 16, 1200, 625, 1);
    Game game = Game(4);
    int diceRolled = 0;
    int terminate = 0;
    int swapToggle = 0;
    int playerMoveAnimDone = 0;
    Dice dice;
    dice.SetLocation(900, 0);

    // BGM and SFX objects
    sfx sfxBGM;
    sfxBGM.Initialize("sfx/Netherplace_Looping_quiet.wav");
    sfxBGM.playRepeat();
    sfx sfxClick;
    sfxClick.Initialize("sfx/sfx_sounds_button11.wav");
    sfx sfxEarnMoney;
    sfxEarnMoney.Initialize("sfx/sfx_coin_cluster5.wav");
    sfx sfxLoseMoney;
    sfxLoseMoney.Initialize("sfx/NOOOO.wav");

    while (terminate == 0) {
        // check if someone is bankrupt
        if (game.checkEndGame()) {
            std::vector<std::string> winner;
            winner = game.getWinner();
            // TODO: display winners on the panel
        }
        FsPollDevice();
        int key = FsInkey();

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        DrawGameSpaces();
        DrawGamePieces(game.getPlayers(), game, &playerMoveAnimDone);
        DrawPlayerStats(game.getPlayers(), game.getProperties());
        int lb, mb, rb, mx, my;
        auto event = FsGetMouseEvent(lb, mb, rb, mx, my);
        Player currPlayer = game.getCurrPlayer();
        int currPlayerID = currPlayer.getID();

        if (!diceRolled) {
            // wait for player action
            DrawWhoseTurn(game.getPlayers(), currPlayer.getID());
            dice.DrawNext();

            switch (key) {
            case FSKEY_SPACE:
                std::cout << "Player rolled" << std::endl;
                diceRolled = 1;
                dice.Roll();
                game.movePlayer(currPlayer.getID(), dice.GetLastValue());
                dice.DrawStaticNumber(dice.GetLastValue());
                FsSwapBuffers();
                FsSleep(2000);
                swapToggle = 1;
                break;
            default:
                break;
            }
        }
        else {
            // Player moved
            TileType currTile = game.getTileType(currPlayer.getPosition());
            if (currTile == TileType::EMPTY || currTile == TileType::START) {
                // Nothing, next player
                if (playerMoveAnimDone) {
                    diceRolled = 0;
                    game.nextPlayer();
                    playerMoveAnimDone = 0;
                }
            }
            else if (currTile == TileType::EARN_MONEY) {
                if (playerMoveAnimDone) {
                    sfxEarnMoney.playOnce();
                    game.setPlayerBalance(currPlayer.getID(),
                        currPlayer.getBalance() + 100);
                    diceRolled = 0;
                    DrawGainMoney(game.getPlayers(), currPlayer.getID(), 100);
                    FsSwapBuffers();
                    FsSleep(2000);
                    swapToggle = 1;
                    game.nextPlayer();
                    playerMoveAnimDone = 0;
                }
            }
            else if (currTile == TileType::LOSE_MONEY) {
                if (playerMoveAnimDone) {
                    sfxLoseMoney.playOnce();
                    game.setPlayerBalance(currPlayer.getID(),
                        currPlayer.getBalance() - 100);
                    diceRolled = 0;
                    DrawLoseMoney(game.getPlayers(), currPlayer.getID(), 100);
                    FsSwapBuffers();
                    FsSleep(2000);
                    swapToggle = 1;
                    game.nextPlayer();
                    playerMoveAnimDone = 0;
                }
            }
            else if (currTile == TileType::PROPERTY) {
                diceRolled = 1;
                Property currProperty =
                    game.getProperty(currPlayer.getPosition());
                int ownerID = currProperty.getOwnerID();
                int rent = currProperty.getRent();
                int price = currProperty.getPrice();
                std::string propertyName = currProperty.getName();
                int playerPos = currPlayer.getPosition();
                if (currProperty.getPosition() == playerPos) {
                    if (ownerID == -1 && currPlayer.getBalance() >= price) {
                        // Prompt buying option
                        DrawBuyButtons(price, propertyName);
                        if (event == FSMOUSEEVENT_LBUTTONDOWN) {
                            if (CheckButtonPressed(mx, my) == 1) {
                                // property sold
                                sfxClick.playOnce();
                                if (playerMoveAnimDone) {
                                    game.setPlayerBalance(
                                        currPlayerID,
                                        currPlayer.getBalance() - price);
                                    game.setPropertyOwner(playerPos,
                                        currPlayerID);
                                    diceRolled = 0;
                                    game.nextPlayer();
                                    playerMoveAnimDone = 0;
                                }
                            }
                            else if (CheckButtonPressed(mx, my) == 2) {
                                // property not sold
                                sfxClick.playOnce();
                                if (playerMoveAnimDone) {
                                    diceRolled = 0;
                                    game.nextPlayer();
                                    playerMoveAnimDone = 0;
                                }
                            }
                        }
                    }
                    else if (ownerID != -1 && ownerID != currPlayerID) {
                        // pay rent
                        if (playerMoveAnimDone) {
                            sfxLoseMoney.playOnce();
                            std::cout << "Player " << currPlayerID
                                << " pays rent" << std::endl;
                            game.setPlayerBalance(
                                currPlayerID, currPlayer.getBalance() - rent);
                            std::vector<Player> players = game.getPlayers();
                            for (Player& p : players) {
                                if (p.getID() == ownerID) {
                                    std::cout << "ownerID: " << ownerID
                                        << std::endl;
                                    game.setPlayerBalance(
                                        ownerID, p.getBalance() + rent);
                                    break;
                                }
                            }
                            diceRolled = 0;
                            DrawPayMoney(game.getPlayers(), currPlayerID, 
                                ownerID, rent);
                            FsSwapBuffers();
                            FsSleep(2000);
                            swapToggle = 1;
                            game.nextPlayer();
                            playerMoveAnimDone = 0;
                        }
                    } 
                    else if (ownerID != -1 && ownerID == currPlayerID) {
                        if (playerMoveAnimDone) {
                            game.upgradePropertyRent(playerPos);
                            diceRolled = 0;
                            game.nextPlayer();
                            playerMoveAnimDone = 0;
                        }
                    } else {
                        if (playerMoveAnimDone) {
                            diceRolled = 0;
                            game.nextPlayer();
                            playerMoveAnimDone = 0;
                        }
                    }
                }
            }
        }
        if (swapToggle) {
            swapToggle = 0;
            continue;
        }
        FsSwapBuffers();

        FsSleep(100);
    }

    // close sound effect players
    sfxBGM.close();
    sfxClick.close();
    sfxEarnMoney.close();
    sfxLoseMoney.close();
    return 0;
}