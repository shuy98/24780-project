#ifndef PROJ24780_GAME_PIECE_H_
#define PROJ24780_GAME_PIECE_H_

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "fssimplewindow.h"
#include "yspng.h"

#define FILE_PATH "./picture/"
/**
 * @brief GamePiece
 * figure resource will be place in a folder like ./game_piece_figs/
 */
class GamePiece {
  public:
    /**
     * @brief At most 5 players. id = 1,2,3,4,5
     */
    GamePiece(int id) {
        if ((id < 1) || (id > 5)) {
            printf(
                "[ERROR] GamePiece Invalid id of player, should be 1,2,3,4,5.");
        }
        _id = id;
        _LoadImage();
    };
    /**
     * @brief Draw the png image with the upper left corner locates at (x,y) in
     * OpenGL coordinates.
     */
    void Draw(int x, int y) {
        if (0 < _png.wid && 0 < _png.hei) {
            glRasterPos2i(x, y + _png.hei);
            glDrawPixels(_png.wid, _png.hei, GL_RGBA, GL_UNSIGNED_BYTE,
                         _png.rgba);
        }
    }

  protected:
    int _LoadImage() {
        std::string fname = FILE_PATH + std::to_string(_id) + ".png";
        // YsRawPngDecoder png;
        if (YSOK == _png.Decode(fname.c_str())) {
            _png.Flip();
            printf("%d x %d png\n", _png.wid, _png.hei);
        } else {
            printf("[ERROR] GamePiece: Failed to load image.\n");
        }
        return 1;
    };

    int _id = 0;
    YsRawPngDecoder _png;
};

#endif // PROJ24780_GAME_PIECE_H_
