#include "Lanes.h"

Lanes::Lanes(Vector2D FirstLineStart, Vector2D FirstLineEnd, Vector2D SecondLineStart, Vector2D SecondLineEnd) {
    line1start = FirstLineStart;
    line1end = FirstLineEnd;
    line2start= SecondLineStart;
    line2end = SecondLineEnd;
    collidedLastFrame = false;
}
void Lanes::draw(Interface& interface)
{
    interface.drawlanes (line1start, line1end, line2start, line2end);
}
Vector2D Lanes::collideWith(Ball& ball, float collisionTime)
{
    //something needed
    return Vector2D{ 0, 0 };
};