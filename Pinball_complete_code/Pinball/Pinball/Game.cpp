
#include "Game.h"
#include <iostream>
using namespace std;
#define GRAVITY 700.0f
float  GameHight, GameWidth, BallRadius, FlipMajRadius, FlipMinRadius, FlipLength, FlipDistance, PumRadius, CeilingPosition, XcollectPosition, YcollectPosition, XInitialCenter, YInitialCenter, XInitialVelocity,
YInitialVelocity, xPumPosition, yPumPosition, Speedmultiplier, xKicker1,
yKicker1, xKicker2, yKicker2, xKicker3, yKicker3, XspeedBooster, YspeedBooster, RspeedBooster, WallPosition, BullX, BullY, bullRadius, LINExs, LINEys, LINExe, LINEye, scoreMultiX, scoreMultiY, scoreMultiRadius , line1SX ,line1SY , line1EX , line1EY , line2SX ,line2SY , line2EX ,line2EY;
string  GaMeWidth, GaMeHight, BaLlRadius, xCenter, yCenter, xVelocity, yVelocity, Flipmaj, Flipmin
, flipLength, flipDistance, ballRadius, ObsatcleType;

Game::Game()
{
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;


    ifstream Data;
    Data.open("PinBallDataGame.txt");
    Data >> ObsatcleNumber;
    Data >> GaMeWidth >> GameWidth;
    Data >> GaMeHight >> GameHight;
    Data >> ballRadius >> BallRadius;
    Data >> xCenter >> yCenter >> XInitialCenter >> YInitialCenter;
    Data >> xVelocity >> yVelocity >> XInitialVelocity >> YInitialVelocity;
    Data >> Flipmaj >> FlipMajRadius;
    Data >> Flipmin >> FlipMinRadius;
    Data >> flipLength >> FlipLength;
    Data >> flipDistance >> FlipDistance;

    interface = new Interface(GameWidth, GameHight);
    gameOver = new gameover(50, 20);
    gameObjectValues = new Obstacle * [ObsatcleNumber];
    for (int i = 0; i < ObsatcleNumber; i++) {
        Data >> ObsatcleType;
        if (ObsatcleType == "POP_BUMPER") {
            Data >> xPumPosition >> yPumPosition >> PumRadius;
            gameObjectValues[i] = new  POP_BUMPER(Vector2D{ xPumPosition,yPumPosition }, PumRadius);
              }
        else if (ObsatcleType == "VIBRANIUM_BUMPER") {
            Data >> xPumPosition >> yPumPosition >> PumRadius;
            gameObjectValues[i] = new  VIBRANIUM_BUMPER(Vector2D{ xPumPosition,yPumPosition }, PumRadius);
           }
        else if (ObsatcleType == "THRUST_BUMPER") {
            Data >> xPumPosition >> yPumPosition >> PumRadius >> Speedmultiplier;
            gameObjectValues[i] = new THRUST_BUMPER(Vector2D{ xPumPosition,yPumPosition }, PumRadius, Speedmultiplier);
             }
        else if (ObsatcleType == "Kicker") {
            Data >> xKicker1 >> yKicker1 >> xKicker2 >> yKicker2 >> xKicker3 >> yKicker3;
            gameObjectValues[i] = new Kickers(Vector2D{ xKicker1,yKicker1 }, Vector2D{ xKicker2,yKicker2 }, Vector2D{ xKicker3,yKicker3 });
         }
        else if (ObsatcleType == "Wall") {
            Data >> WallPosition;
            gameObjectValues[i] = new Wall(WallPosition);
        }
        else if (ObsatcleType == "Ceiling") {
            Data >> CeilingPosition;
            gameObjectValues[i] = new ceiling(CeilingPosition);
        }
        else if (ObsatcleType == "Collectables") {
            Data >> XcollectPosition >> YcollectPosition;
            gameObjectValues[i] = new Collectables(XcollectPosition, YcollectPosition);
        }
        else if (ObsatcleType == "speedBooster") {
            Data >> XspeedBooster >> YspeedBooster >> RspeedBooster;
            gameObjectValues[i] = new speedBooster(Vector2D{ XspeedBooster, YspeedBooster }, RspeedBooster);
        }
        else if (ObsatcleType == "Lanes") {
            Data >> line1SX >> line1SY >> line1EX >> line1EY >> line2SX >> line2SY >> line2EX >> line2EY;
            gameObjectValues[i] = new Lanes(Vector2D{ line1SX, line1SY }, Vector2D{ line1EX, line1EY }, Vector2D{ line2SX, line2SY }, Vector2D{ line2EX, line2EY });
        }
        else if (ObsatcleType == "Bullseyes") {
            Data >> BullX >> BullY >> bullRadius;
            gameObjectValues[i] = new Bullseyes(Vector2D{ BullX, BullY }, bullRadius);
        }
        else if (ObsatcleType == "scoremultipliers") {
            Data >> scoreMultiX >> scoreMultiY >> scoreMultiRadius;
            gameObjectValues[i] = new scoremultipliers(Vector2D{ scoreMultiX, scoreMultiY }, scoreMultiRadius);
        }
        else if (ObsatcleType == "line") {
            Data >> LINExs >> LINEys >> LINExe >> LINEye;
            gameObjectValues[i] = new line(Vector2D{ LINExs, LINEys }, Vector2D{ LINExe, LINEye });
        }
        else {
            cout << "Error in " << i << endl;
        }

    }
    flipperData = new Flipper * [2];
    flipperData[0] = new Flipper(LEFT, Vector2D{ GameWidth / 2.0f - 1.4f * (FlipLength + FlipDistance / 2.0f), GameHight - 50.0f }, 1.2f * FlipLength, 30.0f, FlipMajRadius, FlipMinRadius);
    flipperData[1] = new Flipper(RIGHT, Vector2D{ GameWidth / 2.0f + 1.4f * (FlipLength + FlipDistance / 2.0f), GameHight - 50.0f }, 1.2f * FlipLength, -30.0f, FlipMajRadius, FlipMinRadius);
    lineData = new line * [2];
    lineData[0] = new line({ 0,GameHight - 250 }, { GameWidth / 2.0f - 1.4f * (FlipLength + FlipDistance / 2.0f) ,GameHight - 20 });
    lineData[1] = new line({ GameWidth / 2.0f + 1.4f * (FlipLength + FlipDistance / 2.0f),GameHight - 250 }, { GameWidth ,500 });
    ball = new Ball({ XInitialCenter, YInitialCenter }, { XInitialVelocity ,YInitialVelocity }, BallRadius);

     Data.close();
 
} 

