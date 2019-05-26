#ifndef MENUE
#define MENUE

#include "sdl.h"
#include "image.h"
#include "SDL_Font.h"

class menue
{
private:
	bilder img;
	SDL_Font font;
	int item;
	SDL_Surface** screen;
	void blit_text(char* text, int item, SDL_Rect fla);
public:
	bool fullscreen;
	int sel_item;
	menue(SDL_Surface**);
	void down();
	void up();
	void draw();
	void select();
};

#endif