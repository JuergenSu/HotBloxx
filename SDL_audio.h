#ifndef SDL_AUDIO
#define SDL_AUDIO

#include "sdl.h"
#include <iostream>
using namespace std;

#define NUM_SOUNDS 2

void mixaudio(void *unused, Uint8 *stream, int len);

class audio
{
private:
	SDL_AudioSpec fmt;
public:
	void init();
	audio();
	void PlaySound(char *file);
	void PlaySoundA(char *file);
};

#endif
