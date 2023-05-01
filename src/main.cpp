#include "main.hpp"

// Main Function
int main(int argc, char** argv)
{
	App app;
	
	app.init(argc, argv);
	app.start();
	app.destroy();

	return 0;
}
