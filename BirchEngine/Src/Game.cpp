#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Coin.h"
#include "Collision.h"

GameObject* player;
Coin* coin;
Coin* coin1;
Coin* coin2;
Coin* coin3;
Coin* coin4;
Coin* coin5;
Coin* coin6;
//Collision* colision;
//GameObject* enemy;
Map* map;


SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
//bool checkingCollision(SDL_Rect coin, SDL_Rect player);
bool checkCollision(SDL_Rect player, SDL_Rect coin);
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	player = new GameObject("assets/player.png", 0, 40);
	coin = new Coin("assets/flippingcoin.png", 230, 200,4,4);
	coin1 = new Coin("assets/flippingcoin.png", 198, 200, 4, 4);
	coin2 = new Coin("assets/flippingcoin.png", 616, 550, 4, 4);
	coin3 = new Coin("assets/flippingcoin.png", 102, 200, 4, 4);
	coin4 = new Coin("assets/flippingcoin.png", 102, 134, 4, 4);
	coin5 = new Coin("assets/flippingcoin.png", 230, 134, 4, 4);
	coin6 = new Coin("assets/flippingcoin.png", 583, 550, 4, 4);
	//enemy = new GameObject("assets/enemy.png", 50, 50);
	map = new Map();
	//colision = new Collision();
}

void Game::handleEvents()
{

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default: 
		break;
	}
}

void Game::update()
{

	//std::cout << "typ na mapie: " <<  << std::endl;
	//std::cout << "kolizyjne wspulrzendne" << player->getCollisionX() / 32 << " y: " << player->getCollisionY() / 32 << std::endl;

	// jeżeli gracz koliduje z typem kratki mapy == 1 nie wykona sie aktualizacja gracza == game over
	if (map->getType(player->getCollisionX() / 32, (player->getCollisionY() / 32)) !=1) {
		player->Update();
	}
	
	coin->Update();
	//bool Collision::checkCollision(SDL_Rect coin, SDL_Rect player);
//	std::cout << "czy dziala funkcja check colision " << colision->checkCoinCollision(player->getRect(), &coin->getRect()) << std::endl;
	coin1->Update();
	coin2->Update();
	coin3->Update();
	coin4->Update();
	coin5->Update();
	coin6->Update();

	player->setCollidingRects(map->getColliders());

}

void Game::render()
{

	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	coin->Render();
	coin1->Render();
	coin2->Render();
	coin3->Render();
	coin4->Render();
	coin5->Render();
	coin6->Render();
//	enemy->Render();
	SDL_RenderPresent(renderer);


}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}