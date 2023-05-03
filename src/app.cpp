#include "main.hpp"

#include <getopt.h>

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
  while ((opt = getopt_long(argc, argv, short_opts, long_opts, NULL)) != EOF) {
    switch (opt) {
      case 'f': {
        printf("got fullscreen flag\n");
        break;
      }
      case 'w': {
        int w = 0;
        int h = 0;
        char * token;
        token = strtok(optarg, "x");
        w = atoi(token);
        token = strtok(NULL, "x");
        h = token != NULL ? atoi(token) : 0;
        w = w < WINDOW_W_DEFAULT ? WINDOW_W_DEFAULT : w;
        h = h < WINDOW_H_DEFAULT ? WINDOW_H_DEFAULT : h;
        break;
      }
      case 'h': {
        show_help(argv[0]);
        break;
      }
      default: {
        break;
      }
    }
  }
}

void App::start()
{
	this->window.start();
}

void App::destroy()
{
	this->window.destroy();
  this->audio.destroy();
}
