 #pragma once
#include "Obstacle.h"
class Pumbers: public Obstacle
{
public:
    Vector2D PositionPum;
    float Radius;
    bool collidedLastFrame;    
    explicit Pumbers (Vector2D Pum, float radius);
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};

