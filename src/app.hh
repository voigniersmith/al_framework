class App
{
	int argc;
	char** argv;
	public:
		void check_args(int argc, char** argv);
		void init();
		void start_loop();
		void cleanup();
};