void Game::readInterfaceInput()
{
    interface->getControls(exit, left, right);
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    float deltaTime = timeSpan.count();
    if (left == true) {
       
        if (ball->center.x > flipperData[0]->center.x && ball->center.x < lineData[0]->P2.x && ball->center.y < lineData[0]->P2.y && ball->center.y > GameHight - 90) {
            ball->setVelocity(160, -900);
        }
        for (int i = 30; i > -30;i--) {
            flipperData[0]->setangle(i);
        }
        if (ball->center.x < flipperData[0]->center.x && ball->center.x > lineData[0]->P2.x-5 && ball->center.y < lineData[0]->P2.y && ball->center.y > GameHight -90) {
            ball->setVelocity(0, 0);
        }
        lineData[0] = new line({ 0,GameHight - 250 }, { flipperData[0]->center.x , flipperData[0]->center.y - 7 });
    }
    else {
       lineData[0] = new line({ 0,GameHight - 250 }, { GameWidth / 2.0f - 1.4f * (FlipLength + FlipDistance / 2.0f) + (FlipLength + 15)* sqrt(3.0f)/2.0f ,GameHight - 0.5f *( FlipLength+15) + 3*FlipMinRadius  });
       
        for (int i = -30; i < 30; i++) {
            flipperData[0]->setangle(i);
        }
       
    }
    
    if (right == true) {
        if (ball->center.x < flipperData[1]->center.x && ball->center.x > lineData[1]->P1.x && ball->center.y < lineData[1]->P1.y && ball->center.y > GameHight - 90) {
            ball->setVelocity(-160, -900);
        }
       
        for (int i = -30; i < 30; i++) {
            flipperData[1]->setangle(i);
        }       
        lineData[1] = new line({ flipperData[1]->center.x , flipperData[1]->center.y - 7 }, { 700 ,GameHight - 250 });
        if (ball->center.x > flipperData[1]->center.x && ball->center.x < lineData[1]->P1.x + 5 && ball->center.y < lineData[1]->P1.y && ball->center.y >GameHight - 90) {
            ball->setVelocity(0, 0);
        }
    }
    else {
        lineData[1] = new line({ GameWidth / 2.0f + 1.4f * (FlipLength + FlipDistance / 2.0f) - (FlipLength+15) * sqrt(3.0f) / 2.0f ,GameHight - 0.5f * (FlipLength + 15) + 3 * FlipMinRadius }, { 700 ,GameHight - 250 });
        for (int i = 30; i > -30; i--) {
            flipperData[1]->setangle(i);
        }
    }
}


void Game::simulate()
 {
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    lastFrame = thisFrame;
    float deltaTime = timeSpan.count();  // Delta time in seconds
    if (ball->center.x < flipperData[0]->center.x && ball->center.x > lineData[0]->P2.x - 5 && ball->center.y < 730 && ball->center.y > 660) {
        Vector2D resultantAcceleration = { 0, 0 };

    }
    else  if (ball->center.x > flipperData[1]->center.x && ball->center.x < lineData[1]->P1.x + 5 && ball->center.y < 730 && ball->center.y > 660) {
        Vector2D resultantAcceleration = { 0, 0 };


    }
    else {
        Vector2D resultantAcceleration = { 0, GRAVITY };  // Starting with gravity as the first acceleration contributer
        resultantAcceleration += flipperData[0]->collideWith(*ball, deltaTime);
        resultantAcceleration += flipperData[1]->collideWith(*ball, deltaTime);
        resultantAcceleration += lineData[0]->collideWith(*ball, deltaTime);
        resultantAcceleration += lineData[1]->collideWith(*ball, deltaTime);
        for (int k = 0; k < ObsatcleNumber; k++) {
            resultantAcceleration += gameObjectValues[k]->collideWith(*ball, deltaTime);
        }
        ball->move(resultantAcceleration, deltaTime);
    }
 }

void Game::updateInterfaceOutput()
{
    interface->clear();

    //leftFlipper.draw(interface);
   // The following two lines be replaced with a loop over collidable obstacles
    if (ball->getCenter().y < GameHight) {
        lineData[1]->draw(*interface);
        lineData[0]->draw(*interface);
        flipperData[1]->draw(*interface);
        flipperData[0]->draw(*interface);
        ball->draw(*interface);
        ball->drawscore(*interface);
        //Ceiling[0]->draw(*interface);
       // lanes[0]->draw(*interface);
        for (int k = 0; k < ObsatcleNumber; k++) {
            gameObjectValues[k]->draw(*interface);
        }
    }
    else {
        gameOver->draw(*interface);
        ball->Xposition = 530;
        ball->Yposition = 200;
        ball->drawscore(*interface);
        ball->drawFinalscore(*interface);
    }
   // Booster.draw(interface);
    interface->display();
}

bool Game::exited()
{
    return exit;
}
Game::~Game() {
    delete[] gameObjectValues;
    delete[] flipperData;
}