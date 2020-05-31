#pragma once
#include "Game.h"	
#include "Collision.h"
class Coin {
public:


	
	Coin(const char* texturesheet, int x, int y, int nFrames, int mSpeed);

	~Coin();

	void Update(SDL_Rect rect);
	void Render();

	SDL_Rect getRect();
	
	static int score;
	bool isAlive();
	void killCoin();
private:

	double xpos;
	double ypos;
	bool alive;
	SDL_Texture* coinTexture;
	SDL_Rect srcRect, destRect;
	SDL_Rect playerRect;
	bool animated = false;
	int frames = 0;
	int speed = 100;

	
};