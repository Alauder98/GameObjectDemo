//
//  Alien.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>
#include "a_GameObject.hpp"
#include "i_Shooter.hpp"
#include "i_Collision.hpp"

// Class to create alien object
class Alien: public a_GameObject, i_Shooter, i_Collision
{
public:
    // Constructor / destructor
    Alien();
    ~Alien() = default;
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void Shoot() override;
    void ProcessCollision() override;
};

#endif /* Alien_hpp */
