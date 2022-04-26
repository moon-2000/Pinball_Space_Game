#include "Ball.h"

Ball::Ball(Vector2D Center, Vector2D Velocity, float Radius) {
    radius = Radius;
    center = Center;
    velocity = Velocity;
    score = 0;
    Xposition = 20;
    Yposition = 20;
}

float Ball::getRadius() const
{
    return radius;
}

Vector2D Ball::getCenter() const
{
    return center;
}

Vector2D Ball::getVelocity() const
{
    return velocity;
}

void Ball::move(Vector2D acceleration, float time)
{
    // Kinematic equations for planar motion of a particle
    velocity += acceleration * time;
    center += velocity * time - acceleration * time * time * 0.5;
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius);
}
void Ball::setVelocity(float x, float y) {
    velocity = { x,y };
}
void Ball::drawscore(Interface& interface)
{
    interface.drawgscore(score, Xposition, Yposition);
}

void Ball::drawFinalscore(Interface& interface)
{
    interface.drawfinalscore(70, 0);
}
void Ball::setcenter(float x, float y) {
    center = { x,y };
}
