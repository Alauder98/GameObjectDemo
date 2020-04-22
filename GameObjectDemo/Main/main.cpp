//
//  main.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

// Main to demo logic
int main(int argc, const char * argv[])
{
    // create a new game
    Game* newGame = new Game();
    // run game start
    newGame->Start();
    // process a frame
    newGame->ProcessFrame();
    // delete the game and all contents
    delete newGame;
}
