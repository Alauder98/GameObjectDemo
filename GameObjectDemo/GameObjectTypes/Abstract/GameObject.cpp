//
//  GameObject.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "GameObject.hpp"
#include "Vector2.hpp"

// Function to set active status of GameObject
void GameObject::SetActive(bool newValue){
    isActive = newValue;
}

// return active value of Object
bool GameObject::GetActive() const{
    return isActive;
}

// Constructor
GameObject::GameObject(){
    SetActive(false);
    position.Set(0.0f, 0.0f);
}

// Function to set pos
void GameObject::setPos(float x, float y){
    position.Set(x, y);
}
