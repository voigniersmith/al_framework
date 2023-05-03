#ifndef AUDIO_HPP
#define AUDIO_HPP

class Audio {
	// Adding sounds/music
	void _add_sound_effect(char *, char *);
	void _add_music_track(char *, char *);

	// Retrieving sounds/music
	Sound * _get_sound_effect(char *);
	Music * _get_music_track(char *);

	// Cleaning up
	void _destroy();

	// Class Variables
	std::map<std::string, Sound> sfx;
	std::map<std::string, Music> bgm;

	float master_volume;
	float sfx_volume;
	float bgm_volume;

	public:
		// Initialization
		bool init();

		// Adding
		void add_sound_effect(char *, char *);
		void add_music_track(char *, char *);

		// Retrieving
		Sound * get_sound_effect(char *);
		Music * get_music_track(char *);

		void update_master_volume(float);
		void update_sfx_volume(float);
		void update_bgm_volume(float);

		float get_master_volume();
		float get_sfx_volume();
		float get_bgm_volume();

		// Cleaning up
		void destroy();
};
#endif
