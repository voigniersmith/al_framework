#ifndef APP_HPP
#define APP_HPP

class App
{
	void show_help(char*);
	public:
		void check_args(int, char**);

		void init();
		void start();
		void destroy();
};

#endif
