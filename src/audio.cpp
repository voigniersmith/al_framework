#include "main.hpp"

bool Audio::init() {
  InitAudioDevice();
  return IsAudioDeviceReady();
}

void Audio::add_sound(char * id, char * fname, SoundType tp) {
  assert(id);
  assert(fname);
  if (tp == BGM) {
    this->_add_sound_track(id, fname);
    return;
  }
  if (tp == SFX) {
    this->_add_sound_effect(id, fname);
    return;
  }
  return;
}

Sound * Audio::get_sound(char * id, SoundType tp) {
  assert(id);
  if (tp == BGM) {
    return this->_get_sound_track(id);
  }
  if (tp == SFX) {
    return this->_get_sound_effect(id);
  }
  return NULL;
}

void Audio::destroy() {
  this->_destroy();
  return;
}

void Audio::_add_sound_track(char * id, char * fname) {
  Sound s = LoadSound(fname);
  this->bgm[id] = s;
  return;
}

void Audio::_add_sound_effect(char * id, char * fname) {
  Sound s = LoadSound(fname);
  this->sfx[id] = s;
  return;
}

Sound * Audio::_get_sound_track(char * id) {
  if (this->bgm.find(id) == this->bgm.end()) {
    return NULL;
  }
  return &(this->bgm[id]);
}

Sound * Audio::_get_sound_effect(char * id) {
  if (this->sfx.find(id) == this->sfx.end()) {
    return NULL;
  }
  return &(this->sfx[id]);
}

void Audio::_destroy() {
  for (auto & a : this->bgm) {
    UnloadSound(a.second);
  }
  for (auto & a : this->sfx) {
    UnloadSound(a.second);
  }
  CloseAudioDevice();
  return;
}
