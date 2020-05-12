//
//  SpaceShip.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "SpaceShip.h"
#include "c_ShootCommand.h"
#include "a_Command.h"

SpaceShip::SpaceShip()
{
    // set collider shapes
    m_CollisionComponent.SetColliderShape(1);
    m_CollisionComponent.AddCollisionType(e_CollisionTypes::PLAYER);
    m_maxHealth = m_CurrentHealth = 3;
}

void SpaceShip::Init()
{
    // set active to true
    m_isActive = true;
    
    m_inputHandler.SetInput(SPACE, new c_ShootCommand());
}

void SpaceShip::Update(float deltaTime)
{
    // attempt to get command
    a_Command * command = m_inputHandler.HandleInput();
    
    // If we get a command, execute
    if (command)
    {
        command->Execute((this));
    }
    
    m_CollisionComponent.SetShapePos(m_position);
    
    // check if any collisions occured, if so, process
    e_CollisionTypes type = m_CollisionComponent.CheckCollision();
    if (type != e_CollisionTypes::NONE){
        ProcessCollision(type);
    }
    
    m_ToDelete = true;
}

void SpaceShip::Render()
{
}

// Function to handle when ship is hit
void SpaceShip::Hit()
{
    // remove health
    m_CurrentHealth--;
    // if 0, set active to false
    if (m_CurrentHealth <= 0)
    {
        m_ToDelete = true;
    }
}

// Shoot Command
void SpaceShip::Shoot()
{
    m_shooterComponent.Fire(m_position.x(), m_position.y(), e_CollisionTypes::PLAYER);
}

// Function to check collision
void SpaceShip::ProcessCollision(e_CollisionTypes type)
{
    switch ((int)type)
    {
        case TAG_ENEMY_BULLET:
        case TAG_ENEMY:
            m_CurrentHealth--;
            if (m_CurrentHealth == 0)
            {
                m_ToDelete = true;
            }
            break;
    }
}
