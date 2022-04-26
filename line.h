#pragma once

#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class line : public Obstacle
{
public:
    Vector2D P1;
    Vector2D P2;
    bool collidedLastFrame;
    explicit line(Vector2D p1, Vector2D p2);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};

