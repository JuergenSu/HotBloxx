#include "menu.h"


menue::menue(SDL_Surface** pscreen)
{
	item = 0;
	sel_item = -1;
	screen = pscreen;
	font.init("Comic.ttf",25);

}
void menue::down()
{
	item ++;
	if (item > 7) item = 7;
}
void menue::up()
{
	item --;
	if (item <0 ) item =0;
}
void menue::select()
{
	sel_item = item;
}
void menue::draw()
{
	SDL_Rect fla;
	SDL_Rect screen_fl;

	fla.x = 250;
	fla.y = 150;
	fla.w = 400;
	fla.h = 30;

	screen_fl.x = 0;
	screen_fl.y = 0;
	screen_fl.w = (*screen)->w;
	screen_fl.h = (*screen)->h;
	
	
	SDL_BlitSurface(img.mnubackground,NULL,*screen,&screen_fl);
	blit_text("    SPIELER vs SPIELER",0,fla);
	fla.y+=fla.h;
	blit_text("    SPIELER vs CPU",1,fla);
	fla.y+=fla.h;
	blit_text("    CPU vs CPU",2,fla);
	fla.y+=fla.h;
	blit_text("    HIGHSCORE",3,fla);
	fla.y+=fla.h;
	if (fullscreen)
	{
		blit_text("    FENSTER",4,fla);
	}
	else
	{
		blit_text("    VOLLBILD",4,fla);
	}
	fla.y+=fla.h;
	blit_text("    HILFE",5,fla);
	fla.y+=fla.h;
	blit_text("    CREDITS",6,fla);
	fla.y+=fla.h;
	blit_text("    ENDE",7,fla);

	SDL_Flip(*screen);

}

void menue::blit_text(char* text, int pItem, SDL_Rect fla)
{
	SDL_Color color;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	SDL_Color colora;
	color.r = 0;
	color.g = 0;
	color.b = 0;

	if (item == pItem)
	{
		SDL_BlitSurface(font.renderFont(text,colora),NULL,*screen,&fla);
	}
	else
	{
		SDL_BlitSurface(font.renderFont(text,color),NULL,*screen,&fla);
	}
}
