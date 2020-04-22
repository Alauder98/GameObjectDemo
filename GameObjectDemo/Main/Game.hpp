//
//  Game.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "GameObjectController.hpp"
#include "Clock.hpp"

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
    GameObjectController m_objectController; // Game object controller
    Clock m_gameClock; // Clock for game
};

#endif /* Game_hpp */
