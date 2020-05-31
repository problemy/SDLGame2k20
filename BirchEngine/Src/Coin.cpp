#include "Coin.h"
#include "TextureManager.h"
int Coin::score = 0;
bool coinColision;
Collision* colision;
int score = 0;
Coin::Coin(const char* texturesheet, int x, int y, int mSpeed, int nFrames)
{

	coinTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	animated = true;
	frames = nFrames;
	speed = mSpeed;
	alive = true;
}


void Coin::Update(SDL_Rect player)
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

	coinColision = colision->checkCollision(this->destRect, player );
	if (coinColision) {
		this->killCoin();
		
	}

}
void Coin::Render()
{
	if (alive) {
		SDL_RenderCopy(Game::renderer, coinTexture, &srcRect, &destRect);
	}
}

 SDL_Rect Coin::getRect()
{
	 return  destRect;
}

 void Coin::killCoin() {
	 alive = false;
	 ++score;
	 xpos = -80;
	 ypos = -80;
 }

 bool Coin::isAlive() {

	 return alive;
 }

