//
//  Bullets.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Bullets.hpp"

// Constructor
Bullet::Bullet()
{
    // set collider shapes
    SetColliderShape("Sqaure");
}

void Bullet::Init()
{
}

void Bullet::SetActive(bool newValue)
{
    m_isActive = newValue;
    m_lifespan = 3.0f;
}

void Bullet::Update(float deltaTime)
{
    // check if any collisions occured, if so, process
    if (CheckCollision()){
        ProcessCollision();
    }
    
    // subtract from lifespan
    m_lifespan -= deltaTime;
    // if lifespan is finished, set to inactive
    if (m_lifespan <= 0)
    {
        SetActive(false);
    }
}

void Bullet::Render()
{
}

// Process Collision with bullet
void Bullet::ProcessCollision()
{
    // Redo implementation
}
