//
//  GameObjectController.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "GameObjectController.h"
#include "a_GameObject.h"

// Function to update all objects in the list
void GameObjectController::UpdateAll(float deltaTime)
{
    for (a_GameObject* object : m_objectList)
    {
        if (object)
        {
            object->Update(deltaTime);
        }
    }
}

// Function to reder all objects within the list
void GameObjectController::RenderAll()
{
    for (a_GameObject* object : m_objectList)
    {
        if (object)
        {
            object->Render();
        }
    }
}

// Add an Object to the list
void GameObjectController::Add(a_GameObject* object)
{
    if (object)
    {
        m_objectList.push_back(object);
        object->Init();
    }
}

// Remove an object from the list
void GameObjectController::Remove(bool removeAll)
{
    for (a_GameObject * & object : m_objectList)
    {
        // check if inactive, or if we will delete all objects
        if ((object && !object->GetActive()) || removeAll)
        {
            delete object;
            object = nullptr;
        }
    }
    
    // remove nullptrs from vector
    m_objectList.erase(std::remove_if(m_objectList.begin(), m_objectList.end(), [](a_GameObject * obj){return obj == nullptr;}), m_objectList.end());
}
