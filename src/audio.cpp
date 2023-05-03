#include "main.hpp"

// Public Functions
bool Audio::init() {
  InitAudioDevice();
  SetMasterVolume(MASTER_VOL_DEFAULT);
  return IsAudioDeviceReady();
}

void Audio::add_sound_effect(char * id, char * fname) {
  assert(id);
  assert(fname);
  this->_add_sound_effect(id, fname);
  return;
}

void Audio::add_music_track(char * id, char * fname) {
  assert(id);
  assert(fname);
  this->_add_music_track(id, fname);
  return;
}

Sound * Audio::get_sound_effect(char * id) {
  assert(id);
  return this->_get_sound_effect(id);
}

Music * Audio::get_music_track(char * id) {
  assert(id);
  return this->_get_music_track(id);
}

void Audio::destroy() {
  this->_destroy();
  return;
}

// Private Functions

void Audio::_add_sound_effect(char * id, char * fname) {
  Sound s = LoadSound(fname);
  this->sfx[id] = s;
  return;
}

void Audio::_add_music_track(char * id, char * fname) {
  Music s = LoadMusicStream(fname);
  this->bgm[id] = s;
  return;
}

Sound * Audio::_get_sound_effect(char * id) {
  if (this->sfx.find(id) == this->sfx.end()) {
    return NULL;
  }
  return &(this->sfx[id]);
}

Music * Audio::_get_music_track(char * id) {
  if (this->bgm.find(id) == this->bgm.end()) {
    return NULL;
  }
  return &(this->bgm[id]);
}

void Audio::_destroy() {
  for (auto & a : this->sfx) {
    UnloadSound(a.second);
  }
  for (auto & a : this->bgm) {
    UnloadMusicStream(a.second);
  }
  CloseAudioDevice();
  return;
}
