//
//  Shooter.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Shooter.hpp"

#define BULLET_SIZE 3 // how many bullets can be fired at once

// An interface to allow for a gameobject to shoot bullets

// constructor (Deafult)
Shooter::Shooter(){
    // intialising bullets
    bullets = std::make_unique<std::vector<std::unique_ptr<Bullet>>>();
    bullets->reserve(BULLET_SIZE);
    
    for (int i = 0; i < BULLET_SIZE; i++){
        bullets->push_back(std::make_unique<Bullet>());
    }
}

// Update function to be called each frame
void Shooter::Update(float deltaTime){
    for (auto& bullet : * bullets){
        // if bullets are active, update them
        if (bullet->GetActive()){
            bullet->Update(deltaTime);
        }
    }
}

// function to fire a bullet
void Shooter::Fire(float xPos, float yPos){
    for (int i = 0; i < bullets->size(); i++){
        // if inactive, fire
        if(!bullets->at(i)->GetActive()){
            bullets->at(i)->setPos(xPos, yPos);
            bullets->at(i)->SetActive(true);
            return;
        }
    }
}



