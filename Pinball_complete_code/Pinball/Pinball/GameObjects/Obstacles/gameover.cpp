#include "gameover.h"
#include "Obstacle.h"

gameover::gameover(int X, int Y) {
	Xposition = X;
	Yposition = Y;
}
void gameover::draw(Interface& interface) {
	interface.drawgameover(Xposition, Yposition);
}
void gameover::drawfinalscore(Interface& interface) {
	interface.drawfinalscore(Xposition, Yposition);
}
Vector2D gameover::collideWith(Ball& ball, float collisionTime)
{
	// something nedded
	return Vector2D{ 0, 0 };
}