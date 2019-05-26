#ifndef SPIELFELD
#define SPIELFELD

#include <iostream>
#include "sdl.h"
#include "SDL_audio.h"
#include "image.h"
#include "SDL_random.h"
using namespace std;

class spielfeld;
void tausche_felder();
void loesche_spielfeld(spielfeld &, bool );
void bomb_spielfeld(int,spielfeld*,SDL_Surface**);
void keyswitch(spielfeld* );
void splswitch();
void fieldrotate(spielfeld*);
void fieldshift(spielfeld*);


class spielfeld
{
private:
	int anim_ctr;
	bool rm_anim;
	int rm_line1;
	int rm_line2;
	bilder* img;
	SDL_Surface** screen;
	random rnd;
	audio* sound;
public:
	bool rotate; 
	bool ende;
	int punkte;
	int level;
	bool fkey;
	SDL_Rect flaeche;
	bool feld[12][25];
	spielfeld(int, int, int, int, SDL_Surface**, audio*, bilder*);
	void setScreen(SDL_Surface**);
	void setLevel();
	bool abmelden(int x, int y);
	bool anmelden(int x, int y);
	void lock(int, int, int);
	void remove();
	void draw();
	int check_rm(int x, int y);
};

#endif