#pragma once

#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class ceiling : public Obstacle
{
private:
    float position;  // The horizontal position of the wall
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit ceiling(float position);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};
