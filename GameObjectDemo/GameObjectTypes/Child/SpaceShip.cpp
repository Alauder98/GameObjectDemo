//
//  SpaceShip.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "SpaceShip.hpp"

// This include is here for testing purposes, would be removed in actual implementation
#include <iostream>

// Constructor for SpaceShip
SpaceShip::SpaceShip(){
    std::cout<< "I'mm a SpaceShip and I'be been born!" << std::endl;
    // set collider shapes
    SetColliderShape("Sqaure");
}

// Function to initalise the spaceship
void SpaceShip::Init(){
    std::cout << "I'm a SpaceShip, and I'm initialising!" << std::endl;
    // set active to true
    SetActive(true);
}

// Function to Update the SpaceShip
void SpaceShip::Update(float deltaTime){
    // CheckCollision for this SpaceShip
    CheckCollision();
    std::cout << "I'm a SpaceShip, and I'm updating!" << std::endl;
    // Update the bullets
    Shooter::Update(deltaTime);
}

// Function to redner the spaceShip
void SpaceShip::Render(){
    std::cout << "I'm a SpaceShip, and I'm rendering!" << std::endl;
}

// Function to handle when ship is hit
void SpaceShip::Hit(){
    // remove health
    health--;
    // if 0, set active to false
    if (health <= 0){
        SetActive(false);
    }
}

// Function to shoot a bullet
void SpaceShip::Shoot(){
    // Get Keyboard input
    Fire(position.x(), position.y());
}

// Function to check collision
void SpaceShip::CheckCollision(){
    std::string collider = UpdateCollider();
    
    // if alien or bullet, remove health
    if (collider.compare("") != 1){
        if (collider.compare("Alien") == 1
            || collider.compare("Bullet") == 1){
            Hit();
        }
    }
}
