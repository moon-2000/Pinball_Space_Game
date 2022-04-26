#include <iostream>
#include "Game.h"
#include "Defs.h"
using namespace std;
  int main() {
       
      Game game;
      while (!game.exited())
      {
              // Read new user (or whatever else)
              game.readInterfaceInput();
          //Simulate the game for one more frame
          game.simulate();
          // Update the game graphical interface
          game.updateInterfaceOutput();
      }
      return 0;
}
     