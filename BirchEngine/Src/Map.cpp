#include "Map.h"
#include "TextureManager.h"
int counter;

double lvl1[20][25] = {
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,2,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0 },
{ 0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,2,2,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,1,2,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,1,2,2,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 }
};
Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");
	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = dest.w =32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}




void Map::LoadMap(double arr[20][25])
{
	for(int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}


}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{

			if (counter == 0 && type <2)
			{

				collider.x = dest.x;
				collider.y = dest.y;
				collider.h = collider.w = 32;
				colliders.push_back(collider);
				//collidingTiles.push_back(Tile::Tile(collider, type));
				//std::cout << "collider made at :" << collider.x << "  y: " << collider.y << std::endl;
			}
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0: TextureManager::Draw(grass, src, dest);
				break;
			case 1:TextureManager::Draw(water, src, dest);

				break;

			case 2:TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}
	}
	counter = 1;

}
std::vector<SDL_Rect> Map::getColliders()
{
	return this->colliders;

}



double Map::getType(int row, int col){
	return lvl1[col][row];

}
