//
//  Game.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Clock.h"
#include "Scene.h"

// Class to manage overall Game
class Game
{
public:
    // Constructor / Destructor
    Game() = default;
    ~Game();
    
    // Functions
    void Start();
    void ProcessFrame();

private:
    //GameObjectController m_objectController; // Game object controller
    Clock m_gameClock; // Clock for game
    Scene * m_currentScene;
};
