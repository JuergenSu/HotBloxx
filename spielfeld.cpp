#include "spielfeld.h"


spielfeld::spielfeld(int x, int y, int w, int h, SDL_Surface** pscreen, audio* paudio, bilder* pimg)
{
	img = pimg;
	sound = paudio;
	screen = pscreen;
	rotate = false;
	ende = false;
	flaeche.x = x;
	flaeche.y = y;
	flaeche.w = w;
	flaeche.h = h;
	rm_anim = false;
	rm_line1 = -1;
	rm_line2 = -1;
	for (int g =0; g < 12 ;g++)
	{
		for (int h =0 ;h<25;h++)
		{
			feld[g][h] = false;
		}
	}
	fkey = false;
	level =0;
}

void spielfeld::setScreen(SDL_Surface** pscreen)
{
	screen = pscreen;
}

void spielfeld::setLevel()
{
	if (punkte >300)
		level = 1;
	if (punkte >600)
		level = 2;
	if (punkte >1200)
		level = 3;
	if (punkte >2400)
		level = 4;
	if (punkte >3600)
		level = 5;
	if (punkte >4800)
		level = 6;
	if (punkte >6000)
		level = 7;
	if (punkte >7200)
		level = 8;
	if (punkte >9000)
		level = 9;
}
		
	
	
bool spielfeld::abmelden(int x, int y)
{
	feld[x][y] = false;
	feld[x][y+1] = false;
	feld[x+1][y] = false;
	feld[x+1][y+1] = false;
	return true;
}

	
bool spielfeld::anmelden(int x, int y)
{
	if (y >=24) return false;
	if (feld[x][y] == true ||
		feld[x][y+1] == true ||
		feld[x+1][y] == true ||
		feld[x+1][y+1] ==  true)
	{
		return false;
	}
	else
	{
		return true;
	}
}

	
void spielfeld::lock(int x, int y, int typ=0)
{
	setLevel();
	punkte+=4;
	feld[x][y] = true;
	feld[x][y+1] = true;
	feld[x+1][y] = true;
	feld[x+1][y+1] =  true;
	sound->PlaySound("tap.wav");
	
	if (typ ==8)
	{
		random rnd;
		typ = rnd.get_rnd(7);
	}
	if (check_rm(x,y) == 1)
	{
		punkte+=12;
		if (typ == 0)
		{
			sound->PlaySound("yippie.wav");
		}			
		if (typ != 0)
		{
			punkte+=25;
		}
		if (typ ==2)
		{
			remove();
			loesche_spielfeld(*this,false);
		}
		if (typ ==3)
		{
			remove();
			bomb_spielfeld(4,this,screen);
		}
		if (typ ==4)
		{
			remove();
			keyswitch(this);
		}
		if (typ ==5)
		{
			remove();
			splswitch();
		}
		if (typ ==6)
		{
			remove();
			fieldrotate(this);
		}
		if (typ ==7)
		{
			remove();
			punkte +=200;
		}
		if (typ ==9)
		{
			remove();
			fieldshift(this);
		}
	}
	
	if (check_rm(x,y) == 2)
	{
		
		punkte+=24;
		if (typ == 0)
		{
			sound->PlaySound("yippie.wav");
		}
		if (typ !=0)
		{
			punkte+=50;
		}
		if (typ == 1) 
		{
			remove();
			tausche_felder();
		}
		if (typ ==2)
		{
			remove();
			loesche_spielfeld(*this,false);
		}
		if (typ ==3)
		{
			remove();
			bomb_spielfeld(8,this,screen);
		}
		if (typ ==4)
		{
			remove();
			keyswitch(this);
		}
		if (typ ==5)
		{
			remove();
			splswitch();
		}
		if (typ ==6)
		{
			remove();
			fieldrotate(this);
		}
		if (typ ==7)
		{
			remove();
			punkte +=200;
		}
		if (typ ==9)
		{
			remove();
			fieldshift(this);
		}
	}
}
	
	
void spielfeld::remove()
	{
		int g,h;
		for (g = 0 ;g<12;g++)
		{
			if (rm_line1 != -1)
			{
				feld[g][rm_line1] = false;
			}
			if (rm_line2 != -1)
			{
				feld[g][rm_line2] = false;
			}
			for (h = rm_line1; h >0;h--)
			{
				for (g = 0 ;g<12;g++)
				{
					feld[g][h] = feld[g][h-1];
				}
			}
			for (g = 0 ;g<12;g++)
			{
				feld[g][0] = false;
			}
			for (h = rm_line2; h >0;h--)
			{
				for (g = 0 ;g<12;g++)
				{
					feld[g][h] = feld[g][h-1];
				}
			}
			for (g = 0 ;g<12;g++)
			{
				feld[g][0] = false;
			}
			anim_ctr=10;
			rm_line1 = -1;
			rm_line2 = -1;
			rm_anim=false;
		}
	}
	
	
	
