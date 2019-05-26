#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "SDL_Font.h"
#include "sdl.h"
#include "menu.h"
#include "SDL_audio.h"
#include "SDL_random.h"
#include "highscore.h"
#include "image.h"
#include "spielfeld.h"
#include "block.h"
#include "ki.h"
#include <windows.h>

#ifdef _WIN32
#undef main
#endif

int gamemain();

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	return gamemain();
}

using namespace std;

SDL_Font font;
bilder img;
SDL_Surface *screen;
audio audio;

spielfeld spl1(50,50,250,500,&screen, &audio, &img);
spielfeld spl2(500,50,250,500,&screen, &audio, &img);

void tausche_felder()
{
	audio.PlaySound("Explode.wav");
	bool temp;
	for (int g = 0 ; g < 12; g++)
	{
		for (int h = 0;h < 25; h++)
		{
			temp = spl1.feld[g][h];
			spl1.feld[g][h] = spl2.feld[g][h];
			spl2.feld[g][h] = temp;
		}
	}
}

void loesche_spielfeld(spielfeld & spl, bool halb)
{
	audio.PlaySound("Sound07.wav");

	if (halb == false)
	{
		for (int g = 0 ; g < 12; g++)
		{
			for (int h = 0 ; h < 25; h++)
			{
				spl.feld[g][h] = false;
			}
		}
	}
	else
	{
		for (int g = 0 ; g < 12; g++)
		{
			for (int h = 12 ; h < 25; h++)
			{
				spl.feld[g][h] = false;
			}
		}
	}
}
void splswitch()
{
	audio.PlaySound("Whoosh.wav");

	SDL_Rect temp;
	temp.x = spl1.flaeche.x;
	temp.y = spl1.flaeche.y;
	temp.w = spl1.flaeche.w;
	temp.h = spl1.flaeche.h;

	spl1.flaeche.x = spl2.flaeche.x;
	spl1.flaeche.y = spl2.flaeche.y;
	spl1.flaeche.w = spl2.flaeche.w;
	spl1.flaeche.h = spl2.flaeche.h;

	spl2.flaeche.x = temp.x;
	spl2.flaeche.y = temp.y;
	spl2.flaeche.w = temp.w;
	spl2.flaeche.h = temp.h;
}


void bomb_spielfeld(int nr, spielfeld *a, SDL_Surface** screen)
{
	int g;
	random rnd;
	SDL_Rect fla;
	spielfeld *spl;
	if (a == &spl1)
		spl = &spl2;
	else
		spl = &spl1;

	while (nr != 0)
	{
		audio.PlaySound("Kabumm.wav");
		int x,y;
		nr--;
		x = rnd.get_rnd(12);
		y = rnd.get_rnd(15);
		y +=10;
		fla.x = spl->flaeche.x + x*20;
		if (spl->rotate ==false)
		{
			fla.y = spl->flaeche.y +y*20;
		}
		else
		{
			fla.y = spl->flaeche.y + spl->flaeche.h - y*20;
		}
		fla.w=20;
		fla.h=20;
		for (g=0; g < 10;g++)
		{
			SDL_BlitSurface(img.expl[g],NULL,*screen,&fla);
			SDL_Flip(*screen);
			SDL_Delay(30);
			spl->feld[x][y] = false;
		}
	}
}

void keyswitch(spielfeld* a)
{
	audio.PlaySound("Amoebe.wav");
	spielfeld* spl;
	if (a == &spl1)
	{
		spl = &spl2;
	}
	else
	{
		spl = &spl1;
	}
	if (a->fkey == true)
	{
		a->fkey = false;
	}
	else
	{
		spl->fkey =true;
	}
	return;
}

void fieldrotate(spielfeld* a)
{
	audio.PlaySound("Ricochet.wav");

	spielfeld* spl;
	if (a == &spl1)
	{
		spl = &spl2;
	}
	else
	{
		spl = &spl1;
	}
	if (a->rotate == true)
	{
		a->rotate = false;
	}
	else
	{
		spl->rotate =true;
	}
	return;
}

void fieldshift(spielfeld* a)
{
	audio.PlaySound("yo.wav");
	spielfeld* spl;
	if (a == &spl1)
	{
		spl = &spl2;
	}
	else
	{
		spl = &spl1;
	}
	bool temp[25];
	for (int g =0; g <25;g++)
	{
		temp[g] = spl->feld[0][g];
		for (int h = 0;h <11;h++)
		{
			spl->feld[h][g] = spl->feld[h+1][g];
		}
		spl->feld[11][g] = temp[g];
	}
	return;
}


