//
//  Bullets.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "a_GameObject.h"
#include "i_Collision.h"

// Class to create a bullet object
class Bullet: public a_GameObject, public i_Collision
{
public:
    // Constructor
    Bullet();
    ~Bullet() = default;
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void ProcessCollision(e_CollisionTypes type) override;
    void SetActive(bool newValue) override;
    
private:
    float m_lifespan; // the lifespan of this bullet
};
