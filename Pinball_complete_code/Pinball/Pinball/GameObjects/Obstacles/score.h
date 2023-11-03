#pragma once
#include "Obstacle.h"
class score : public Obstacle
{
private:
	bool CollidedLastframe;
	int Xposition, Yposition;
	int Score;
public:
	score(int scr , int X, int Y);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	void increasescore(int value);
};
