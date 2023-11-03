#pragma once
#include "Obstacle.h"
class Kickers : public Obstacle
{
public:
	Vector2D P1, P2, P3;
	bool CollidedLastframe;
	float theta1;
	explicit Kickers(Vector2D P1, Vector2D P2, Vector2D P3);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};