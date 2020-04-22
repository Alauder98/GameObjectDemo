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
Alien::Alien():i_Collision(e_CollisionTypes::ENEMY)
{
    std::cout << "I'm an Alien and I've been born!" << std::endl;
    // set collider shapes
    SetColliderShape("Sqaure");
}

// Function to update
void Alien::Update(float deltaTime)
{
    // check if any collisions occured, if so, process
    if (CheckCollision() != e_CollisionTypes::NONE){
        ProcessCollision();
    }
    
    std::cout << "I'm an Alien and I'm updating!" << std::endl;
    // update
    i_Shooter::Update(deltaTime);
}

// Render alien
void Alien::Render()
{
    std::cout << "I'm an Alien and I'm rendering!" << std::endl;
}

// Start alien
void Alien::Init()
{
    SetActive(true);
    std::cout << "I'm an Alien and I'm initialising!" << std::endl;
}

void Alien::Shoot()
{
    
    // Do a random calculation
    
    // fire the bullet
    Fire(m_position.x(), m_position.y());
}

// Function to check collision
void Alien::ProcessCollision()
{
    // Redo Implementation
}
