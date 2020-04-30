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

// This include is here for testing purposes, would be removed in actual implementation
#include <iostream>

SpaceShip::SpaceShip():i_Collision(e_CollisionTypes::PLAYER), i_Shooter(e_CollisionTypes::PLAYER)
{
    // set collider shapes
    SetColliderShape(1);
}

void SpaceShip::Init()
{
    // set active to true
    SetActive(true);
    
    m_inputHandler.SetInput(SPACE, new c_ShootCommand());
}

void SpaceShip::Update(float deltaTime)
{
    // attempt to get command
    a_Command * command = m_inputHandler.HandleInput();
    
    // If we get a command, execute
    if (command)
    {
        command->Execute(static_cast<a_GameObject &>(* this));
    }
    
    SetShapePos(m_position);
    
    // Update the bullets
    i_Shooter::Update(deltaTime);
    
    // check if any collisions occured, if so, process
    e_CollisionTypes type = CheckCollision();
    if (type != e_CollisionTypes::NONE){
        ProcessCollision(type);
    }
}

void SpaceShip::Render()
{
}

// Function to handle when ship is hit
void SpaceShip::Hit()
{
    // remove health
    m_health--;
    // if 0, set active to false
    if (m_health <= 0)
    {
        SetActive(false);
    }
}

// Function to shoot a bullet
void SpaceShip::Shoot()
{
    // Get Theoretical Keyboard input
    Fire(m_position.x(), m_position.y());
}

// Function to check collision
void SpaceShip::ProcessCollision(e_CollisionTypes type)
{
    switch ((int)type)
    {
        case TAG_ENEMY_BULLET:
        case TAG_ENEMY:
            m_health--;
            if (m_health == 0)
            {
                SetActive(false);
            }
            break;
    }
}
