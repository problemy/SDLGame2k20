#pragma once
#include "Game.h"	
#include"Collision.h"
#include"Coin.h"
#include <vector>
class GameObject {
	public:
		//static const int player_vel = 10;
		GameObject(const char* texturesheet,int x, int y);
		~GameObject();
	
		void Move();
		void Update();
		void Render();
		//SDL_Rect getRect();
		
		void handleEvent(SDL_Event& e);
		void move(SDL_Rect& coin);
		void setCollidingRects(std::vector<SDL_Rect> vector);

		bool collideEnemy(SDL_Rect player);

	private:


		std::vector <SDL_Rect> collidingRects;
		int xpos;
		int ypos;

		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		double velocity = 1.0;
		bool animated = false;
		int frames = 0;
		int speed = 100;
		SDL_Rect collider;
		int mVelX, mVelY;
		int mPosX, mPosY;
		SDL_Rect mCollider;
};