void draw_number(int number, SDL_Rect start)
{
	int g,j;
	SDL_Rect curr;
	curr.y = start.y;
	curr.h = 15;
	curr.w = 10;

	for (g = 10000000,j=0; g > 0 ; g=g/10,j++)
	{
		curr.x = start.x + j * 10;

		if (number ==0)
		{
			SDL_BlitSurface(img.nr[0],NULL,screen,&curr);
		}
		else
		{
			if (number % g != number)
			{
				SDL_BlitSurface(img.nr[number / g],NULL,screen,&curr);
				number -= (number/g)*g;
			}
			else
			{
				SDL_BlitSurface(img.nr[0],NULL,screen,&curr);
			}
		}
	}
}




void draw_stati()
{
	SDL_Rect punkte1, level1;
	SDL_Rect punkte2, level2;
	level1.x = 390;
	level1.y = 105;
	level1.w = 10;
	level1.h = 15;
	
	level2.x = 390;
	level2.y = 435;
	level2.w = 10;
	level2.h = 15;

	punkte1.x = 375;
	punkte1.y = 145;
	punkte1.w = 150;
	punkte1.h = 15;
		
	punkte2.x = 375;
	punkte2.y = 480;
	punkte2.w = 150;
	punkte2.h = 15;

	SDL_BlitSurface(img.nr[spl1.level],NULL,screen,&level1);
	SDL_BlitSurface(img.nr[spl2.level],NULL,screen,&level2);
	
	draw_number(spl1.punkte,punkte1);
	draw_number(spl2.punkte,punkte2);
}




void init()
{

	spl1.ende = false;
	spl2.ende = false;
	spl1.punkte = 0;
	spl2.punkte = 0;
	spl1.level = 0;
	spl2.level =0;
	spl1.rotate = false;
	spl2.rotate = false;
	loesche_spielfeld(spl1,false);
	loesche_spielfeld(spl2,false);
	spl1.fkey = false;
	spl2.fkey = false;
	spl1.flaeche.x = 50;
	spl1.flaeche.y = 50;
	spl1.flaeche.w = 250;
	spl1.flaeche.h = 500;
	spl2.flaeche.x = 500;
	spl2.flaeche.y = 50;
	spl2.flaeche.w = 250;
	spl2.flaeche.h = 500;
}


