#pragma once

#include "Drawable.h"
#include "Collidable.h"
// Represents a (controllable) flipper
class Flipper: public Drawable, Collidable
{
private:
    FlipperType type;  // Left or right flipper
    float length;  // Flipper length
    float angle;  // Angle of rotation
    float majorRadius;  // The radius of the rotation end
    float minorRadius;  // The radius of the other end

public:
    Vector2D center;
    // The angle should probably be removed from the constructor after adding the controls
    Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);

    Vector2D collideWith(Ball & ball, float collisionTime) override;
    void draw(Interface& interface) override;
    void setangle(float ANGLE);
};
