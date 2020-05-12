//
//  Bullets.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Bullets.h"

// Constructor
Bullet::Bullet()
{
    // set collider shapes
    m_collisionComponent.SetColliderShape(1);
    m_collisionComponent.AddCollisionType(e_CollisionTypes::BULLET);
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
    m_collisionComponent.SetShapePos(m_position);
    
    // subtract from lifespan
    m_lifespan -= deltaTime;
    // if lifespan is finished, set to inactive
    if (m_lifespan <= 0)
    {
        SetActive(false);
    }
    
    e_CollisionTypes type = m_collisionComponent.CheckCollision();
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
    int collisionType = (int)m_collisionComponent.getCollisionType();
    // if player is colided with and we are enemy bullet
    // or if we are player bullet who has colided with enemy
    if ((type == e_CollisionTypes::PLAYER &&
         collisionType ==  TAG_ENEMY_BULLET)
        ||
        (type == e_CollisionTypes::ENEMY &&
        collisionType == TAG_PLAYER_BULLET))
    {
        SetActive(false);
    }
}

void Bullet::SetOwned(bool newOwnedValue)
{
    m_currentlyOwned = newOwnedValue;
}
