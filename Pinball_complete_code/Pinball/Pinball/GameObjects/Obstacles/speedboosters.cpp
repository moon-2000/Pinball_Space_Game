#include "speedboosters.h"
speedboosters::speedboosters(Vector2D Pum, float radius) {
    Positionspd = Pum;
    Radius = radius;
    collidedLastFrame = false;
}
void speedboosters::draw(Interface& interface) {
    interface.drawspeedboosters(Positionspd, Radius);
};

Vector2D speedboosters::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && sqrt((Positionspd.x - ball.getCenter().x) * (Positionspd.x - ball.getCenter().x) + (Positionspd.y - ball.getCenter().y) * (Positionspd.y - ball.getCenter().y)) < (ball.getRadius() + Radius))
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * 2, ball.getVelocity().y * 2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
};