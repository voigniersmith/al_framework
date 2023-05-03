#include "main.hpp"

// Public Functions
bool Audio::init() {
	InitAudioDevice();
	SetMasterVolume(VOL_DEFAULT_MASTER);
	update_sfx_volume(VOL_DEFAULT_SFX);
	update_bgm_volume(VOL_DEFAULT_BGM);
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

void Audio::update_master_volume(float volume) {
	this->master_volume = volume;
	return;
}

void Audio::update_sfx_volume(float volume) {
	this->sfx_volume = volume;
	return;
}

void Audio::update_bgm_volume(float volume) {
	this->bgm_volume = volume;
	return;
}

float Audio::get_master_volume() {
	return this->master_volume;
}

float Audio::get_sfx_volume() {
	return this->sfx_volume;
}

float Audio::get_bgm_volume() {
	return this->bgm_volume;
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
	for (auto & sfx : this->sfx) {
		if (IsSoundPlaying(sfx.second)) {
			StopSound(sfx.second);
		}
		UnloadSound(sfx.second);
	}
	for (auto & bgm : this->bgm) {
		if (IsMusicStreamPlaying(bgm.second)) {
			StopMusicStream(bgm.second);
		}
		UnloadMusicStream(bgm.second);
	}
	CloseAudioDevice();
	return;
}
