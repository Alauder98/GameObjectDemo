//
//  Shooter.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Shooter.hpp"
#include <vector>

#define BULLET_SIZE 3 // how many bullets can be fired at once

// An interface to allow for a gameobject to shoot bullets

// constructor (Deafult)
Shooter::Shooter(){
    // intialising bullets
    bullets = new std::vector<Bullet*>();
    bullets->reserve(BULLET_SIZE);
    
    for (int i = 0; i < BULLET_SIZE; i++){
        Bullet* newBullet = new Bullet();
        bullets->push_back(newBullet);
    }
}

// Update function to be called each frame
void Shooter::Update(float deltaTime){
    for (Bullet* bullet : * bullets){
        // if bullets are active, update them
        if (bullet->GetActive()){
            bullet->Update(deltaTime);
        }
    }
}

// destructor
Shooter::~Shooter(){
    for (Bullet * & bullet : * bullets){
        // delete bullets
        delete bullet;
        bullet = nullptr;
    }
    
    // erase nullptrs
    bullets->erase(std::remove_if(bullets->begin(), bullets->end(), [](GameObject * obj){return obj == nullptr;}), bullets->end());
    
    // delete the list
    delete bullets;
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



