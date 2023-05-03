#include "main.hpp"

int	Window::flag_get()
{
	return this->flag;
}

void Window::flag_set(int f)
{
	this->flag = f;
}

void Window::flag_clear()
{
	this->flag = 0;
}

void Window::flag_reset()
{
}

void Window::width_reset()
{
	this->width = WINDOW_DEFAULT_W;
}

void Window::height_reset()
{
	this->height = WINDOW_DEFAULT_H;
}

void Window::init()
{
	SetTargetFPS(WINDOW_DEFAULT_FPS);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
}

void Window::start()
{	
	InitWindow(this->width, this->height, "STARTER TEXT");
}

void Window::destroy()
{
	CloseWindow();
}

