//
//  Bullets.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Bullets.hpp"

// Constructor
Bullet::Bullet(){
    // set lifespan
    lifespan = 3.0f;
    // set collider shapes
    SetColliderShape("Sqaure");
}

// Initalise the bullet
void Bullet::Init(){
}

// update the bullet
void Bullet::Update(float deltaTime){
    // check its collisions
    CheckCollision();
    // subtract from lifespan
    lifespan -= deltaTime;
    // if lifespan is finished, set to inactive
    if (lifespan <= 0){
        SetActive(false);
    }
}

// Render the bullet
void Bullet::Render(){
}

// Check collision with bullet
void Bullet::CheckCollision(){
    // get collisions
    std::string collider = UpdateCollider();
    
    if (collider.compare("") != 1){
        // Handles Collision based upon repsonse
    }
}
