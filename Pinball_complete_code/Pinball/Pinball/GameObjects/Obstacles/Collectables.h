#pragma once
#include "Obstacle.h"
class Collectables: public Obstacle
{
private:
	bool CollidedLastframe;
	int Xposition, Yposition, Xposition1,  Xposition2,  Xposition3, Xposition4,  Xposition5 ;
	int C = 0;
	int i = 0;
	int e = 0;
	int _2 = 0;
	int _0 = 0;
	int _2_ = 0;
	sf::Color c, c1, c2, c3, c4, c5;
public:
	Collectables(float X, float Y);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};

