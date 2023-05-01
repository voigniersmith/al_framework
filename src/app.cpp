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
		\t--windowed (-w) W H            start in windowed mode, with resolution WxH\
		\t                                   default is 640x480\
	", prog_name);
}

// Public Methods
void App::init(int argc, char** argv)
{
	// Set Defaults Here
	this->window.init();

	// Actually Check Arguments Here
	for (int i = 0; i < argc; i++) {
		printf("arg[%d] = '%s'\n", i, argv[i]);

		string s = argv[i];

		if (s == "--fullscreen") {}
		
		if (s == "--windowed") {
			int w = atoi(argv[i + 1]);
			int h = atoi(argv[i + 2]);

			w = w < WINDOW_W_DEFAULT ? WINDOW_W_DEFAULT : w;
			h = h < WINDOW_H_DEFAULT ? WINDOW_H_DEFAULT : h;
		}

		if (s == "--help")
			show_help(argv[0]);
	}
}

void App::start()
{
	this->window.start();
}

void App::destroy()
{
	this->window.destroy();
}
