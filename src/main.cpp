#include "main.hpp"

// Main Function
int main(int argc, char** argv)
{
	App* app = new App(argc, argv);

	app->start();

	delete app;

	return 0;
}
