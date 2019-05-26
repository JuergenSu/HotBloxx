#include "image.h"

bilder::bilder()
{
	reload();
}
void bilder::reload()
{
	background = SDL_LoadBMP("spielfeld.bmp");
	hsbackground = SDL_LoadBMP("hsbg.bmp");
	mnubackground = SDL_LoadBMP("bg.bmp");
	block[0] = SDL_LoadBMP("block1.bmp");
	stein = SDL_LoadBMP("blockl.bmp");
	help = SDL_LoadBMP("help.bmp");
	credits = SDL_LoadBMP("credits.bmp");

	alpha[0] = SDL_LoadBMP("alpha9.bmp");
	alpha[1] = SDL_LoadBMP("alpha8.bmp");
	alpha[2] = SDL_LoadBMP("alpha7.bmp");
	alpha[3] = SDL_LoadBMP("alpha6.bmp");
	alpha[4] = SDL_LoadBMP("alpha5.bmp");
	alpha[5] = SDL_LoadBMP("alpha4.bmp");
	alpha[6] = SDL_LoadBMP("alpha3.bmp");
	alpha[7] = SDL_LoadBMP("alpha2.bmp");
	alpha[8] = SDL_LoadBMP("alpha1.bmp");
	alpha[9] = SDL_LoadBMP("alpha0.bmp");

	nr[0] = SDL_LoadBMP("0.bmp");
	nr[1] = SDL_LoadBMP("1.bmp");
	nr[2] = SDL_LoadBMP("2.bmp");
	nr[3] = SDL_LoadBMP("3.bmp");
	nr[4] = SDL_LoadBMP("4.bmp");
	nr[5] = SDL_LoadBMP("5.bmp");
	nr[6] = SDL_LoadBMP("6.bmp");
	nr[7] = SDL_LoadBMP("7.bmp");
	nr[8] = SDL_LoadBMP("8.bmp");
	nr[9] = SDL_LoadBMP("9.bmp");

	expl[0] = SDL_LoadBMP("expl1.bmp");
	expl[1] = SDL_LoadBMP("expl2.bmp");
	expl[2] = SDL_LoadBMP("expl3.bmp");
	expl[3] = SDL_LoadBMP("expl4.bmp");
	expl[4] = SDL_LoadBMP("expl5.bmp");
	expl[5] = SDL_LoadBMP("expl6.bmp");
	expl[6] = SDL_LoadBMP("expl7.bmp");
	expl[7] = SDL_LoadBMP("expl8.bmp");
	expl[8] = SDL_LoadBMP("expl9.bmp");
	expl[9] = SDL_LoadBMP("expl10.bmp");


	bl_ch[0] = SDL_LoadBMP("bl_ch1.bmp");
	bl_ch[1] = SDL_LoadBMP("bl_ch2.bmp");
	bl_ch[2] = SDL_LoadBMP("bl_ch3.bmp");
	bl_ch[3] = SDL_LoadBMP("bl_ch4.bmp");
	bl_ks[0] = SDL_LoadBMP("bl_ks1.bmp");
	bl_ks[1] = SDL_LoadBMP("bl_ks2.bmp");
	bl_ks[2] = SDL_LoadBMP("bl_ks3.bmp");
	bl_ks[3] = SDL_LoadBMP("bl_ks4.bmp");
	bl_cl[0] = SDL_LoadBMP("bl_cl1.bmp");
	bl_cl[1] = SDL_LoadBMP("bl_cl2.bmp");
	bl_cl[2] = SDL_LoadBMP("bl_cl3.bmp");
	bl_cl[3] = SDL_LoadBMP("bl_cl4.bmp");
	bl_bb[0] = SDL_LoadBMP("bl_bb1.bmp");
	bl_bb[1] = SDL_LoadBMP("bl_bb2.bmp");
	bl_bb[2] = SDL_LoadBMP("bl_bb3.bmp");
	bl_bb[3] = SDL_LoadBMP("bl_bb4.bmp");
	bl_fs[0] = SDL_LoadBMP("bl_fs1.bmp");
	bl_fs[1] = SDL_LoadBMP("bl_fs2.bmp");
	bl_fs[2] = SDL_LoadBMP("bl_fs3.bmp");
	bl_fs[3] = SDL_LoadBMP("bl_fs4.bmp");
	bl_rt[0] = SDL_LoadBMP("bl_rt1.bmp");
	bl_rt[1] = SDL_LoadBMP("bl_rt2.bmp");
	bl_rt[2] = SDL_LoadBMP("bl_rt3.bmp");
	bl_rt[3] = SDL_LoadBMP("bl_rt4.bmp");
	bl_gs[0] = SDL_LoadBMP("bl_gs1.bmp");
	bl_gs[1] = SDL_LoadBMP("bl_gs2.bmp");
	bl_gs[2] = SDL_LoadBMP("bl_gs3.bmp");
	bl_gs[3] = SDL_LoadBMP("bl_gs4.bmp");

	bl_fz[0] = SDL_LoadBMP("bl_fz1.bmp");
	bl_fz[1] = SDL_LoadBMP("bl_fz2.bmp");
	bl_fz[2] = SDL_LoadBMP("bl_fz3.bmp");
	bl_fz[3] = SDL_LoadBMP("bl_fz4.bmp");
	bl_sf[0] = SDL_LoadBMP("bl_sf1.bmp");
	bl_sf[1] = SDL_LoadBMP("bl_sf2.bmp");
	bl_sf[2] = SDL_LoadBMP("bl_sf3.bmp");
	bl_sf[3] = SDL_LoadBMP("bl_sf4.bmp");
	nochmal = SDL_LoadBMP("nochmal.bmp");
	pause = SDL_LoadBMP("pause.bmp");
}
