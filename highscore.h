#include "SDL_Font.h"
#include "sdl.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <strstream>
#include "image.h"
using namespace std;

#ifndef _highscore
#define _highscore

class highscore
{
private:
	unsigned char *taste;
	bilder img;
	SDL_Font font;
	ifstream file;
	int punkte[10];
	char* name[10];
	void sort();
public:
	highscore();
	void load();
	bool isHighscore(int);
	void addName(char*, int);
	void save();
	void draw(SDL_Surface**);
};

#endif