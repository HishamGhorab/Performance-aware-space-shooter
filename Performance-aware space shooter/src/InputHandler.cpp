#include "Engine.h"
#include "Game.h"
#include "InputHandler.h"

void MovementHandler::UpdatePlayer()
{
	int playerId = 0;

	//Movement
	if (GetKey(SDL_SCANCODE_D))
		velocities[playerId].x = 500;
	if (GetKey(SDL_SCANCODE_A))
		velocities[playerId].x = -500;

	if (GetKeyReleased(SDL_SCANCODE_D) || GetKeyReleased(SDL_SCANCODE_A))
		velocities[playerId].x = 0;

	Step(playerId, velocities[playerId].x * deltaTime);
}

void MovementHandler::UpdateEnemies(int xVelocity)
{
	for (int i = 1; i < aiEntitiesCount; i++)
	{
		int id = i;

		velocities[id].x = xVelocity;
		Step(id, velocities[id].x * deltaTime);
	}
}

void MovementHandler::UpdateProjectiles()
{
	for (int i = 1; i < projectilePositions.size(); i++)
	{
		int id = i;
		Step(id, projectileVelocities[id].y * deltaTime);
	}
}
