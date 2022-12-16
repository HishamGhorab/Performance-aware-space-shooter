#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

extern struct Vector2
{
	Vector2(int x, int y)
	{this->x = x; this->y = y;}

	int x;
	int y;
};

extern struct Vector3
{
	Vector3(int x, int y, int z)
	{this->x = x; this->y = y; this->z = z;}

	int x;
	int y;
	int z;
};

struct Key_State
{
	bool state = false;
	int change_frame = 0;
};

//we are now creating an array with the size of all possible scancodes
extern Key_State keys[SDL_NUM_SCANCODES];

bool GetKey(SDL_Scancode key);
bool GetKeyPressed(SDL_Scancode key);
bool GetKeyReleased(SDL_Scancode key);

extern bool Step(int id, float dx);
extern bool Sweep(int id, float dx);

extern float deltaTime;
extern int frameNumber;