#pragma once

class MovementHandler
{
public:
	void UpdatePlayer();
	void UpdateEnemies(int xVelocity);
	void UpdateProjectiles();
};
