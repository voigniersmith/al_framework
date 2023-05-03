#include "main.hpp"

void Window::title_set(string s)
{
	this->title = s;
}

bool Window::flag_check(int f)
{
	assert(f > 0);
	return IsWindowState(f);
}

void Window::flag_set(int f)
{
	assert(f > 0);
	SetWindowState(f);
}

void Window::flag_clear(int f)
{
	assert(f > 0);
	ClearWindowState(f);
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
	width_reset();
	height_reset();

	flag_set(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(WINDOW_DEFAULT_FPS);
}

void Window::start()
{	
	InitWindow(this->width, this->height, this->title.c_str());
}

void Window::update()
{
	// Set Logical Size in Case of Resize
	this->width = GetScreenWidth();
	this->height = GetScreenHeight();
}

