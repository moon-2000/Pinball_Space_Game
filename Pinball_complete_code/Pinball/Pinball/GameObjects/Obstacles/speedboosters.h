#pragma once
#include "Obstacle.h"
class speedboosters : public Obstacle
{
private:
    Vector2D Positionspd;
    float Radius;
    bool collidedLastFrame;
public:
    explicit speedboosters(Vector2D Pum, float radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};