#include "Collectables.h"
#include "Obstacle.h"

Collectables::Collectables(float X, float Y) {
	Xposition = X;
	Yposition = Y;
	Xposition1 = X + 100;
	Xposition2 = X + 200;
	Xposition3 = X + 300;
	Xposition4 = X + 400;
	Xposition5 = X + 500;
}
Vector2D Collectables::collideWith(Ball& ball, float collisionTime)
{
	if (ball.getCenter().x > Xposition && ball.getCenter().x < Xposition + 45 && C == 0 && ball.getCenter().y > Yposition + 15 && ball.getCenter().y < Yposition + 75) {
		ball.score += 100;
		C++;
		return Vector2D{ 0, 0 };
	}
	if (ball.getCenter().x > Xposition1+10 && ball.getCenter().x < Xposition1 + 45-10 && i == 0 && ball.getCenter().y > Yposition+15 && ball.getCenter().y < Yposition +75) {
		ball.score += 100;
		i++;
		return Vector2D{ 0, 0 };
	}
	if (ball.getCenter().x > Xposition2 && ball.getCenter().x < Xposition2 + 45 && e == 0 && ball.getCenter().y > Yposition + 15 && ball.getCenter().y < Yposition +75) {
		ball.score += 100;
		e++;
		return Vector2D{ 0, 0 };
	}
	if (ball.getCenter().x > Xposition3 && ball.getCenter().x < Xposition3 + 45 && _2 == 0 && ball.getCenter().y > Yposition + 15 && ball.getCenter().y < Yposition +75) {
		ball.score += 100;
		_2++;
		return Vector2D{ 0, 0 };
	}
	if (ball.getCenter().x > Xposition4 && ball.getCenter().x < Xposition4 + 45 && _0 == 0 && ball.getCenter().y > Yposition + 15 && ball.getCenter().y < Yposition +75) {
		ball.score += 100;
		_0++;
		return Vector2D{ 0, 0 };
	}
	if (ball.getCenter().x > Xposition5 && ball.getCenter().x < Xposition5 + 45 && _2_ == 0 && ball.getCenter().y > Yposition + 15 && ball.getCenter().y < Yposition +75) {
		ball.score += 100;
		_2_++;
		return Vector2D{ 0, 0 };
	} 
	if (C ==1 && i ==1 && e ==1 && _2 == 1 && _0 ==1 && _2_ ==1 ) {
		ball.score += 1000;
		C++;
		i++;
		e++;
		_2++;
		_2_++;
		_0++;
		return Vector2D{ 0, 0 };
	}
	else {
		return Vector2D{ 0, 0 };
	}
}
void Collectables::draw(Interface& interface) {
	if (C== 0) {
		interface.drawCollectables(Xposition, Yposition , sf::Color::White , 'C');
	}
	if (C ==1)
	{
		interface.drawCollectables(Xposition, Yposition, sf::Color::Yellow, 'C');
	}
	if (C == 2) {
		interface.drawCollectables(Xposition, Yposition, sf::Color::Green, 'C');
	}
	if (i == 0) {
		interface.drawCollectables(Xposition1, Yposition, sf::Color::White, 'I');
	}
	if(i == 1)
	{
		interface.drawCollectables(Xposition1, Yposition, sf::Color::Yellow, 'I');
	}
	if (i == 2) {
		interface.drawCollectables(Xposition1, Yposition, sf::Color::Green, 'I');
	}
	if (e == 0) {
		interface.drawCollectables(Xposition2 , Yposition, sf::Color::White, 'E');
	}
    if (e == 1)
	{
		interface.drawCollectables(Xposition2, Yposition, sf::Color::Yellow, 'E');
	}
	if (e == 2) {
		interface.drawCollectables(Xposition2, Yposition, sf::Color::Green, 'E');
	}
	if (_2 == 0) {
		interface.drawCollectables(Xposition3 , Yposition, sf::Color::White, '2');
	}
    if (_2 == 1)
	{
		interface.drawCollectables(Xposition3, Yposition, sf::Color::Yellow, '2');
	}
	if (_2 == 2) {
		interface.drawCollectables(Xposition3, Yposition, sf::Color::Green, '2');
	}
	if (_0 == 0) {
		interface.drawCollectables(Xposition4 , Yposition, sf::Color::White, '0');
	}
	if (_0 == 1)
	{
		interface.drawCollectables(Xposition4, Yposition, sf::Color::Yellow, '0');
	}
	if (_0 == 2) {
		interface.drawCollectables(Xposition4, Yposition, sf::Color::Green, '0');
	}
	if (_2_ == 0) {
		interface.drawCollectables(Xposition5, Yposition, sf::Color::White, '2');
	}
	if (_2_ == 1)
	{
		interface.drawCollectables(Xposition5, Yposition, sf::Color::Yellow, '2');
	}
	if (_2_ == 2) {
		interface.drawCollectables(Xposition5, Yposition, sf::Color::Green, '2');
	}
}
