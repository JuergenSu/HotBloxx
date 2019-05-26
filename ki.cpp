#include "ki.h"

ki_spl::ki_spl(spielfeld* spl,block* temp)
{
	spf = spl;
	spb = temp;
}

void ki_spl::setSpielfeld(spielfeld* spl)
{
	spf = spl; 
}

void ki_spl::invoke()
{
	bool frei = true;
	for (int h = 24; h>0; h--)
	{
		for (int g = 0; g<11; g++)
		{
			if (spb->spl.feld[g][h] == false &&
				spb->spl.feld[g+1][h] == false &&
				spb->spl.feld[g][h+1] == false &&
				spb->spl.feld[g+1][h+1] == false
				)
			{
				frei = true;
				for (int z = h; z >0 ; z--)
				{
					if (spb->spl.feld[g][z] == true || spb->spl.feld[g+1][z] == true)
					{
						frei = false;
						break;
					}
				}
				if (frei)
				{
					if (spb->x > g)
					{
						spb->move_left();
					}
					if (spb->x < g)
					{
						spb->move_right();
					}				
					if (spb->x == g)
					{
						spb->drop();
					}
					goto ende;
				}
			}
		}
	}
ende:;

}

void ki_spl::setBlock(block* temp)
{
	spb = temp;
}
