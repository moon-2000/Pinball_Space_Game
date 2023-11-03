#pragma once
#include <cmath>
using namespace std;
#include "Obstacle.h"
class Lanes: public Obstacle
{
private:
    Vector2D line1start;
    Vector2D line1end;
    Vector2D line2end;
    Vector2D line2start;
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit Lanes(Vector2D FirstLineStart, Vector2D FirstLineEnd,  Vector2D SecondLineStart, Vector2D SecondLineEnd);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};

