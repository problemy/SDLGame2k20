#include "Collision.h"
#include "Map.h"
#include "GameObject.h"

bool Collision::checkCollision(SDL_Rect A, SDL_Rect B)
{


	if (
		A.x + A.w > B.x + 2 &&
		B.x + B.w > A.x + 2 &&
		A.y + A.h > B.y + 2 &&
		B.y + B.h > A.y + 2
		)
	{
		return true;
	}

	return false;
}

void Collision::getType() {}


