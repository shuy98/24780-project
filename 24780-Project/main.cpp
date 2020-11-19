#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "Dice.hpp"
#include "GamePiece.hpp"

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

void DrawGameSpaces(const std::vector<Player> &players) // PropertySoldState)
{
    int GSx[20];
    int GSy[20];

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

    int PROPAVAILr = 0;
    int PROPAVAILg = 0;
    int PROPAVAILb = 0;

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

    int GSr[20] = {STARTr,     PLUSMONEYr,  PROPAVAILr, BLANKr,
                   PLUSMONEYr, BLANKr,      PROPAVAILr, MINUSMONEYr,
                   BLANKr,     PROPAVAILr,  PLUSMONEYr, BLANKr,
                   PLUSMONEYr, MINUSMONEYr, BLANKr,     PROPAVAILr,
                   PLUSMONEYr, BLANKr,      PROPAVAILr, MINUSMONEYr};

    int GSg[20] = {STARTg,     PLUSMONEYg,  PROPAVAILg, BLANKg,
                   PLUSMONEYg, BLANKg,      PROPAVAILg, MINUSMONEYg,
                   BLANKg,     PROPAVAILg,  PLUSMONEYg, BLANKg,
                   PLUSMONEYg, MINUSMONEYg, BLANKg,     PROPAVAILg,
                   PLUSMONEYg, BLANKg,      PROPAVAILg, MINUSMONEYg};

    int GSb[20] = {STARTb,     PLUSMONEYb,  PROPAVAILb, BLANKb,
                   PLUSMONEYb, BLANKb,      PROPAVAILb, MINUSMONEYb,
                   BLANKb,     PROPAVAILb,  PLUSMONEYb, BLANKb,
                   PLUSMONEYb, MINUSMONEYb, BLANKb,     PROPAVAILb,
                   PLUSMONEYb, BLANKb,      PROPAVAILb, MINUSMONEYb};

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

    for (const Player &p : players) {
        int playerID = p.getID();
        int playerPos = p.getPosition();
        GamePiece gp = GamePiece(playerID + 1);
        int x = 0;
        int y = 0;
        if (playerID == 0) {
            x = GSx[playerPos] + 8;
            y = GSy[playerPos] + 8;
        } else if (playerID == 1) {
            x = GSx[playerPos] + 66;
            y = GSy[playerPos] + 8;
        } else if (playerID == 2) {
            x = GSx[playerPos] + 8;
            y = GSy[playerPos] + 66;
        } else if (playerID == 3) {
            x = GSx[playerPos] + 66;
            y = GSy[playerPos] + 66;
        }
        gp.Draw(x, y);
    }

}

void DrawPlayerStats(const std::vector<Player> &players,
                     const std::vector<Property> &properties) {
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
        sprintf(PlayerNum, "Player %d", currPlayer.getID());
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

        // Write rank

        char Rank[100];
        int Ranking = 0;
        sprintf(Rank, "Rank: %d", Ranking); // tie to player class info
        glColor3ub(255, 255, 255);
        glRasterPos2i(x + 5, y + 175);
        YsGlDrawFontBitmap10x14(Rank);

        // Display game piece
        {}

        x += spacing;
    }
}

void DrawWhoseTurn(int playerID) // check data type to be given
{
    // call only if it is time for next player to roll
    char RollMessage[100];
    sprintf(RollMessage, "Player %d, please roll.",
            playerID); // tie to player class info
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 300);
    YsGlDrawFontBitmap10x14(RollMessage);
}

void DrawBuyButtons() {
    // call only if player lands on buyable space
    glColor3ub(0, 0, 0);
    glRasterPos2i(900, 475);
    YsGlDrawFontBitmap10x14("Will you buy this property?");

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

int main(void) {
    FsOpenWindow(16, 16, 1200, 625, 1);
    Game game = Game(4);
    int diceRolled = 0;
    int terminate = 0;
    int swapToggle = 0;
    Dice dice;
    dice.SetLocation(900, 0);

    while (terminate == 0) {
        FsPollDevice();
        int key = FsInkey();

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        DrawGameSpaces(game.getPlayers());
        DrawPlayerStats(game.getPlayers(), game.getProperties());
        int lb, mb, rb, mx, my;
        auto event = FsGetMouseEvent(lb, mb, rb, mx, my);
        Player currPlayer = game.getCurrPlayer();
        int currPlayerID = currPlayer.getID();

        if (!diceRolled) {
            // wait for player action
            DrawWhoseTurn(currPlayer.getID());
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
        } else {
            // Player moved
            TileType currTile = game.getTileType(currPlayer.getPosition());
            if (currTile == TileType::EMPTY || currTile == TileType::START) {
                // Nothing, next player
                diceRolled = 0;
                game.nextPlayer();
            } else if (currTile == TileType::EARN_MONEY) {
                game.setPlayerBalance(currPlayer.getID(),
                                      currPlayer.getBalance() + 100);
                diceRolled = 0;
                game.nextPlayer();
            } else if (currTile == TileType::LOSE_MONEY) {
                game.setPlayerBalance(currPlayer.getID(),
                                      currPlayer.getBalance() - 100);
                diceRolled = 0;
                game.nextPlayer();
            } else if (currTile == TileType::PROPERTY) {
                diceRolled = 1;
                Property currProperty =
                    game.getProperty(currPlayer.getPosition());
                int ownerID = currProperty.getOwnerID();
                int rent = currProperty.getRent();
                int price = currProperty.getPrice();
                int playerPos = currPlayer.getPosition();
                if (currProperty.getPosition() == playerPos) {
                    if (ownerID == -1 && currPlayer.getBalance() >= price) {
                        // Prompt buying option
                        DrawBuyButtons();
                        if (event == FSMOUSEEVENT_LBUTTONDOWN) {
                            if (CheckButtonPressed(mx, my) == 1) {
                                // property sold
                                game.setPlayerBalance(currPlayerID,
                                                      currPlayer.getBalance() -
                                                          price);
                                game.setPropertyOwner(playerPos, currPlayerID);
                                diceRolled = 0;
                                game.nextPlayer();
                            } else if (CheckButtonPressed(mx, my) == 2) {
                                // property not sold
                                diceRolled = 0;
                                game.nextPlayer();
                            }
                        }
                    } else if (ownerID != -1 && ownerID != currPlayerID) {
                        // pay rent
                        std::cout << "Player " << currPlayerID << " pays rent"
                                  << std::endl;
                        game.setPlayerBalance(currPlayerID,
                                              currPlayer.getBalance() - rent);
                        std::vector<Player> players = game.getPlayers();
                        for (Player &p : players) {
                            if (p.getID() == ownerID) {
                                std::cout << "ownerID: " << ownerID
                                          << std::endl;
                                game.setPlayerBalance(ownerID,
                                                      p.getBalance() + rent);
                                break;
                            }
                        }
                        diceRolled = 0;
                        game.nextPlayer();
                        std::cout << "next\n";
                    } else {
                        diceRolled = 0;
                        game.nextPlayer();
                    }
                }
            }
        }
        if (swapToggle) {
            swapToggle = 0;
            continue;
        }
        FsSwapBuffers();

        FsSleep(50);
    }

    return 0;
}