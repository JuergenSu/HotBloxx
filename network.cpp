#include "network.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

SDL_Net::SDL_Net(SDL_Surface* pScreen)
{
	screen = pScreen;
	font.init("comic.ttf",20);
	networkGame = false;
}
bool SDL_Net::Init(bool isServer)
{
	this->server = isServer;
	int i = SDLNet_Init();
	if (i ==-1)
	{
		return false;
	}
	return true;

	if (server == true)
	{
		make_server(45111);
	}
	else
	{
		char* host;
		SDL_Rect* fla;
		fla->x = 300;
		fla->w = 200;
		fla->h = 30;
		fla->y = 250;
		host = font.makeTextBox(screen,fla);
		connect_2_server(host,45111);
	}
}
void SDL_Net::Quit()
{
	SDLNet_Quit();
	return;
}

bool SDL_Net::isServer()
{
	return server;
}
bool SDL_Net::isNetworkGame()
{
	return networkGame;
}


void SDL_Net::make_server(int port)
{
	networkGame = true;
	IPaddress ip;
	if(SDLNet_ResolveHost(&ip,NULL,port)==-1) 
	{
		printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
	}
	own=SDLNet_TCP_Open(&ip);
	if(!own) {
		printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
	} 
	
	waitForPlayer();
}



void SDL_Net::connect_2_server(char* host,int port)
{
	networkGame = true;
	IPaddress ip;
	if(SDLNet_ResolveHost(&ip,host,port)==-1) 
	{
		printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		
	}
	own=SDLNet_TCP_Open(&ip);
	if(!own) {
		printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());

	}
	waitForGameStart();
}








void SDL_Net::waitForPlayer()
{
	unsigned char* taste;
	int player;
	taste=SDL_GetKeyState(NULL);
	while (!taste[SDLK_RETURN])
	{
		taste=SDL_GetKeyState(NULL);
		for (int g =0;g<3;g++)
		{
			if (this->socket[g] == NULL)
			{
				socket[g] = SDLNet_TCP_Accept(own);
				if (!socket[g] )
				{
					SDLNet_TCP_Send(socket[g],"player",2);
					player = g;
				}
			}
		}
		printf("%i",g);
		printf("player connected\n");

		
		
		
	}
	send("lets Start");
}


void SDL_Net::waitForGameStart()
{
}




void SDL_Net::forward(int number);

void SDL_Net::send(char*)
{
}
char* SDL_Net::recv();
char* SDL_Net::get_error();


void SDL_Net::close(TCPsocket socket);
TCPsocket SDL_Net::accept();
void SDL_Net::handle_data();

