//
//  Game.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Game.h"
#include "u_ErrorHandler.h"

// destructor
Game::~Game()
{
    /*
    // delete all gameobjects
    m_objectController.RemoveAll();
     */
    
    m_currentScene->ShutDownScene();
    delete m_currentScene;
    m_currentScene = nullptr;
}

// Function to start game
void Game::Start()
{
    /*
    // Create Releveant game objects for test
    SpaceShip* testSpaceShip = new SpaceShip();
    Alien* testAlien = new Alien();
    
    // Add these to object controller
    m_objectController.Add(testSpaceShip);
    m_objectController.Add(testAlien);
    ShooterComponent::InitShooter(m_objectController);
     */
    
    m_currentScene = new Scene();
    m_currentScene->LoadScene(1, "Test");
}

// Function to process a frame
void Game::ProcessFrame()
{
    // tick timer
    m_gameClock.Tick();
    
    //Update->Removce->Render Inactive on current scene
    m_currentScene->StepSceneForwardFrame(m_gameClock.GetDeltaTime());
    
    /*
    // Update -> Render -> Remove inactive
    m_objectController.UpdateAll(m_gameClock.GetDeltaTime());
    m_objectController.RenderAll();
    //m_objectController.Remove(false);
     */
}


