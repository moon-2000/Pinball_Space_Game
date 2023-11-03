#pragma once

#include <chrono>
using namespace std::chrono;

#include <string>
using namespace std;

#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Flipper.h"
#include "GameObjects/Obstacles/gameover.h"
#include "GameObjects/Obstacles/Pumbers.h"
#include "GameObjects/Obstacles/Kickers.h"
#include "GameObjects/Obstacles/ceiling.h"
#include "GameObjects/Obstacles/Collectables.h"
#include "GameObjects/Obstacles/speedBooster.h"
#include "GameObjects/Obstacles/POP_BUMPER.h"
#include "GameObjects/Obstacles/VIBRANIUM_BUMPER.h"
#include "GameObjects/Obstacles/THRUST_BUMPER.h"
#include "GameObjects/Obstacles/line.h"
#include "GameObjects/Obstacles/lanes.h"
#include "GameObjects/Obstacles/scoremultipliers.h"
#include "GameObjects/Obstacles/Bullseyes.h"
// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface* interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls
    int  ObsatcleNumber;
    Ball* ball;
    ceiling** Ceiling;
    gameover* gameOver;// The ball (obviously :D)
    Wall** wallData;
    Lanes** lanes;
public:
    Game();
    ~Game();
    void readInterfaceInput();  
    void simulate();
    void updateInterfaceOutput();
    bool exited();
    Flipper** flipperData;
    line** lineData;
    Obstacle** gameObjectValues;
    THRUST_BUMPER** THRUST_BUMPERData;
    POP_BUMPER** POP_BUMPERData;
    VIBRANIUM_BUMPER** VIBRANIUM_BUMPERData;
    Kickers** KickersData;
   

};
 