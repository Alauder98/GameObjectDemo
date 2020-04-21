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
#include <memory>
#include "Clock.hpp"
#include "GameObjectController.hpp"

// Class to manage overall Game
class Game{
public:
    // Constructor / Destructor
    Game() = default;
    ~Game();
    
    // Functions
    void Start();
    void ProcessFrame();

private:
    class std::unique_ptr<GameObjectController> objectController; // Game object controller
    class std::unique_ptr<Clock> gameClock; // Clock for game
};

#endif /* Game_hpp */
