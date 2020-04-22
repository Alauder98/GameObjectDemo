//
//  Shooter.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include <vector>
#include "Bullets.h"

// interface to manage shooting of bullets for child class
class i_Shooter
{
public:
    // Constructor / destructor
    i_Shooter();
    virtual ~i_Shooter() = default;
    
    // functions
    void Fire(float xPos, float yPos);
    virtual void Shoot() = 0;
    void Update(float deltaTime);
    
private:
    // vector of bullets
    std::vector<Bullet> m_bullets;
};
