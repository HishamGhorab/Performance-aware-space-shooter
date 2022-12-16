#include <SDL/SDL.h>
#include <iostream>
#include <vector>

#include "Game.h"
#include "Engine.h"

vector<Vector2> positions;
vector<Vector2> velocities;
vector<Vector2> sizes;

vector<Vector2> projectilePositions;
vector<Vector2> projectileVelocities;
vector<Vector2> projectileSizes;

vector<Vector3> rgb;

int aiEntitiesCount = 0;

void CreatePlayer()
{
	Entity player(0);
	aiEntitiesCount++;

	Vector2 position = Vector2(GAMESIZE_X/2 - 50, 600);
	Vector2 velocity = Vector2(0, 0);
	Vector3 color = Vector3(90, 70, 70);
	Vector2 size = Vector2(50, 30);

	positions.push_back(position);
	velocities.push_back(velocity);
	rgb.push_back(color);
	sizes.push_back(size);

}

void CreateEnemies(int amount)
{
	for (int i = 1; i < amount; i++)
	{
		Entity enemy(i);
		aiEntitiesCount++;

		Vector2 position = Vector2(GAMESIZE_X/2 - i * 60, 50);
		Vector2 velocity = Vector2(0,0);
		Vector3 color = Vector3(239, 118, 122);
		Vector2 size = Vector2(50, 30);

		positions.push_back(position);
		velocities.push_back(velocity);
		rgb.push_back(color);
		sizes.push_back(size);
	}
}

void InstantiatePoolOfProjectiles(int poolAmount)
{
	for (int i = 0; i < poolAmount; i++)
	{
		Vector2 position = Vector2(INT_MAX, INT_MAX);
		Vector2 velocity = Vector2(0, 0);
		Vector2 size = Vector2(10, 10);

		projectilePositions.push_back(position);
		projectileVelocities.push_back(velocity);
		projectileSizes.push_back(size);
	}
}


void ShootProjectile(Vector2 shootPos, bool directionUp)
{
	//get velocity direction
	int yVel = 500;
	if (directionUp)
		yVel = -500;

	//Get a free projectile from the pool
	for (int i = 0; i < projectilePositions.size(); i++)
	{
		Vector2 position = projectilePositions[i];
		if (position.x != INT_MAX)
			continue;

		position = shootPos;
		int velocity = projectileVelocities[i].y = yVel;
		return;
	}
}

void EnemyShoot()
{
}

void PlayerShoot()
{
	ShootProjectile(positions[0], true);
}

void DrawEntities()
{
	for (int i = 0; i < aiEntitiesCount; i++)
	{
		SDL_SetRenderDrawColor(render, rgb[i].x, rgb[i].y, rgb[i].z, 255);
		SDL_Rect rect = { (int)positions[i].x, (int)positions[i].y, sizes[i].x, sizes[i].y };
		SDL_RenderFillRect(render, &rect);
	}
}