int gamemain()
{
	highscore *hsc = new highscore();
	hsc->load();
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(800, 600, 16, SDL_DOUBLEBUF);
	menue mnu(&screen);
	mnu.fullscreen = false;
	spl1.setScreen(&screen);
	spl2.setScreen(&screen);
	SDL_Rect temp;
	SDL_Color color;
	bool CPU1=false;
	bool CPU2=false;
	for(;;)
	{
		SDL_WM_SetCaption("HOTBLOCKS",NULL);
		SDL_Event event;
		Uint32 timer_start, timer_ende;
		block bl1(6,1,spl1,&img,&screen);
		block bl2(6,1,spl2,&img,&screen);
		ki_spl KI_CPU1(&spl1,&bl1);
		ki_spl KI_CPU2(&spl2,&bl2);
		SDL_Rect screen_fl;
		screen_fl.x = 0;
		screen_fl.y = 0;
		screen_fl.w = 800;
		screen_fl.h = 600;
		unsigned char *taste;
		mnu.sel_item = -1;
		while(mnu.sel_item == -1)
		{
			CPU1=false;
			CPU2=false;
			SDL_WaitEvent(&event);
			taste=SDL_GetKeyState(NULL);
			if(taste[SDLK_UP])
			{
				mnu.up();
			}
			if(taste[SDLK_DOWN])
			{
				mnu.down();
			}
			if (taste[SDLK_RETURN])
			{
				mnu.select();
			}
			mnu.draw();
			temp.x=700;
			temp.y=100;
			color.r=255;
			color.g=255;
			color.b=255;
		}
		if (mnu.sel_item ==1) 
		{
			CPU1 = true;
			mnu.sel_item =0;
		}

		if (mnu.sel_item ==2) 
		{
			CPU1 = true;
			CPU2 = true;
			mnu.sel_item =0;
		}
		if (mnu.sel_item ==0)
		{
			init();
			bool abgebrochen = false;
		
			while ( event.type !=SDL_QUIT &&spl1.ende == false && spl2.ende == false)
			{
				if (timer_ende - timer_start < 40) 
				{
					SDL_Delay(40-(timer_ende - timer_start));
				}
				timer_start = SDL_GetTicks();

				SDL_PollEvent(&event);
				if (taste[SDLK_ESCAPE])
				{
					abgebrochen = true;
					break;
				}
				if (taste[SDLK_p])
				{
					SDL_Rect fla;
					fla.x = 250;
					fla.y = 250;
					fla.w = 300;
					fla.h = 100;
					SDL_BlitSurface(img.pause,NULL,screen,&fla);
					SDL_Flip(screen);
					SDL_Delay(200);
					SDL_PollEvent(&event);
					taste=SDL_GetKeyState(NULL);
					while(!taste[SDLK_p])
					{
						taste=SDL_GetKeyState(NULL);
						SDL_PollEvent(&event);
					}
					SDL_Delay(200);
					SDL_PollEvent(&event);
				}
				if (spl2.fkey == false)
				{
					if(taste[SDLK_LEFT])
					{
						bl2.move_left();
					}
					if(taste[SDLK_RIGHT])
					{
						bl2.move_right();
					}
				}
				else
				{
					if(taste[SDLK_LEFT])
					{
						bl2.move_right();
					}
					if(taste[SDLK_RIGHT])
					{
						bl2.move_left();
					}
				}
				if(taste[SDLK_DOWN])
				{
					bl2.drop();
				}
				if (spl1.fkey ==false)
				{
					if(taste[SDLK_s])
					{
						bl1.move_left();
					}
					if(taste[SDLK_f])
					{
						bl1.move_right();
					}
				}
				else
				{
					if(taste[SDLK_s])
					{
						bl1.move_right();
					}
					if(taste[SDLK_f])
					{
						bl1.move_left();
					}
				}

				if(taste[SDLK_d])
				{
					bl1.drop();
				}
				*taste = '\0';		// zum verbessen der STeuerung
				if (CPU1)
				{
					KI_CPU1.invoke();
				}
				if (CPU2)
				{
					KI_CPU2.invoke();
				}
				bl1.move();
				bl2.move();        
				SDL_BlitSurface(img.background,NULL,screen,&screen_fl);
				draw_stati();
				spl1.draw();
				spl2.draw();
				bl1.draw();
				bl2.draw();
				SDL_Flip(screen);
				SDL_PollEvent(&event);
				timer_ende = SDL_GetTicks();
			}
			if (!abgebrochen)
			{

				if (spl1.ende == false)
				{
					spl1.punkte = spl1.punkte +500;
				}
				if (spl2.ende == false)
				{
					spl2.punkte = spl2.punkte +500;
				}
				SDL_Rect tb;
				char* text;
				if(!CPU1)
				{
					if (hsc->isHighscore(spl1.punkte))
					{
						tb.x=200;
						tb.y=200;
						tb.h=30;
						tb.w=300;
						font.init("Comic.ttf",20);
						text = font.makeTextBox(&screen,&tb,"HIGHSCORE! SPIELER 1:");
						hsc->addName(text,spl1.punkte);
					}
				}
				if (!CPU2)
				{
					if (hsc->isHighscore(spl2.punkte))
					{
						tb.x=200;
						tb.y=200;
						tb.h=30;
						tb.w=300;
						font.init("Comic.ttf",20);
						text = font.makeTextBox(&screen,&tb,"HIGHSCORE! SPIELER 2:");
						hsc->addName(text,spl2.punkte);
					}
				}
			}
		}
		if (mnu.sel_item ==3) 
		{
			hsc->draw(&screen);
		}

		if (mnu.sel_item ==4) 
		{
			if (!mnu.fullscreen)
			{
				screen = SDL_SetVideoMode(800, 600, 16, SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_HWSURFACE);
				mnu.fullscreen = true;
				SDL_ShowCursor(0);
			}
			else
			{
				screen = SDL_SetVideoMode(800, 600, 16, SDL_DOUBLEBUF);
				mnu.fullscreen = false;
				SDL_ShowCursor(1);
			}
			mnu.sel_item =-1;
		}
		if (mnu.sel_item ==5) 
		{
			SDL_Rect Sscreen;
			Sscreen.w = screen->w;
			Sscreen.h = screen->h;
			Sscreen.x = 0;
			Sscreen.y = 0;	
			SDL_BlitSurface(img.help,NULL,screen,&Sscreen);
			SDL_Flip(screen);
			SDL_Event event;
			unsigned char* taste;
			taste=SDL_GetKeyState(NULL);
			while (event.type !=SDL_KEYDOWN || taste[SDLK_RETURN])
			{
				SDL_WaitEvent(&event);
				taste=SDL_GetKeyState(NULL);
			}
		}
		if (mnu.sel_item ==6) 
		{
			SDL_Rect Sscreen;
			Sscreen.w = screen->w;
			Sscreen.h = screen->h;
			Sscreen.x = 0;
			Sscreen.y = 0;	
			SDL_BlitSurface(img.credits,NULL,screen,&Sscreen);
			SDL_Flip(screen);
			SDL_Event event;
			unsigned char* taste;
			taste=SDL_GetKeyState(NULL);
			while (event.type !=SDL_KEYDOWN || taste[SDLK_RETURN])
			{
				SDL_WaitEvent(&event);
				taste=SDL_GetKeyState(NULL);
			}
		}
		if (mnu.sel_item ==7) 
		{
			hsc->save();
			return 0;
		}
	}
}



