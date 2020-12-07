#ifndef SFX_H
#define SFX_H

#include "yssimplesound.h"
#include <iostream>
#include <string>

class sfx {
  private:
    YsSoundPlayer player;
    YsSoundPlayer::SoundData wav;

  public:
    void Initialize(const char *dir) {
        if (YSOK != wav.LoadWav(dir)) {
            std::cout << "Failed to read" << std::endl;
        }

        player.Start();
        while (YSTRUE == player.IsPlaying(wav)) {
            player.KeepPlaying();
        }
    }

    void playOnce() { player.PlayOneShot(wav); }
    void playRepeat() { player.PlayBackground(wav); }
    void close() { player.End(); }
};

#endif