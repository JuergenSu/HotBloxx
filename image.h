#include "sdl.h"

#ifndef CLASS_BILDER
#define CLASS_BILDER

class bilder
{
public:
	SDL_Surface* credits;
	SDL_Surface* help;
	SDL_Surface* background;
	SDL_Surface* mnubackground;
	SDL_Surface* hsbackground;
	SDL_Surface* block[1];
	SDL_Surface* stein;
	SDL_Surface* alpha[10];
	SDL_Surface* expl[10];
	SDL_Surface* nr[10];
	SDL_Surface* bl_ch[4];
	SDL_Surface* bl_cl[4];
	SDL_Surface* bl_bb[4];
	SDL_Surface* bl_ks[4];
	SDL_Surface* bl_fs[4];
	SDL_Surface* bl_rt[4];
	SDL_Surface* bl_gs[4];
	SDL_Surface* bl_fz[4];
	SDL_Surface* bl_sf[4];
	SDL_Surface* pause;
	SDL_Surface* nochmal;
	bilder();
	void reload();
};

#endif