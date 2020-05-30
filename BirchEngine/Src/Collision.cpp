#include "Collision.h"
#include "Map.h"
#include <stdio.h>
#include "GameObject.h"
#include "Coin.h"

bool Collision::checkCollision(SDL_Rect A, SDL_Rect B)
{
	// Nie sprawdzamy dok³adnie kolizji (a przy okazji wywo³ujemy lekki efekt drgania, przy poruszaniu siê przy krawêdziach

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

void Collision::getType()
{
	
}

/*bool Collision::checkCoinCollision(SDL_Rect*coin, SDL_Rect player)
{

	// Wersja kolizji z u³atwieniem dla gracza (nie wymaga a¿ takiej precyzji w pozycjonowaniu
	if (
		coin.x + coin.w > player.x + 8 &&
		player.x + player.w > coin.x + 8 &&
		coin.y + coin.h > player.y + 8 &&
		player.y + player.h > coin.y + 8
		)
	{
		return true;
		
	}

	return false;
}
*/

bool checkingCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}




