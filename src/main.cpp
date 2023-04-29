#include "main.hpp"

// Main Function
int main(int argc, char** argv)
{
	App app;
	
	app.check_args(argc, argv);

	app.init();
	app.start();
	app.destroy();

	return 0;
}
