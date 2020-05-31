#include "GameObject.h"
#include "TextureManager.h"
#include "Collision.h"
#include "Map.h"

bool collided = false;
GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;

	////Initialize the offsets
	//mPosX = 0;
	//mPosY = 0;

	////Set collision box dimension
	//mCollider.w = 16;
	//mCollider.h = 16;

	////Initialize the velocity
	//mVelX = 0;
	//mVelY = 0;
}
bool checkCollision(SDL_Rect a, SDL_Rect b)
{		//std::cout << "check collicions" << std::endl;
		if (
			a.x + a.w >= b.x &&
			b.x + b.w >= a.x &&
			a.y + a.h >= b.y &&
			b.y + b.h >= a.y
			)
		{
			//std::cout << " collide physics at x :" << a.x << b.x << std::endl;
			//std::cout << " collide physics at y: " << a.y << b.y << std::endl;
			return true;

		}
		return false;


	}


void GameObject::Update()
{

	srcRect.h = srcRect.w  = 32;
	srcRect.x = srcRect.y = 0;
	if (!collided) {
		xBeforeMove = xpos;
		yBeforeMove = ypos;
	}


		//std::cout << "Velocity" << velocity << std::endl;

		auto kstate = SDL_GetKeyboardState(NULL);
		if (kstate[SDL_SCANCODE_LEFT]) {
			xpos = xpos - 1 * velocity;
			velocity += 0.01;

		}
		if (kstate[SDL_SCANCODE_RIGHT]) {
			xpos = xpos + 1 * velocity;
			velocity += 0.01;
		}
		if (kstate[SDL_SCANCODE_UP]) {
			ypos = ypos - 1 * velocity;
			velocity += 0.01;
		}
		if (kstate[SDL_SCANCODE_DOWN]) {
			ypos = ypos + 1 * velocity;
			velocity += 0.01;
		}
	

		collider.x = xpos;
		collider.y = ypos;
		collider.w = collider.h = 16;
		collided = collideEnemy(collider);
		
		//std::cout << xpos << " x pos; " << ypos << "ypos;" << std::endl;
		
		if (collided) {
			destRect.x = xBeforeMove;
			destRect.y = yBeforeMove;
			xpos = xBeforeMove;
			ypos = yBeforeMove;
			velocity = 1;
		}
		else {
			destRect.x = xpos;
			destRect.y = ypos;
	
		}



		destRect.w = srcRect.w / 2;
		destRect.h = srcRect.h / 2;
}
	

//void GameObject::move(SDL_Rect& coin)
//{
//	//Move the dot left or right
//	mPosX += mVelX;
//	mCollider.x = mPosX;
//
//	//If the dot collided or went too far to the left or right
//	if ((mPosX < 0) || (mPosX + 16 > 800) || checkCollision(mCollider, coin))
//	{
//		//Move back
//		mPosX -= mVelX;
//		mCollider.x = mPosX;
//	}
//
//	//Move the dot up or down
//	mPosY += mVelY;
//	mCollider.y = mPosY;
//
//	//If the dot collided or went too far up or down
//	if ((mPosY < 0) || (mPosY + 16 > 640) || checkCollision(mCollider, coin))
//	{
//		//Move back
//		mPosY -= mVelY;
//		mCollider.y = mPosY;
//	}
//}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}

SDL_Rect GameObject::getRect()
{
	return destRect;
}
void GameObject::setCollidingRects(std::vector<SDL_Rect> vector)
{
	this->collidingRects = vector;
}

bool GameObject::collideEnemy(SDL_Rect player)
{
	//std::cout << collidingRects.size() << std::endl;;
	for (const auto &i : collidingRects)
	{

		if (checkCollision(player, i))
		{
			std::cout << "ipos " << i.x << ":x  y:" << i.y << std::endl;
			colisionX = i.x;
			colisionY = i.y;
			//std::cout << " collidegameobj " << std::endl;
			return true;
		}

	}
	return false;
}

int GameObject::getCollisionX() {
	return colisionX;

}

int GameObject::getCollisionY() {
	return colisionY;
}

void GameObject::addScore() {
	score++;
}