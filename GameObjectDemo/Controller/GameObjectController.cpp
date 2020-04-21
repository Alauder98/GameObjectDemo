//
//  GameObjectController.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "GameObjectController.hpp"

// Constructor
GameObjectController::GameObjectController(){
    // Create new objects
    objectList = std::make_unique<std::vector<GameObject*>>();
}

// Function to update all objects in the list
void GameObjectController::UpdateAll(float deltaTime){
    for (GameObject* object : * objectList){
        object->Update(deltaTime);
    }
}

// Function to reder all objects within the list
void GameObjectController::RenderAll(){
    for (GameObject* object : * objectList){
        object->Render();
    }
}

// Add an Object to the list
void GameObjectController::Add(GameObject* object){
    objectList->push_back(object);
    object->Init();
}

// Remove an object from the list
void GameObjectController::Remove(bool removeAll){
    for (GameObject * & object : * objectList){
        // check if inactive, or if we will delete all objects
        if (!object->GetActive() || removeAll){
            delete object;
            object = nullptr;
        }
    }
    
    // remove nullptrs from vector
    objectList->erase(std::remove_if(objectList->begin(), objectList->end(), [](GameObject * obj){return obj == nullptr;}), objectList->end());
}
