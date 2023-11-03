#include "scoremultipliers.h"
scoremultipliers::scoremultipliers(Vector2D Pum, float Radius) {
	ScoreMultPosition = Pum;
	radius = Radius;
}
void scoremultipliers::draw(Interface& interface) {
	interface.drawScoreMultipliers(ScoreMultPosition, radius);
}
Vector2D scoremultipliers::collideWith(Ball& ball, float collisionTime)
{
	//something needed
	return Vector2D{ 0, 0 };
};