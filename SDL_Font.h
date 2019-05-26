#include "sdl.h"
#include "SDL_ttf.h"
#include <iostream>
using namespace std;

#ifndef _SDL_Font
#define _SDL_Font

class SDL_Font
{
private:
	unsigned char *taste;
	void addChar(char letter);
	void removeChar();
public:
	char text[255];
	TTF_Font* font;
	SDL_Font();
	void init(char* file, int size);
	SDL_Surface* renderFont(char* text,SDL_Color &color);
	SDL_Surface* renderFont(int number,SDL_Color &color);
	void quit();
	char* makeTextBox(SDL_Surface** screen, SDL_Rect* fla, char*);
};

#endif