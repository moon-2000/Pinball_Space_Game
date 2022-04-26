#include "Gates.h"

Gates::Gates(Vector2D FirstLineStart, Vector2D FirstLineEnd ) {
    line1 = FirstLineStart;
    line2 = FirstLineEnd;
    collidedLastFrame = false;
}
void Gates::draw(Interface& interface)
{
    interface.drawlanes (line1, line2);
}
Vector2D Gates::collideWith(Ball& ball, float collisionTime)
{


    if (!collidedLastFrame && ball.getCenter().x <= line1.x && ball.getCenter().x >= line1.x  - 20 && ball.getCenter().y > line1.y && ball.getCenter().y < line1.y+100)   {
        collidedLastFrame = true;
        ball.setcenter(line2.x, line2.y + 50 );
        return Vector2D{ 0 , 0 } / collisionTime;


    }
   
    else    if (!collidedLastFrame && ball.getCenter().x >= line2.x && ball.getCenter().x <= line2.x  + 20 && ball.getCenter().y > line1.y && ball.getCenter().y < line1.y + 100) {
        collidedLastFrame = true;
        ball.setcenter(line1.x, line1.y + 50);
        return Vector2D{ 0 , 0 } / collisionTime;


    }

    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
};