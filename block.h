#ifndef CLASS_BLOCK
#define CLASS_BLOCK

#include <iostream>
#include "sdl.h"
#include "image.h"
#include "spielfeld.h"
using namespace std;

class block
{
private:
	int special;
	int ctr;
	int anim_ctr ;
	int ctr_max;
	int ctr_drop;
	bool fdrop;
	bilder* img;
	SDL_Surface** screen;

public:
	spielfeld &spl;
	int x;
	int y;
	block(int px, int py,spielfeld &pspl, bilder* pimg, SDL_Surface** pscreen);
	void check_ende();
	void setType();			
	void init(int px, int py);
	void move_right();
	void move_left();
	void drop();
	void move();
	void draw();
};

#endif