#include "block.h"

block::block(int px, int py,spielfeld &pspl, bilder* pimg, SDL_Surface** pscreen):spl(pspl)
	{
		screen = pscreen;
		img = pimg;
		init (px,py);
		setType();
		ctr_max = 25;
		ctr=ctr_max;
		anim_ctr=0;
		fdrop = false;
		ctr_drop =1;
	}

void block::check_ende()
	{
		if (y ==1)
		{
			if (spl.anmelden(x,y+1)==false)
			{
				spl.ende =true;
			}
		}
	}





void block::setType()
	{
		random rnd;
		int test;
		ctr_max= 25 - (spl.level *2.5);
		test =  rnd.get_rnd(4);
     	//test = 3;							// immer special
		if (test !=3) 
		{
			special =0;
//			special =9;
			return;
		}
		else
		{
			test =  rnd.get_rnd(9);
			special = test+1;
			//special = 3;				// immer bombe
			return;
		}
		
	}
			
	
	
void block::init(int px, int py)
	{
		x = px;
		y = py;
	}
	
	
void block::move_right()
	{
		int t = x + 1;
		if (t>10) return;
		if (spl.anmelden(t,y) ==true)
		{
			x = t;
		}

	}
	
	
void block::move_left()
	{
		int t = x-1;
		if (t <0) return;
		if (spl.anmelden(t,y) ==true)
		{
			x = t;
		}
	}
	
	
void block::drop()
	{
		fdrop = true;
		ctr = ctr_drop;
	}
	
	
void block::move()
	{
		ctr--;
		if (ctr <= 0)
		{
			if (fdrop==true)
			{
				ctr = ctr_drop;
			}
			else
			{
				ctr = ctr_max;
			}
			if (spl.anmelden(x,y+1)==true)
			{
				y++;
			}
			else
			{
				spl.lock(x,y,special);
				y =1;
				setType();
				fdrop = false;
				check_ende();
			}
		}
	}
	
	
void block::draw()
	{
		SDL_Surface *iBlock[2][2];
		SDL_Rect stein;
		if (spl.rotate == false)
		{
			if (ctr !=0)
			{
				stein.y = spl.flaeche.y + (y-1)*20 + (20 / (double)ctr_max * (ctr_max -ctr)) ;
			}
			else
			{
				stein.y = spl.flaeche.y + (y-1)*20+20 ;
			}
		}
		else
		{
			if (ctr !=0)
			{
				stein.y = spl.flaeche.y+spl.flaeche.h-20 -( (y)*20 + (20 / (double)ctr_max * (ctr_max -ctr)) );
			}
			else
			{
				stein.y = spl.flaeche.y+spl.flaeche.h-20 -( (y)*20+20 );
			}
		}

		stein.x=20;
		stein.h = 20;
		
		stein.x = spl.flaeche.x+ x*20;

		if (special==0)
		{
			iBlock[0][0] = img->block[0];
			iBlock[0][1] = img->block[0];
			iBlock[1][0] = img->block[0];
			iBlock[1][1] = img->block[0];
		}
		if (special==1)
		{
			iBlock[0][0] = img->bl_ch[0];
			iBlock[0][1] = img->bl_ch[1];
			iBlock[1][0] = img->bl_ch[2];
			iBlock[1][1] = img->bl_ch[3];
		}	

		if (special==2)
		{
			iBlock[0][0] = img->bl_cl[0];
			iBlock[0][1] = img->bl_cl[1];
			iBlock[1][0] = img->bl_cl[2];
			iBlock[1][1] = img->bl_cl[3];
		}	
		if (special==3)
		{
			iBlock[0][0] = img->bl_bb[0];
			iBlock[0][1] = img->bl_bb[1];
			iBlock[1][0] = img->bl_bb[2];
			iBlock[1][1] = img->bl_bb[3];
		}	
		if (special==4)
		{
			iBlock[0][0] = img->bl_ks[0];
			iBlock[0][1] = img->bl_ks[1];
			iBlock[1][0] = img->bl_ks[2];
			iBlock[1][1] = img->bl_ks[3];
		}
		if (special==5)
		{
			iBlock[0][0] = img->bl_fs[0];
			iBlock[0][1] = img->bl_fs[1];
			iBlock[1][0] = img->bl_fs[2];
			iBlock[1][1] = img->bl_fs[3];
		}
		if (special==6)
		{
			iBlock[0][0] = img->bl_rt[0];
			iBlock[0][1] = img->bl_rt[1];
			iBlock[1][0] = img->bl_rt[2];
			iBlock[1][1] = img->bl_rt[3];
		}
		if (special==7)
		{
			iBlock[0][0] = img->bl_gs[0];
			iBlock[0][1] = img->bl_gs[1];
			iBlock[1][0] = img->bl_gs[2];
			iBlock[1][1] = img->bl_gs[3];
		}
		if (special==8)
		{
			iBlock[0][0] = img->bl_fz[0];
			iBlock[0][1] = img->bl_fz[1];
			iBlock[1][0] = img->bl_fz[2];
			iBlock[1][1] = img->bl_fz[3];
		}
		if (special==9)
		{
			iBlock[0][0] = img->bl_sf[0];
			iBlock[0][1] = img->bl_sf[1];
			iBlock[1][0] = img->bl_sf[2];
			iBlock[1][1] = img->bl_sf[3];
		}
		SDL_BlitSurface(iBlock[0][0],NULL,*screen,&stein);	
		stein.x +=20;
		SDL_BlitSurface(iBlock[0][1],NULL,*screen,&stein);	
		stein.x -=20;
		stein.y +=20;
		SDL_BlitSurface(iBlock[1][0],NULL,*screen,&stein);	
		stein.x +=20;
		SDL_BlitSurface(iBlock[1][1],NULL,*screen,&stein);	
	}

