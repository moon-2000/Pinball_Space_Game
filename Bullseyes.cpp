#include "Bullseyes.h"
Bullseyes::Bullseyes(Vector2D Bull, float Radius) {
    PositionBullseyes = Bull;
    radius = Radius;
    CollidedLastframe = false;
}
void Bullseyes::draw(Interface& interface) {
    interface.drawBullseyes(PositionBullseyes, radius);
}
Vector2D Bullseyes::collideWith(Ball& ball, float collisionTime)
{
  /*  Vector2D center = { PositionBullseyes.x + 50  , PositionBullseyes.y + 30 };
    float distance = sqrt((center.x * ball.getCenter().x) * (center.x * ball.getCenter().x) + (center.x * ball.getCenter().y) * (center.x * ball.getCenter().y));
    if (!CollidedLastframe && ball.getCenter().x >= PositionBullseyes.x && ball.getCenter().x <= PositionBullseyes.x + 100 && ball.getCenter().y >= PositionBullseyes.y && ball.getCenter().y <= PositionBullseyes.y + 60) 
        {
            CollidedLastframe = true;
            ball.score += 5;
            return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y *-2 } / collisionTime;
            if (distance <= 30 + ball.getRadius()) {
                ball.score += 5;
            }
            if (distance >= 30 + ball.getRadius() && distance <= 35 + ball.getRadius()) {
                ball.score += 10;
            }
            if (distance >= 35 + ball.getRadius() && distance <= 40 + ball.getRadius()) {
                ball.score += 20;
            }
            if (distance >= 40 + ball.getRadius() && distance <= 45 + ball.getRadius()) {
                ball.score += 40;
            }
            if (distance >= 45 + ball.getRadius() && distance <= 50 + ball.getRadius()) {
                ball.score += 80;
            }
        }
    else {
        return Vector2D{ 0, 0 };
    }*/
    float theta = abs(atan(-(ball.getCenter().y - PositionBullseyes.y) / (ball.getCenter().x - PositionBullseyes.x)));
    float theta2 = atan(ball.getVelocity().y / ball.getVelocity().x) - theta;
    float magnitude = sqrt((ball.getVelocity().y) * (ball.getVelocity().y) + (ball.getVelocity().x) * (ball.getVelocity().x));
    Vector2D u = { ball.getCenter().x - PositionBullseyes.x  ,  ball.getCenter().y - PositionBullseyes.y };
    float magnitude_u = sqrt((u.x) * (u.x) + (u.y) * (u.y));
    Vector2D u_star = u / magnitude_u;
    float cosin = cos(theta - theta2);
    float sine = sin(theta - theta2);

    if (!CollidedLastframe && sqrt((PositionBullseyes.x - ball.getCenter().x) * (PositionBullseyes.x - ball.getCenter().x) + (PositionBullseyes.y - ball.getCenter().y) * (PositionBullseyes.y - ball.getCenter().y)) <= (ball.getRadius() + radius)) {

        CollidedLastframe = true;
        ball.score += 20;
        //  return Vector2D{ magnitude * cosin - ball.getVelocity().x , magnitude * sine - ball.getVelocity().y } / collisionTime;
        return Vector2D{0.2f*( magnitude * u_star.x - ball.getVelocity().x ),0.2f*( magnitude * u_star.y - ball.getVelocity().y) } / collisionTime;
    }
    else
    {
        CollidedLastframe = false;
        return Vector2D{ 0, 0 };
    }
};
