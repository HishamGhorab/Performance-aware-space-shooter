#include "engine.h"
#include "Game.h"

SDL_Window* window;
SDL_Renderer* render;

Key_State keys[SDL_NUM_SCANCODES];

bool GetKey(SDL_Scancode key)
{
	return keys[key].state;
}

bool GetKeyPressed(SDL_Scancode key)
{
	return keys[key].state && keys[key].change_frame == frameNumber;
}

bool GetKeyReleased(SDL_Scancode key)
{
	return !keys[key].state && keys[key].change_frame == frameNumber;
}

bool Step(int id, float dx)
{
	if (Sweep(id, dx))
		return false;

	positions[id].x += dx;
	return true;
}

bool Sweep(int id, float dx)
{
	if (positions[id].x + dx < 0 || positions[id].x + dx > GAMESIZE_X - sizes[id].x)
		return true;

	return false;
}

float deltaTime = 0.0f;
int frameNumber = 0.0f;