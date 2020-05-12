//
//  GameObjectController.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "GameObjectController.h"
#include "a_GameObject.h"
#include "u_DebugMonitor.h"

// Function to update all objects in the list
void GameObjectController::UpdateAll(float deltaTime)
{
    u_DebugMonitor::PrintToConsole();
    for (a_GameObject * & object : m_objectList)
    {
        if (object != nullptr)
        {
            object->Update(deltaTime);
            
            if (object->GetToDelete())
            {
                u_DebugMonitor::RemoveGameObject();
                delete object;
                object = nullptr;
            }
        }
    }
    
    // remove nullptrs from vector
    m_objectList.erase(std::remove_if(m_objectList.begin(), m_objectList.end(), [](a_GameObject * obj){return obj == nullptr;}), m_objectList.end());
    
    u_DebugMonitor::PrintToConsole();
}

// Function to reder all objects within the list
void GameObjectController::RenderAll()
{
    for (a_GameObject* object : m_objectList)
    {
        if (object != nullptr)
        {
            object->Render();
        }
    }
}

// Add an Object to the list
void GameObjectController::Add(a_GameObject* object)
{
    if (object != nullptr)
    {
        m_objectList.push_back(object);
        object->Init();
    }
    
    u_DebugMonitor::AddGameObject();
}

// Remove an object from the list
void GameObjectController::RemoveAll()
{
    for (a_GameObject * object : m_objectList)
    {
        if (object != nullptr)
        {
            u_DebugMonitor::RemoveGameObject();
            delete object;
            object = nullptr;
        }
    }
    
    // remove nullptrs from vector
    m_objectList.erase(std::remove_if(m_objectList.begin(), m_objectList.end(), [](a_GameObject * obj){return obj == nullptr;}), m_objectList.end());
    
    m_objectList.clear();
}
