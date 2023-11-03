#pragma once
#include "Obstacle.h"
class THRUST_BUMPER : public Obstacle
{
private:
    float speedmultiplier;
    Vector2D PositionPum;
    float Radius;
    bool collidedLastFrame;
public:
    explicit THRUST_BUMPER(Vector2D Pum, float radius, float Speedmultiplier);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};

