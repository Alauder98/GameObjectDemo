//
//  SpaceShip.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "a_GameObject.h"
#include "i_Shooter.h"
#include "i_Collision.h"
#include "h_InputHandler.h"

// Class to create spaceship
class SpaceShip: public a_GameObject, public i_Shooter, public i_Collision
{
public:
    // Constructor / Destructor
    SpaceShip();
    ~SpaceShip() = default;
    
    // Functions
    void Update(float DeltaTime) override;
    void Render() override;
    void Init() override;
    void Shoot() override;
    void ProcessCollision(e_CollisionTypes type) override;
    void Hit();

private:
    int m_health; // The health of the player
    h_InputHandler m_inputHandler;
};
