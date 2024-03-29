#include "THRUST_BUMPER.h"
#include <cmath>
THRUST_BUMPER::THRUST_BUMPER (Vector2D Pum, float radius, float Speedmultiplier) {
    PositionPum = Pum;
    Radius = radius;
    speedmultiplier = Speedmultiplier;
    collidedLastFrame = false;
}
void THRUST_BUMPER::draw(Interface& interface) {
	interface.drawTHRUST_BUMPER(PositionPum, Radius);
};
Vector2D THRUST_BUMPER::collideWith(Ball& ball, float collisionTime)
{
    float theta = abs(atan(-(ball.getCenter().y - PositionPum.y) / (ball.getCenter().x - PositionPum.x)));
    float theta2 = atan(ball.getVelocity().y / ball.getVelocity().x) - theta;
    float magnitude = sqrt((ball.getVelocity().y) * (ball.getVelocity().y) + (ball.getVelocity().x) * (ball.getVelocity().x));
    Vector2D u = { ball.getCenter().x - PositionPum.x  ,  ball.getCenter().y - PositionPum.y };
    float magnitude_u = sqrt((u.x) * (u.x) + (u.y) * (u.y));
    Vector2D u_star = u / magnitude_u;
    float cosin = cos(theta - theta2);
    float sine = sin(theta - theta2);

    if (!collidedLastFrame && sqrt((PositionPum.x - ball.getCenter().x) * (PositionPum.x - ball.getCenter().x) + (PositionPum.y - ball.getCenter().y) * (PositionPum.y - ball.getCenter().y)) <= (ball.getRadius() + Radius)) {

        collidedLastFrame = true;
        //  return Vector2D{ magnitude * cosin - ball.getVelocity().x , magnitude * sine - ball.getVelocity().y } / collisionTime;
        ball.score += 5;
        return Vector2D{ magnitude * u_star.x - ball.getVelocity().x , magnitude * u_star.y - ball.getVelocity().y } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
};