//
//  SpaceShip.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "SpaceShip.h"

// This include is here for testing purposes, would be removed in actual implementation
#include <iostream>

SpaceShip::SpaceShip():i_Collision(e_CollisionTypes::PLAYER)
{
    std::cout<< "I'mm a SpaceShip and I'be been born!" << std::endl;
    // set collider shapes
    SetColliderShape("Sqaure");
}

void SpaceShip::Init()
{
    std::cout << "I'm a SpaceShip, and I'm initialising!" << std::endl;
    // set active to true
    SetActive(true);
}

void SpaceShip::Update(float deltaTime)
{
    // check if any collisions occured, if so, process
    if (CheckCollision() != e_CollisionTypes::NONE){
        ProcessCollision();
    }
    
    std::cout << "I'm a SpaceShip, and I'm updating!" << std::endl;
    // Update the bullets
    i_Shooter::Update(deltaTime);
}

void SpaceShip::Render()
{
    std::cout << "I'm a SpaceShip, and I'm rendering!" << std::endl;
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
void SpaceShip::ProcessCollision()
{
    // Redo Implementation
}