void spielfeld::draw()
	{
		SDL_Rect fla;

		for (int g =0; g < 12 ;g++)
		{
			for (int h =0 ;h<25;h++)
			{
				if (feld[g][h] == true)
				{
					fla.x = flaeche.x + g*20;
					if (rotate == false)
					{
						fla.y = flaeche.y +h*20;
					}
					else
					{
						fla.y = (flaeche.y +flaeche.h-20)-h*20;
					}
					fla.w=20;
					fla.h=20;
					SDL_BlitSurface(img->stein,NULL,*screen,&fla);
				}

			}
		}
		if (rm_anim ==true)
		{
			anim_ctr --;
			if (anim_ctr> 0)
			{
				for (int g =0; g < 12 ;g++)
				{
					if (rm_line1 != -1)
					{
						fla.x = flaeche.x + g*20;
						if (rotate == false)
						{
							fla.y = flaeche.y + rm_line1 *20;
						}
						else
						{
							fla.y = (flaeche.y +flaeche.h-20)- rm_line1 *20;
						}

						fla.w=20;
						fla.h=20;
						SDL_BlitSurface(img->alpha[anim_ctr],NULL,*screen,&fla);
					}
					if (rm_line2 != -1)
					{
						fla.x = flaeche.x + g*20;
						if (rotate == false)
						{
							fla.y = flaeche.y + rm_line2 *20;
						}
						else
						{
							fla.y = (flaeche.y +flaeche.h-20)- rm_line2 *20;
						}
						fla.w=20;
						fla.h=20;
						SDL_BlitSurface(img->alpha[anim_ctr],NULL,*screen,&fla);
					}
				}
			}
			else
			{
				int g;
				for (g =0; g < 12 ;g++)
				{
					if (rm_line1 != -1)
					{
						fla.x = flaeche.x + g*20;
						if (rotate == false)
						{
							fla.y = flaeche.y + rm_line1 *20;
						}
						else
						{
							fla.y = (flaeche.y +flaeche.h-20)- rm_line1 *20;
						}
						fla.w=20;
						fla.h=20;
						SDL_BlitSurface(img->alpha[anim_ctr],NULL,*screen,&fla);
					}
					if (rm_line2 != -1)
					{
						fla.x = flaeche.x + g*20;
						if (rotate == false)
						{
							fla.y = flaeche.y + rm_line2 *20;
						}
						else
						{
							fla.y = (flaeche.y +flaeche.h-20)- rm_line2 *20;
						}
						fla.w=20;
						fla.h=20;
						SDL_BlitSurface(img->alpha[anim_ctr],NULL,*screen,&fla);
					}
				}
				remove();

			}
		}
	}
	
	
int spielfeld::check_rm(int x, int y)
	{
		int g;
		int nr = 0;
		bool complete1 = true;
		bool complete2 = true;
		for (g=0;g<12;g++)
		{
			if (feld[g][y] ==false)
			{
				complete1 = false;
			}
			if (feld[g][y+1] ==false)
			{
				complete2 = false;
			}

		} 
		for (g=0;g<12;g++)
		{
			if (complete1 == true)
			{
				rm_line1 = y;
				rm_anim=true;
				anim_ctr=10;
			}
			if (complete2 == true)
			{
				rm_line2 = y+1;
				rm_anim = true;
				anim_ctr=10;
			}
		}
		return complete1 + complete2;

	}


