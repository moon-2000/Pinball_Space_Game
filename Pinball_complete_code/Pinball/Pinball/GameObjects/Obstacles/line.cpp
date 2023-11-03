#include "line.h"

#include <cmath>
using namespace std;

line::line(Vector2D p1, Vector2D p2) {
    P1 = p1;
    P2 = p2;
    collidedLastFrame = false;
}

void line::draw(Interface& interface)
{
    interface.drawline(P1 , P2);
}

Vector2D line::collideWith(Ball& ball, float collisionTime)
{
   
   int slope = abs((P1.y - P2.y) / (P1.x - P2.x));
    float theta = atan(slope);
    Vector2D vector = { 500 ,  - 700 };
   /* if(!collidedLastFrame && (ball.getCenter().x - P1.x) * ((P1.y - P2.y) / (P1.x - P2.x)) <= (ball.getCenter().y - P1.y)  + ball.getRadius() && ball.getCenter().x > P1.x && ball.getCenter().x < P2.x  && vector.x * ball.getVelocity().x + vector.y * ball.getVelocity().y < 0)
    {
        collidedLastFrame = true; 
       return Vector2D{(ball.getVelocity().x * sin(theta) - ball.getVelocity().y * cos(theta) - ball.getVelocity().x),( ball.getVelocity().x * cos (theta) - ball.getVelocity().y * sin(theta) - ball.getVelocity().y) } /(collisionTime); 

    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }*/
    if (!collidedLastFrame && (ball.getCenter().x - P1.x) * ((P1.y - P2.y) / (P1.x - P2.x)) <= (ball.getCenter().y - P1.y) + ball.getRadius() && ball.getCenter().x > P1.x && ball.getCenter().x < P2.x && P2.y > P1.y)
    {
        collidedLastFrame = true;
        ball.velocity.x = 0;
        ball.velocity.y = 0;
        return Vector2D{ 5000 , 0  };
    }
    else if (!collidedLastFrame && (ball.getCenter().x - P1.x) * ((P1.y - P2.y) / (P1.x - P2.x)) <= (ball.getCenter().y - P1.y) + ball.getRadius() && ball.getCenter().x > P1.x && ball.getCenter().x < P2.x && P2.y < P1.y)
    {
        collidedLastFrame = true;
        ball.velocity.x = 0;
        ball.velocity.y = 0;
        return Vector2D{ -4000 , 0 };
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }

}