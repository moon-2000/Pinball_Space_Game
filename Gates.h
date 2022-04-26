#pragma once
#include <cmath>
using namespace std;
#include "Obstacle.h"
class Gates : public Obstacle
{
private:
    Vector2D line1;
    Vector2D line2;
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit Gates(Vector2D FirstLineStart, Vector2D FirstLineEnd);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};

