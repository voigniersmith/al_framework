#include "main.hh"

int main(int argc, char** argv)
{
	App app;
	
	app.check_args(argc, argv);

	app.init();
	app.start_loop();
	app.cleanup();

	return 0;
}
