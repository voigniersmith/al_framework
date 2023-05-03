#include "main.hpp"

// Private Methods
void App::show_help(char* prog_name)
{
	printf(" \
			usage:\n\
			\t%s [arguments ...]\n\
			\n\
			available arguments:\n\
			\t--help (-h)                    display this message & exit\
			\t--fullscreen (-f)              start in fullscreen mode\
			\t--windowed (-w) WxH            start in windowed mode, with resolution WxH\
			\t                                   default is 640x480\
			", prog_name);
}

// Public Methods
void App::init(int argc, char** argv)
{
	// Set Defaults Here
	this->window.init();
	this->audio.init();

	const char * const short_opts = "fw:h";
	option long_opts[] = {
		{ "fullscreen", no_argument, NULL, 'f' },
		{ "windowed", required_argument, NULL, 'w' },
		{ "help", no_argument, NULL, 'h' },
		{ NULL, no_argument, NULL, 0 }
	};

	int opt = 0;
	int w = 0;
	int h = 0;
	char * token;
	while ((opt = getopt_long(argc, argv, short_opts, long_opts, NULL)) != EOF) {
		switch (opt) {
			case 'f':
				printf("got fullscreen flag\n");
				break;

			case 'w':
				token = strtok(optarg, "x");
				w = atoi(token);
				token = strtok(NULL, "x");
				h = token != NULL ? atoi(token) : 0;
				w = w < WINDOW_DEFAULT_W ? WINDOW_DEFAULT_W : w;
				h = h < WINDOW_DEFAULT_H ? WINDOW_DEFAULT_H : h;
				break;

			case 'h':
				show_help(argv[0]);
				break;

			default:
				break;
		}
	}
}

void App::start()
{
	this->window.start();

	// Driver Loop
	while (!WindowShouldClose())
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		window.update();
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
}

void App::destroy()
{
	this->window.destroy();
	this->audio.destroy();
}
