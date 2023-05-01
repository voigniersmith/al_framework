#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"

class App
{
	Window window;
	void show_help(char*);
	public:
		void init(int, char**);
		void start();
		void destroy();
};

#endif
