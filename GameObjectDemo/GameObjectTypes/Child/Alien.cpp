//
//  Alien.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Alien.hpp"

// This include is here for testing purposes, would be removed in actual implementation
#include <iostream>

// Constructor
Alien::Alien(){
    std::cout << "I'm an Alien and I've been born!" << std::endl;
    // set collider shapes
    SetColliderShape("Sqaure");
}

// Function to update
void Alien::Update(float deltaTime){
    // Check for collision
    CheckCollision();
    std::cout << "I'm an Alien and I'm updating!" << std::endl;
    // update
    Shooter::Update(deltaTime);
}

// Render alien
void Alien::Render(){
    std::cout << "I'm an Alien and I'm rendering!" << std::endl;
}

// Start alien
void Alien::Init(){
    SetActive(true);
    std::cout << "I'm an Alien and I'm initialising!" << std::endl;
}

void Alien::Shoot(){
    
    // Do a random calculation
    
    // fire the bullet
    Fire(position.x(), position.y());
}

// Function to check collision
void Alien::CheckCollision(){
    // update the collider
    std::string collision = UpdateCollider();
    
    if (collision.compare("") != 1){
        // compare to other types that you wish to collide with
    }
}
