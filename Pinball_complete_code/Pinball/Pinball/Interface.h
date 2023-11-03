#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Defs.h"

// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
    float GameWidth, GameHight;
    sf::RenderWindow window;  // Represents the game window
    const sf::Color  // Colors used for drawing (can change the whole theme of the game)
        backgroundColor = sf::Color(800, 0, 800),
        outlineColor = sf::Color::Black,
        ballFillColor = sf::Color::White,
        flipperFillColor = sf::Color::White;
    const float outlineThickness = -2.0f;  // Negative sign means inwards

public:
    Interface(float gWidth, float gHight);  // Constructor
    void getControls(bool & exit, bool & left, bool & right);  // Detects the buttons pressed
    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, float radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);  // Draws a flipper
    void drawWall(float position);  // Draws a vertical wall
   // void drawPumbers(Vector2D Pum, float radius); //Draws the  pumbers
    void drawKickers(Vector2D P1,Vector2D P2,Vector2D P3); //Draws the  kickers
    void drawCeiling( float position);
    void drawCollectables(float x, float y , sf::Color c , char Char);
    void drawBoosters(Vector2D PositionBooster, float Radius);
    void drawgscore(int initialscore, int x, int y);
    void drawgameover(int x, int y);
    void drawTHRUST_BUMPER(Vector2D Pum, float radius);
    void drawPOP_BUMPER(Vector2D Pum, float radius);
    void drawVIBRANIUM_BUMPER(Vector2D Pum, float radius);
    void drawfinalscore(int x, int y);
    void drawline(Vector2D p1 , Vector2D p2);
    void drawBullseyes(Vector2D PositBullseyes, float Radius);
    void drawScoreMultipliers(Vector2D ScoreMultPosition, float Radius);
    void drawlanes(Vector2D line1start, Vector2D line1end, Vector2D line2start, Vector2D line2end);
};
