#pragma once
#include <iostream>
#include <vector>

#include "Engine.h"

using namespace std;


#define GAMESIZE_X 1270
#define GAMESIZE_Y 720

#define X_SPACEENEMIES 100

class Entity
{
	int id;

public:
	Entity(int id)
	{
		this->id = id;
	}
};

extern int aiEntitiesCount;

extern vector<Vector2> positions;
extern vector<Vector2> velocities;
extern vector<Vector2> sizes;

extern vector<Vector2> projectilePositions;
extern vector<Vector2> projectileVelocities;
extern vector<Vector2> projectileSizes;

extern vector<Vector3> rgb;

void CreatePlayer();
void CreateEnemies(int amount);

void InstantiatePoolOfProjectiles(int poolAmount);
void ShootProjectile(Vector2 shootPos, bool directionUp);

void EnemyShoot();
void PlayerShoot();

void DrawEntities();
