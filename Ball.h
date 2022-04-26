#pragma once

#include "Drawable.h"
// Represents the ball (the single most important object in a Pinball game!)
class Ball: public Drawable
{
public:
    float radius;  // Radius of the ball
    Vector2D center;  // The instantaneous center of the ball
    Vector2D velocity;  // The instantaneous velocity of the ball
    float score;
    float Xposition, Yposition;
    explicit Ball(Vector2D Center , Vector2D Velocity, float Radius);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    Vector2D getVelocity() const;
    void setVelocity(float x , float y);
    void setcenter(float x, float y);

    void move (Vector2D acceleration, float time);  // Simulates the ball's motion under uniform acceleration for a period of time
    void draw (Interface & interface) override;
    void drawscore(Interface& interface);
    void drawFinalscore(Interface& interface);
};
