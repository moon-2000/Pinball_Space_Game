#pragma once
#include "Obstacle.h"

class Bullseyes : public Obstacle
{
private:
    Vector2D PositionBullseyes;
    float radius;
    bool CollidedLastframe;

public:
    explicit Bullseyes(Vector2D Bull, float Radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override; 
};

