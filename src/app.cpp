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
void App::check_args(int argc, char** argv)
{
	// Set Defaults Here
	// this->display.flag_reset();

	// Actually Check Arguments Here
	for (int i = 0; i < argc; i++) {
		printf("arg[%d] = '%s'\n", i, argv[i]);

		string s = argv[i];

		if (s == "--fullscreen") {
			//this->display.flag_clear();
			//this->display.flag_set(ALLEGRO_FULLSCREEN_WINDOW);
		}
		
		if (s == "--windowed") {
			int w = atoi(argv[i + 1]);
			int h = atoi(argv[i + 2]);

			w = w < DISP_W_DEFAULT ? DISP_W_DEFAULT : w;
			h = h < DISP_H_DEFAULT ? DISP_H_DEFAULT : h;

			//this->display.width = w;
			//this->display.height = h;
		}

		if (s == "--help")
			show_help(argv[0]);
	}
}

void App::init()
{
	// Need basic allegro initialization
	//assert(al_init());
	
	// Need a Display Object
	//this->display.init();

	// Need a Controller Object (Mouse/Keyboard/Etc.)
	// Need an Image Class
	// Need a Drawing Interface?
}

void App::start()
{
	//this->display.start();

//	while(!exit)
//	{
//		this->event.handle();
//	}
}

void App::destroy()
{
	//this->display.destroy();
}
