#include "speedBooster.h"
speedBooster::speedBooster(Vector2D boosterPosition, float Radius) {
	PositionBooster = boosterPosition;
	radius = Radius;
	CollidedLastframe = false;
}
void speedBooster::draw(Interface& interface) {
	interface.drawBoosters(PositionBooster, radius);
}
Vector2D speedBooster::collideWith(Ball& ball, float collisionTime)
{
        if (!CollidedLastframe && sqrt((PositionBooster.x - ball.getCenter().x) * (PositionBooster.x - ball.getCenter().x) + (PositionBooster.y - ball.getCenter().y) * (PositionBooster.y - ball.getCenter().y)) < (ball.getRadius() + radius))
        {
            CollidedLastframe = true;

            return Vector2D{ ball.getVelocity().x * 0.3f, ball.getVelocity().y * 0.3f } / collisionTime;
        }
        else
        {
            CollidedLastframe = false;
            return Vector2D{ 0, 0 };
        }
    };
