//
//  GameObjectController.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include <vector>

class a_GameObject;

// Class to store a list to manage gameobjects
class GameObjectController
{
public:
    // Constructor / Destructor
    GameObjectController() = default;
    ~GameObjectController() = default;
    
    // functions
    void UpdateAll(float deltaTime);
    void Add(a_GameObject* object);
    void RenderAll();
    void Remove(bool all);
private:
    // vector to hold gameObjects
    std::vector<a_GameObject *> m_objectList;
};
