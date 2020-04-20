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

// Class to manage overall Game
class Game{
public:
    // Constructor / Destructor
    Game();
    ~Game();
    
    // Functions
    void Start();
    void ProcessFrame();

private:
    class GameObjectController* objectController; // Game object controller
    class Clock * gameClock; // Clock for game
};

#endif /* Game_hpp */
