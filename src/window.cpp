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
	this->width = WINDOW_W_DEFAULT;
}

void Window::height_reset()
{
	this->height = WINDOW_H_DEFAULT;
}

void Window::init()
{
	width_reset();
	height_reset();
}

void Window::start()
{	
	InitWindow(this->width, this->height, "STARTER TEXT");	
}

void Window::destroy()
{
	CloseWindow();
}

