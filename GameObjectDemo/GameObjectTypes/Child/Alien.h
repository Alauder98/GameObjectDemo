//
//  Alien.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "a_GameObject.h"
#include "i_Shooter.h"
#include "i_Collision.h"

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
