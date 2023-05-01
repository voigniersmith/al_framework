#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window
{
	// Primitive Fields
	int flag;

	public:
		int		width;
		int		height;
		
		int		flag_get();
		void 	flag_set(int);
		void 	flag_clear();
		void	flag_reset();

		void	width_reset();
		void	height_reset();
		
		void	init();
		void	start();
		void	destroy();
};
#endif
