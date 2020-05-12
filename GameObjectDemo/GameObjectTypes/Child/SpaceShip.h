//
//  SpaceShip.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "a_GameObject.h"
#include "ShooterComponent.h"
#include "CollisionComponent.h"
#include "h_InputHandler.h"

// Class to create spaceship
class SpaceShip: public a_GameObject
{
public:
    // Constructor / Destructor
    SpaceShip();
    ~SpaceShip() = default;
    
    // Functions
    void Update(float DeltaTime) override;
    void Render() override;
    void Init() override;
    void ProcessCollision(e_CollisionTypes type);
    void Hit();
    void Shoot();

private:
    int m_CurrentHealth; // The health of the player
    int m_maxHealth;
    h_InputHandler m_inputHandler;
    ShooterComponent m_shooterComponent;
    CollisionComponent m_CollisionComponent;
};
