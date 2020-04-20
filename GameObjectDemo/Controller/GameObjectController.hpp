//
//  GameObjectController.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef GameObjectController_hpp
#define GameObjectController_hpp

#include <stdio.h>
#include <vector>
#include "GameObject.hpp"

// Class to store a list to manage gameobjects
class GameObjectController{
public:
    // Constructor / Destructor
    GameObjectController();
    ~GameObjectController();
    
    // functions
    void UpdateAll(float deltaTime);
    void Add(GameObject* object);
    void RenderAll();
    void Remove(bool all);
private:
    // vector to hold gameObjects
    std::vector<GameObject *> * objectList;
};

#endif /* GameObjectController_hpp */
