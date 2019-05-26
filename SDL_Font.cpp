#include "SDL_Font.h"	

SDL_Font::SDL_Font()
{
}	
void SDL_Font::init(char* file, int size)
{
	TTF_Init();
	font=TTF_OpenFont(file, size);
	if(!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}
}

SDL_Surface* SDL_Font::renderFont(char* text, SDL_Color &color)
{
	return TTF_RenderText_Solid(font,text, color);
}

void SDL_Font::quit()
{
	TTF_Quit();
}

char* SDL_Font::makeTextBox(SDL_Surface** screen, SDL_Rect* fla, char* caption)
{
	SDL_Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	text[0] = '\0';
	SDL_Rect textpos;

	textpos.x = fla->x;
	textpos.y = fla->y+20;
	textpos.h = fla->h;
	textpos.w = fla->w;


	SDL_FillRect(*screen,fla,SDL_MapRGB((*screen)->format,0,0,0));
	SDL_Flip(*screen);
	taste=SDL_GetKeyState(NULL);
	taste[SDLK_RETURN] = false;
	while (!taste[SDLK_RETURN])
	{
		SDL_FillRect(*screen,fla,SDL_MapRGB((*screen)->format,255,50,50));
		SDL_FillRect(*screen,&textpos,SDL_MapRGB((*screen)->format,255,50,50));
		SDL_BlitSurface(renderFont(caption,color),NULL,*screen,fla);
		SDL_BlitSurface(renderFont(text,color),NULL,*screen,&textpos);
		SDL_Flip(*screen);

		taste=SDL_GetKeyState(NULL);
		SDL_Event event;
		SDL_WaitEvent(&event);
		if (taste[SDLK_a])
		{
			addChar('A');
		}
		if (taste[SDLK_b])
		{
			addChar('B');
		}
		if (taste[SDLK_c])
		{
			addChar('C');
		}
		if (taste[SDLK_d])
		{
			addChar('D');
		}
		if (taste[SDLK_e])
		{
			addChar('E');
		}
		if (taste[SDLK_f])
		{
			addChar('F');
		}
		if (taste[SDLK_g])
		{
			addChar('G');
		}
		if (taste[SDLK_h])
		{
			addChar('H');
		}
		if (taste[SDLK_i])
		{
			addChar('I');
		}
		if (taste[SDLK_j])
		{
			addChar('J');
		}
		if (taste[SDLK_k])
		{
			addChar('K');
		}
		if (taste[SDLK_l])
		{
			addChar('L');
		}
		if (taste[SDLK_m])
		{
			addChar('M');
		}
		if (taste[SDLK_n])
		{
			addChar('N');
		}
		if (taste[SDLK_o])
		{
			addChar('O');
		}
		if (taste[SDLK_p])
		{
			addChar('P');
		}
		if (taste[SDLK_q])
		{
			addChar('Q');
		}
		if (taste[SDLK_r])
		{
			addChar('R');
		}
		if (taste[SDLK_s])
		{
			addChar('S');
		}
		if (taste[SDLK_t])
		{
			addChar('T');
		}
		if (taste[SDLK_u])
		{
			addChar('U');
		}
		if (taste[SDLK_v])
		{
			addChar('V');
		}
		if (taste[SDLK_w])
		{
			addChar('W');
		}
		if (taste[SDLK_x])
		{
			addChar('X');
		}
		if (taste[SDLK_y])
		{
			addChar('Y');
		}
		if (taste[SDLK_z])
		{
			addChar('Z');
		}
		if (taste[SDLK_BACKSPACE])
		{
			removeChar();
		}
		if (taste[SDLK_SPACE])
		{
			addChar('_');
		}
		*taste = '\0';
	}
	*taste = '\0';

	return text;

}

void SDL_Font::addChar(char letter)
{
	for (int g =0; g < 250;g++)
	{
		if (text[g] == '\0')
		{
			text[g] = letter;
			text[g+1] = '\0';
			return;
		}
	}
}

void SDL_Font::removeChar()
{
	for (int g =0; g < 250;g++)
	{
		if (text[g+1] == '\0')
		{
			text[g] = '\0';
			return;
		}
	}
}

SDL_Surface* SDL_Font::renderFont(int number,SDL_Color &color)
{
	char text[255];
	char rtext[255];
	int div;
	int ziffer;
	int pos =0;
	while ((div = number/10) >=1)
	{	
		ziffer = number % 10;
		text[pos] = 48 + ziffer;
		pos++;
		number /= 10 ;
	}
	text[pos] = 48 + number;
	text[pos+1] = '\0';
	int lz = 0;
	if (pos >0)
	{
		while (lz <= pos)
		{
			rtext[lz] = text[pos-lz];
			lz++;
		}
	}
	rtext[lz] = '\0';
	return TTF_RenderText_Solid(font,rtext, color);
}