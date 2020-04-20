//
//  GameObject.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "GameObject.hpp"

// Function to set active status of GameObject
void GameObject::SetActive(bool newValue){
    isActive = newValue;
}

// return active value of Object
bool GameObject::GetActive(){
    return isActive;
}

// Constructor
GameObject::GameObject(){
    SetActive(false);
    position = new Vector2(0, 0);
}

// Destructor
GameObject::~GameObject(){
}

// Function to set pos
void GameObject::setPos(int x, int y){
    position = new Vector2(x, y);
}
