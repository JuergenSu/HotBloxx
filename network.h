#include "sdl.h"
#include "SDL_Net.h"
#include "SDL_Font.h"

class SDL_Net
{
private:
	SDL_Font font;
	SDL_Surface* screen;
	TCPsocket own;
	bool server;
	bool networkGame;
	TCPsocket socket[3];
	void forward(int number);
	char* ownData;
	void waitForPlayer();
	void waitForGameStart();
public:
	SDL_Net(SDL_Surface*);
	bool Init(bool isServer);
	bool isServer();
	void Quit();
	void send(char*);
	char* recv();
	char* get_error();
	void make_server(int port);
	void connect_2_server(char* host,int port);
	void close(TCPsocket socket);
	TCPsocket accept();
	void handle_data();
	bool isNetworkGame();
};