//
//  Bullets.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Bullets.h"

// Constructor
Bullet::Bullet():i_Collision(e_CollisionTypes::BULLET)
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
    SetShapePos(m_position);
    
    // subtract from lifespan
    m_lifespan -= deltaTime;
    // if lifespan is finished, set to inactive
    if (m_lifespan <= 0)
    {
        SetActive(false);
    }
    
    e_CollisionTypes type = CheckCollision();
    // check if any collisions occured, if so, process
    if (type != e_CollisionTypes::NONE){
        ProcessCollision(type);
    }
}

void Bullet::Render()
{
}

// Process Collision with bullet
void Bullet::ProcessCollision(e_CollisionTypes type)
{
    // if player is colided with and we are enemy bullet
    // or if we are player bullet who has colided with enemy
    if ((type == e_CollisionTypes::PLAYER &&
         (int)getCollisionType() ==  12)
        ||
        (type == e_CollisionTypes::ENEMY &&
        (int) getCollisionType() == 10))
    {
        SetActive(false);
    }
}
