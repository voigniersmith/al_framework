#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "audio.hpp"

class App
{
	Window* window;
 	Audio audio;
	
	void init(int, char**);
	void show_help(char*);
	void destroy();
	
	public:
		App(int c, char** v)
		{
			init(c, v);
		}
		
		void start();

		~App()
		{
			destroy();
		}
};

#endif
