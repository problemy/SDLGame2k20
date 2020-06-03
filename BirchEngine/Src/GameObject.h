#pragma once
#include "Game.h"	
#include"Collision.h"
#include"Coin.h"
#include <vector>

class GameObject {
	public:
		int frameWidth, frameHeight;
		int textureWidth, textureHeight;

		GameObject(const char* texturesheet,int x, int y);
		~GameObject();
		void Move();
		void Update();
		void Render();
		SDL_Rect getRect();
		void setCollidingRects(std::vector<SDL_Rect> vector);
		int getCollisionX();
		int getCollisionY();

		bool collideEnemy(SDL_Rect player);
		void addScore();
		int getScore();
		void updateStatus(int i);
		void updateCoinStatus(int i);

	private:

		int score = 0;
		std::vector <SDL_Rect> collidingRects;

		double xpos;
		double ypos;
		double xBeforeMove = xpos;
		double yBeforeMove = ypos;
		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		double velocity = 1.0;
		bool animated = false;
		int frames = 0;
		int speed = 100;
		SDL_Rect collider;

		int colisionX = 0;
		int colisionY = 32;

};