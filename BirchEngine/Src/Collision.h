#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Coin.h"
#include "Map.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
class Collision
{

public:
	Collision();
	~Collision();
	bool checkCollision(SDL_Rect a, SDL_Rect b);
	//static bool checkCollision(SDL_Rect A, SDL_Rect B);
	//static bool checkCoinCollision(SDL_Rect* coin, SDL_Rect* player);
	//static bool checkingCollision(SDL_Rect a, SDL_Rect b);
	void getType();
private:

	
	Map* map;

};