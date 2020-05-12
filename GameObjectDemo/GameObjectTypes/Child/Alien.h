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
#include "ShooterComponent.h"
#include "CollisionComponent.h"

// Class to create alien object
class Alien: public a_GameObject
{
public:
    // Constructor / destructor
    Alien();
    virtual ~Alien() = default;
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void ProcessCollision(e_CollisionTypes type);
    
private:
    ShooterComponent m_ShooterComponent;
    CollisionComponent m_CollisionComponent;
};
