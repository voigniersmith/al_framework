#include "main.hh"

void App::check_args(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	
	for (int i = 0; i < c; i++)
		printf("arg[%d] = '%s'\n", i, v[i]);
}

void App::init()
{
}

void App::start_loop()
{
}

void App::cleanup()
{
}
