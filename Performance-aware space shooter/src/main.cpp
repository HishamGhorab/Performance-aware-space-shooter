#include <stdio.h>
#include <SDL/SDL.h>
#include "Engine.h"
#include "Game.h"
#include "InputHandler.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAMESIZE_X, GAMESIZE_Y, 0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool running = true;
	Uint64 previousTicks = SDL_GetPerformanceCounter();

	MovementHandler movementHanlder;

	CreatePlayer();
	CreateEnemies(10);
	InstantiatePoolOfProjectiles(30);

	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 deltaTicks = ticks - previousTicks;
		previousTicks = ticks;
		deltaTime = (float)deltaTicks / SDL_GetPerformanceFrequency();

		SDL_SetRenderDrawColor(render, 100, 87, 166, 255);
		SDL_RenderClear(render);
		
		frameNumber++;


		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
			{
				if (event.key.repeat)
					break;

				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode].state = true;
				keys[scancode].change_frame = frameNumber;

				break;
			}
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode].state = false;
				keys[scancode].change_frame = frameNumber;

				break;
			}
			}
		}

		movementHanlder.UpdatePlayer();

		int vel = 0;
		float num = sin(frameNumber * deltaTime);
		
		if (num > 0)
			vel = 50;

		if(num < 0)
			vel = -50;
		

		movementHanlder.UpdateEnemies(vel);

		if (GetKeyPressed(SDL_SCANCODE_V))
		{
			std::cout << "hi" << std::endl;
			PlayerShoot();
		}

		DrawEntities();

		SDL_Delay(16);
		SDL_RenderPresent(render);
	}
}