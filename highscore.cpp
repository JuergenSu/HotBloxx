#include "highscore.h"


highscore::highscore()
{
}

void highscore::load()
{
	file.open("highscore.dat",ios_base::in);
	for (int g = 0; g<10;g++)
	{
		file >> punkte[g];
		name[g] = new char[200];
		file >> name[g];
	}
	file.close();
	sort();


}

void highscore::sort()
{
	for (int g = 0; g< 10 ; g++)
	{
		for (int h = 0; h< 9 ; h++)
		{
			if (punkte[h] < punkte[h+1])
			{
				int temp = punkte[h];
				punkte[h] = punkte[h+1];
				punkte[h+1] = temp;

				char temp2[255];
				strcpy(temp2,name[h]);
				strcpy(name[h],name[h+1]);
				strcpy(name[h+1], temp2);
			}
		}
	}
}


void highscore::addName(char* pname, int ppunkte)
{
	if (!isHighscore(ppunkte))
	{
		return;
	}
	for (int g=9; g>=0 ; g--)
	{
		if (ppunkte > punkte[g-1] && g !=0)
		{
			punkte[g] = punkte[g-1];
			strcpy(name[g],name[g-1]);
		}
		else
		{
			punkte[g] = ppunkte;
			strcpy(name[g],pname);
			break;
		}
	}
}

void highscore::save()
{
	ofstream file;
	file.open("highscore.dat",ios_base::out);
	for (int g =0; g < 10; g++)
	{
		if (name[g][0] == '\0' )
		{
			name[g][0] = '_';
			name[g][1] = '\0';
		}
		file << punkte[g] <<" "<< name[g] << endl;
	}
	file.close();
}
void highscore::draw(SDL_Surface** screen)
{

	SDL_Rect fla;
	fla.x = 300;
	fla.y = 50;
	fla.w = 400;
	fla.h = 30;
	SDL_Rect Sscreen;
	Sscreen.w = (*screen)->w;
	Sscreen.h = (*screen)->h;
	Sscreen.x = 0;
	Sscreen.y = 0;
	SDL_Color color;
	color.r=248;
	color.g=255;
	color.b=52;
	


	font.init("comic.ttf",20);
	
	SDL_BlitSurface(img.hsbackground,NULL,*screen,&Sscreen);
	SDL_BlitSurface(font.renderFont("HIGHSCORE",color),NULL,*screen,&fla);
	fla.x -=50;
	fla.y +=50;

	for (int g = 0; g < 10;g++)
	{
		fla.y +=35;
		SDL_BlitSurface(font.renderFont(punkte[g],color),NULL,*screen,&fla);
		fla.x += 100;
		SDL_BlitSurface(font.renderFont(name[g],color),NULL,*screen,&fla);
		fla.x -= 100;
	}

	fla.y +=35;
	
	SDL_BlitSurface(font.renderFont("Bitte taste drücken",color),NULL,*screen,&fla);
	

	SDL_Flip(*screen);
	SDL_Event event;
	while (event.type !=SDL_KEYDOWN)
	{
		SDL_WaitEvent(&event);	
	}
	
}





bool highscore::isHighscore(int ppunkte)
{
	if (ppunkte > punkte[9])
		return true;
	else
		return false;
}
