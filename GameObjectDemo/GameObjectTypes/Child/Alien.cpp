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
Alien::Alien()
{
    // set collider shapes
    m_CollisionComponent.SetColliderShape(1);
    m_CollisionComponent.AddCollisionType(e_CollisionTypes::ENEMY);
}

// Function to update
void Alien::Update(float deltaTime)
{
    m_CollisionComponent.SetShapePos(m_position);
    
    // check if any collisions occured, if so, process
    e_CollisionTypes type = m_CollisionComponent.CheckCollision();
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
    m_isActive = true;
}

// Function to check collision
void Alien::ProcessCollision(e_CollisionTypes type)
{
    switch((int)type)
    {
        case TAG_PLAYER_BULLET:
            m_ToDelete = true;
            break;
    }
}
