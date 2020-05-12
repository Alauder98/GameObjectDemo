//
//  Scene.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 03/05/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "GameObjectController.h"
#include <string>

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;
    
    void LoadScene(int SceneId, const std::string sceneName );
    void ShutDownScene();
    void StepSceneForwardFrame(float deltaTime);
    
private:
    
    GameObjectController m_objectController; // Game object controller
    int m_currentSceneID;
    std::string m_name; // name of the scene
};
