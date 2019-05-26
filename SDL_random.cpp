#include "SDL_random.h"

random::random()
{
	srand((unsigned) SDL_GetTicks());
}
int random::get_rnd(int a)
{
		return rand()%a;
}



