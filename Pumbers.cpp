#include "Pumbers.h"
Pumbers::Pumbers( Vector2D Pum, float radius) {
	PositionPum = Pum;
	Radius = radius;
    collidedLastFrame = false;
}
void Pumbers::draw(Interface& interface) {
	interface.drawPumbers(PositionPum , Radius);
};

Vector2D Pumbers::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && sqrt((PositionPum.x - ball.getCenter().x)*(PositionPum.x - ball.getCenter().x)+(PositionPum.y - ball.getCenter().y)*(PositionPum.y - ball.getCenter().y)) <( ball.getRadius()+ Radius))
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2, 0 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
};

