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
Game::~Game()
{
    // delete all gameobjects
    m_objectController.Remove(true);
}

// Function to start game
void Game::Start()
{
    
    m_gameClock.Start();
    
    // Create Releveant game objects for test
    SpaceShip* testSpaceShip = new SpaceShip();
    Alien* testAlien = new Alien();
    
    // Add these to object controller
    m_objectController.Add(testSpaceShip);
    m_objectController.Add(testAlien);
}

// Function to process a frame
void Game::ProcessFrame()
{
    // tick timer
    m_gameClock.Tick();
    m_objectController.UpdateAll(m_gameClock.GetTime());
    m_objectController.RenderAll();
    m_objectController.Remove(false);
}


