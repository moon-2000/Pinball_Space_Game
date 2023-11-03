#pragma once
#include "Obstacle.h"
class gameover : public Obstacle
{
private:
	bool CollidedLastframe;
	int Xposition, Yposition;
public:
	gameover(int X, int Y);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	void drawfinalscore(Interface& interface);
};
