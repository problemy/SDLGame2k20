#include "Coin.h"
#include "TextureManager.h"


Coin::Coin(const char* texturesheet, int x, int y, int mSpeed, int nFrames)
{

	coinTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	animated = true;
	frames = nFrames;
	speed = mSpeed;
}


void Coin::Update()
{


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w /2;
	destRect.h = srcRect.h /2;

	if (animated)
	{

		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	}

}
void Coin::Render()
{
	SDL_RenderCopy(Game::renderer, coinTexture, &srcRect, &destRect);

}

 SDL_Rect* Coin::getRect()
{
	 return  &destRect;
}
