#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window
{
	void	init();

	public:
		int		width;
		int		height;
		string	title;
		
		Window()
		{
			init();
		}

		void	title_set(string);
		bool	flag_check(int);
		void 	flag_set(int);
		void 	flag_clear(int);

		void	width_reset();
		void	height_reset();
		
		void	start();
		void	update();

		~Window()
		{
			CloseWindow();
		}
};
#endif
