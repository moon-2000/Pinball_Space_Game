#include "ceiling.h"

#include <cmath>
using namespace std;

ceiling::ceiling(float position): position(position), collidedLastFrame(false) {}

void ceiling::draw(Interface & interface)
{
    interface.drawCeiling(position);
}

Vector2D ceiling::collideWith(Ball & ball, float collisionTime)
{

    if(!collidedLastFrame && abs(position - ball.getCenter().y) <= ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D { 0, ball.getVelocity().y *-2} / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D {0, 0};
    }
}
