#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window
{
	public:
		int		width;
		int		height;
		string	title;
		
		void	title_set(string);
		bool	flag_check(int);
		void 	flag_set(int);
		void 	flag_clear(int);

		void	width_reset();
		void	height_reset();
		
		void	init();
		void	start();
		void	update();
		void	destroy();
};
#endif
