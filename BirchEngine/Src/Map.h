#pragma once
#include "Game.h"
#include <vector>

class Map
{
public:

	Map();
	~Map();

	void LoadMap(double arr[20][25]);
	void DrawMap();
	//int getType(int row, int col);
	double getType(int col, int row);
	SDL_Rect getBox();
	//void Tile(int x, int y, int tileType);
	SDL_Rect mBox;
	int mType;


	std::vector<SDL_Rect> getColliders();

private:
	SDL_Rect src, dest;
	std::vector<SDL_Rect> colliders;
	//std::vector<Tile> collidingTiles;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* meta;
	SDL_Rect collider;
	//Tile collidingTile;
	//Tile* tile;
	double map[20][25];

};