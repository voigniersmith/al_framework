#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <raylib.h>

#include <map>

class Audio {
  private:
    // Adding
    void _add_sound_effect(char *, char *);
    void _add_music_track(char *, char *);

    // Retrieving
    Sound * _get_sound_effect(char *);
    Music * _get_music_track(char *);

    // Cleaning up
    void _destroy();

    // Class Variables
    std::map<std::string, Sound> sfx;
    std::map<std::string, Music> bgm;
  
  public:
    // Initialization
    bool init();

    // Adding
    void add_sound_effect(char *, char *);
    void add_music_track(char *, char *);

    // Retrieving
    Sound * get_sound_effect(char *);
    Music * get_music_track(char *);

    // Cleaning up
    void destroy();
};
#endif
