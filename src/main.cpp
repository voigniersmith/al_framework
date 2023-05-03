#include "main.hpp"

// Main Function
int main(int argc, char** argv)
{
	App app;// = new App(argc, argv);
	
	app.init(argc, argv);
	app.start();
	app.destroy();

	//delete(app);

	return 0;
}
