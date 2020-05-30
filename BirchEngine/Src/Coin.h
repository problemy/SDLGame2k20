#pragma once
#include "Game.h"	

class Coin {
public:



	Coin(const char* texturesheet, int x, int y, int nFrames, int mSpeed);

	~Coin();


	void Update();

	void Render();

	SDL_Rect* getRect();

private:

	int xpos;
	int ypos;

	SDL_Texture* coinTexture;
	SDL_Rect srcRect, destRect;
	bool animated = false;
	int frames = 0;
	int speed = 100;

	
};