#include "score.h"
#include "Obstacle.h"

score::score(int scr , int X, int Y) {
	Xposition = X;
	Yposition = Y;
	Score = scr;
}
void score::draw(Interface& interface) {
	interface.drawgscore(Score , Xposition, Yposition);
}
void score::increasescore(int value) {
	Score = Score + value;
}
Vector2D score::collideWith(Ball& ball, float collisionTime)
{
	// something nedded
	return Vector2D{ 0, 0 };
}