#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <raylib.h>

#include <map>

typedef enum {
  BGM,
  SFX
} SoundType;

class Audio {
  private:
    std::map<std::string, Sound> bgm;
    std::map<std::string, Sound> sfx;
    void _add_sound_track(char *, char *);
    void _add_sound_effect(char *, char *);
    Sound * _get_sound_track(char *);
    Sound * _get_sound_effect(char *);
    void _destroy();
  
  public:
    bool init();
    void add_sound(char *, char *, SoundType);
    Sound * get_sound(char *, SoundType);
    void destroy();
};
#endif
