//
//  Game.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Game.hpp"

/* These would be removed and used in a more fomal "level" class*/
#include "SpaceShip.hpp"
#include "Alien.hpp"


// destructor
Game::~Game(){
    // delete all gameobjects
    objectController->Remove(true);
    // delete the controller and clock
}

// Function to start game
void Game::Start(){
    // create new object controller
    objectController = std::make_unique<GameObjectController>();
    
    // create and start clock
    gameClock = std::make_unique<Clock>();
    gameClock->Start();
    
    // Create Releveant game objects for test
    SpaceShip* testSpaceShip = new SpaceShip();
    Alien* testAlien = new Alien();
    
    // Add these to object controller
    objectController->Add(testSpaceShip);
    objectController->Add(testAlien);
}

// Function to process a frame
void Game::ProcessFrame(){
    // tick timer
    gameClock->Tick();
    // update objects
    objectController->UpdateAll(gameClock->GetTime());
    // render new states
    objectController->RenderAll();
    // remove inactive objects
    objectController->Remove(false);
}


