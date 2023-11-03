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
    //something needed
    return Vector2D{ 0, 0 };
};
