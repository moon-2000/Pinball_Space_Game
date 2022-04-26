#pragma once
#include "Obstacle.h"
class speedBooster : public Obstacle
 {
private:
    Vector2D PositionBooster;
    float radius;
    bool CollidedLastframe;

public:
    explicit speedBooster(Vector2D Pum, float Radius);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
 };

