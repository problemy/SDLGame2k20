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
			srcRect.x = 64;
			srcRect.y = 32;

		}
		if (kstate[SDL_SCANCODE_RIGHT]) {
			xpos = xpos + 1 * velocity;
			velocity += 0.01;
			srcRect.x = 64;
			srcRect.y = 64;
		}
		if (kstate[SDL_SCANCODE_UP]) {
			ypos = ypos - 1 * velocity;
			velocity += 0.01;
			srcRect.x = 64;
			srcRect.y = 96;
		}
		if (kstate[SDL_SCANCODE_DOWN]) {
			ypos = ypos + 1 * velocity;
			velocity += 0.01;
			srcRect.x = 64;
			srcRect.y = 0;
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

	if (player.x < 0 || player.x > 800-16) {
		return true;
	}
	if (player.y < 0 || player.y > 640 - 16) {
		return true;
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




void GameObject::updateStatus(int i) {
	destRect.x = 200;
	destRect.y = 280;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	switch (i) {
	case 0:
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 0;
		srcRect.h = 0;
		break;
	case 1:
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 400;
		srcRect.h = 86;
		break;
	case 2:
		srcRect.x = 0;
		srcRect.y = 91;
		srcRect.w = 400;
		srcRect.h = 44;
		break;
	case 3:
		srcRect.x = 0;
		srcRect.y = 158;
		srcRect.w = 400;
		srcRect.h = 22;
		break;
	default:
		break;
	}


}
void GameObject::updateCoinStatus(int i)
{
	//if (i > 0) {
		destRect.x = 520;
		destRect.y = 5;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
		srcRect.x = 0;
		srcRect.y = 28 * (i - 1);
		srcRect.w = 280;
		srcRect.h = 28;
	//}
}
;

int GameObject::getScore() {
	return score;
}