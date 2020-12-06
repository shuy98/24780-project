#ifndef PROJ24780_DICE_H_
#define PROJ24780_DICE_H_

#include "fssimplewindow.h"
#include "yspng.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

#define FILE_PATH "./picture/"

/**
 * @brief Dice class.
 */
class Dice {
  public:
    Dice() { _LoadImage(); };

    ~Dice(){};

    void SetLocation(int x, int y) {
        _x = x;
        _y = y;
    };
    /**
     * @brief Draw next Dice roll image.
     */
    void DrawNext() {
        if (pngs.size() == 0) {
            printf("[ERROR] Dice, no images loaded!!");
            return;
        }
        const auto &png = pngs[_i];
        if (0 < png.wid && 0 < png.hei) {
            glRasterPos2i(_x, _y + png.hei);
            glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
        }
        _i++;
        if (_i >= (int)pngs.size()) {
            _i = 0;
        }
        return;
    };
    /**
     *
     */
    void DrawStaticNumber(int val) {
        if ((val > 6) || (val < 1)) {
            printf("[ERROR] Dice, input value out of [1,6] range!!");
            return;
        }
        const auto &png = nums[val - 1];
        if (0 < png.wid && 0 < png.hei) {
            glRasterPos2i(_x, _y + png.hei);
            glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
        }
        return;
    }
    /**
     * @brief Return a random ranging from 1 to 6.
     */
    int Roll() {
        int curr_time = (int)time(NULL);
        srand(curr_time);
        _r = rand() % 6 + 1;
        return _r;
    }; // some animation? Return a random number.
    /**
     * @brief before first roll, return 0
     */
    int GetLastValue() { return _r; };

  protected:
    int _LoadImage() {
        pngs.resize(8);
        for (int i = 0; i < 8; i++) {
            std::string fname = FILE_PATH + std::string("roll") +
                                std::to_string(i + 1) + ".png";
            // YsRawPngDecoder png;
            if (YSOK == pngs[i].Decode(fname.c_str())) {
                pngs[i].Flip();
                printf("%d x %d png\n", pngs[i].wid, pngs[i].hei);
            } else {
                printf("[ERROR] Dice: Failed to load image.\n");
            }
        }
        nums.resize(6);
        for (int i = 0; i < 6; i++) {
            std::string fname = FILE_PATH + std::string("dice") +
                                std::to_string(i + 1) + ".png";
            if (YSOK == nums[i].Decode(fname.c_str())) {
                nums[i].Flip();
                printf("%d x %d png\n", nums[i].wid, nums[i].hei);
            } else {
                printf("[ERROR] Dice: Failed to load image.\n");
            }
        }
        return 1;
    };
    int _i = 0;
    int _r = 0;
    int _x = 0;
    int _y = 0;

    std::vector<YsRawPngDecoder> pngs;
    std::vector<YsRawPngDecoder> nums;
};

#endif // LR_COMMON_DEBUG_H_
