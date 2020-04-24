//
//  Alien.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Alien.h"

// This include is here for testing purposes, would be removed in actual implementation
#include <iostream>

// Constructor
Alien::Alien():i_Collision(e_CollisionTypes::ENEMY), i_Shooter(e_CollisionTypes::ENEMY)
{
    // set collider shapes
    SetColliderShape("Test");
}

// Function to update
void Alien::Update(float deltaTime)
{
    SetShapePos(m_position);
    
    // update
    i_Shooter::Update(deltaTime);
    
    // check if any collisions occured, if so, process
    e_CollisionTypes type = CheckCollision();
    if (type != e_CollisionTypes::NONE){
        ProcessCollision(type);
    }
}

// Render alien
void Alien::Render()
{
}

// Start alien
void Alien::Init()
{
    SetActive(true);
}

void Alien::Shoot()
{
    
    // Do a random calculation
    
    // fire the bullet
    Fire(m_position.x(), m_position.y());
}

// Function to check collision
void Alien::ProcessCollision(e_CollisionTypes type)
{
    switch((int)type)
    {
        case 10:
            SetActive(false);
            break;
    }
}
