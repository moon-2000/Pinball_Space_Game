#include "Interface.h"
#include <sstream>
#include <string>
Interface::Interface(float gWidth, float gHight)
{
    GameWidth = gWidth;
    GameHight = gHight;
    sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GameWidth, GameHight), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall( float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(position, 0), ballFillColor),
            sf::Vertex(sf::Vector2f(position, GameWidth), ballFillColor)
            };
    window.draw(line, 2, sf::Lines);
}
void Interface::drawPOP_BUMPER(Vector2D Pum, float Radius)
{
    sf::CircleShape Pumber(Radius);
    Pumber.setOrigin(Radius, Radius);
    Pumber.setOutlineThickness(outlineThickness);
    Pumber.setOutlineColor(outlineColor);
    Pumber.setFillColor(ballFillColor);
    Pumber.setPosition(Pum.x, Pum.y);
    Pumber.setFillColor(sf::Color :: Yellow);
    window.draw(Pumber);
}
void Interface::drawVIBRANIUM_BUMPER(Vector2D Pum, float Radius)
{
    sf::CircleShape Pumber(Radius);
    Pumber.setOrigin(Radius, Radius);
    Pumber.setOutlineThickness(outlineThickness);
    Pumber.setOutlineColor(outlineColor);
    Pumber.setFillColor(ballFillColor);
    Pumber.setPosition(Pum.x, Pum.y);
    Pumber.setFillColor(sf::Color::Magenta);
    window.draw(Pumber);
}
void Interface::drawTHRUST_BUMPER(Vector2D Pum, float Radius)
{
    sf::CircleShape Pumber(Radius);
    Pumber.setOrigin(Radius, Radius);
    Pumber.setOutlineThickness(outlineThickness);
    Pumber.setOutlineColor(outlineColor);
    Pumber.setFillColor(ballFillColor);
    Pumber.setPosition(Pum.x, Pum.y);
    Pumber.setFillColor(sf::Color::Green);
    window.draw(Pumber);
}
void Interface::drawKickers(Vector2D P1, Vector2D P2, Vector2D P3) {
    sf::ConvexShape Kicker;

    // resize it to 3 points
    Kicker.setPointCount(3);

    // define the points
    Kicker.setPoint(0, sf::Vector2f(P1.x, P1.y));
    Kicker.setPoint(1, sf::Vector2f(P2.x, P2.y));
    Kicker.setPoint(2, sf::Vector2f(P3.x, P3.y));
    Kicker.setOutlineThickness(outlineThickness);
    Kicker.setOutlineColor(sf::Color::Black);
    Kicker.setFillColor(sf::Color::Cyan);
    window.draw(Kicker);
}

void Interface::drawCeiling(float position)
{

    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0 , position), ballFillColor),
            sf::Vertex(sf::Vector2f( GameWidth,position), ballFillColor)
    };
    window.draw(line, 2, sf::Lines);
}
void Interface::drawCollectables(float x, float y , sf::Color c , char Char) {
    sf::Text collectables;
    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");
    collectables.setFont(font);
    collectables.setString(Char);
    collectables.setCharacterSize(72);
    collectables.setFillColor(c);
    collectables.setStyle(sf::Text::Bold);
    collectables.setPosition(x, y);
    
    window.draw(collectables);
}
void Interface:: drawBoosters(Vector2D PositionBooster, float Radius) {
    sf::CircleShape SpeedBooster(Radius);
    SpeedBooster.setOrigin(Radius, Radius);
    SpeedBooster.setPosition(PositionBooster.x, PositionBooster.y);
    SpeedBooster.setFillColor(sf::Color::White);
    window.draw(SpeedBooster);
} 
void  Interface::drawgscore(int initialscore ,int x, int y) {
    sf::Text mytext;
    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");
    mytext.setFont(font);
    mytext.setCharacterSize(56);
    std::stringstream ss;  // #include <sstream>
    ss << initialscore;
    mytext.setString(ss.str().c_str());
    mytext.setPosition(x, y);
    mytext.setFillColor(sf::Color::White);

    window.draw(mytext);
}
void Interface::drawgameover(int x, int y) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");
    text.setFont(font);
    text.setPosition(x, y);
    text.setString("GAME OVER");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Cyan);
    text.setStyle(sf::Text::Bold);
    window.draw(text);
}
void Interface::drawfinalscore(int x, int y) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");
    text.setFont(font);
    text.setPosition(x, y+200);
    text.setString("YOUR SCORE IS :  ");
    text.setCharacterSize(56);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    window.draw(text);
}
void Interface::drawline(Vector2D p1, Vector2D p2) {

    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(p1.x , p1.y), ballFillColor),
            sf::Vertex(sf::Vector2f(p2.x , p2.y), ballFillColor)
    };
    window.draw(line, 2, sf::Lines);
}
void Interface::drawBullseyes(Vector2D PositBullseyes, float Radius) {
    sf::CircleShape Bullseyes(Radius);
    Bullseyes.setOrigin(Radius, Radius);
    Bullseyes.setPosition(PositBullseyes.x, PositBullseyes.y);
    Bullseyes.setFillColor(sf::Color::Green);
    window.draw(Bullseyes);
}
void Interface::drawScoreMultipliers(Vector2D ScoreMultiPosition, float Radius) {
    sf::CircleShape scoremultipliers(Radius);
    scoremultipliers.setOrigin(Radius, Radius);
    scoremultipliers.setPosition(ScoreMultiPosition.x, ScoreMultiPosition.y);
    scoremultipliers.setFillColor(sf::Color::Red);
    window.draw(scoremultipliers);
}
void Interface::drawlanes(Vector2D line1start, Vector2D line1end, Vector2D line2start, Vector2D line2end) {
    sf::Vertex line1[] =
    {
            sf::Vertex(sf::Vector2f(line1start.x , line1start.y), ballFillColor),
            sf::Vertex(sf::Vector2f(line1end.x , line1end.y), ballFillColor)
    };
    sf::Vertex line2[] =
    {
            sf::Vertex(sf::Vector2f(line2start.x , line2start.y), ballFillColor),
            sf::Vertex(sf::Vector2f(line2end.x , line2end.y), ballFillColor)
    };
    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
}