#pragma once
#include "Obstacle.h"
class VIBRANIUM_BUMPER : public Obstacle
{
private:
    Vector2D PositionPum;
    float Radius;
    bool collidedLastFrame;
public:
    explicit VIBRANIUM_BUMPER(Vector2D Pum, float radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};
