#include "Kickers.h"
#include <cmath>
Kickers::Kickers(Vector2D p1, Vector2D p2 , Vector2D p3) {
	P1 = p1;
	P2 = p2;
	P3 = p3;
	CollidedLastframe = false;
}
void Kickers::draw(Interface& interface) {
	interface.drawKickers(P1, P2 , P3);
};
Vector2D Kickers::collideWith(Ball& ball, float collisionTime)
{
    int slope1 = abs( (P1.y - P2.y) / (P1.x - P2.x));
    theta1 = -atan(slope1) ;
    float theta2 = atan(ball.getVelocity().y / ball.getVelocity().x) - theta1;
    float magnitude = sqrt((ball.getVelocity().y) * (ball.getVelocity().y) + (ball.getVelocity().x) * (ball.getVelocity().x));
    float cosin = cos(theta1 - theta2);
    float sine = sin(theta1 - theta2);

    if (!CollidedLastframe && (ball.getCenter().x - P1.x) * ((P1.y - P2.y) / (P1.x - P2.x)) <= (ball.getCenter().y - P1.y) && (ball.getCenter().x - P1.x) * ((P1.y - P2.y) / (P1.x - P2.x)) + 35     >= (ball.getCenter().y - P1.y) && ball.getCenter().x > P1.x && ball.getCenter().x < P2.x)
         {
             CollidedLastframe = true;
             ball.score += 5;
             return Vector2D{ magnitude * cosin - ball.getVelocity().x , magnitude * sine - ball.getVelocity().y } / collisionTime;

            }

    else
    {
        CollidedLastframe = false;
        return Vector2D{ 0, 0 };
    }
}



