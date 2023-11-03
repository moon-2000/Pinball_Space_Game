#pragma once
#include "Obstacle.h"
class POP_BUMPER : public Obstacle
{
private:
    Vector2D PositionPum;
    float Radius;

public:
    bool collidedLastFrame;
    explicit POP_BUMPER(Vector2D Pum, float radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};
