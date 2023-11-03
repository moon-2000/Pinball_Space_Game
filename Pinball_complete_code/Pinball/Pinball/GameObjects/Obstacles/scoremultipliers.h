#pragma once
#include "Obstacle.h"
class scoremultipliers : public Obstacle
{
private:
    Vector2D ScoreMultPosition;
    float radius;
    bool CollidedLastframe;

public:
    explicit scoremultipliers(Vector2D Bull, float Radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
};








