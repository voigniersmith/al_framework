#include "main.hpp"

int	Display::flag_get()
{
	return this->flag;
}

void Display::flag_set(int f)
{
	this->flag |= f;
}

void Display::flag_clear()
{
	this->flag = 0;
}

void Display::flag_reset()
{
	//flag = ALLEGRO_WINDOWED;
	//flag |= ALLEGRO_RESIZABLE;
}

void Display::width_reset()
{
	this->width = DISP_W_DEFAULT;
}

void Display::height_reset()
{
	this->height = DISP_H_DEFAULT;
}

void Display::init()
{
	width_reset();
	height_reset();
}

void Display::start()
{	
	InitWindow(this->width, this->height, "STARTER TEXT");	
	//this->display = al_create_display(this->width, this->height);
	//assert(this->display);
}

void Display::destroy()
{
	//al_destroy_display(this->display);
}

