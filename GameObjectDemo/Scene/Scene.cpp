//
//  Scene.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 03/05/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Scene.h"
#include "u_XMLReader.h"
#include "ShooterComponent.h"

void Scene::LoadScene(int sceneId, const std::string sceneName)
{
    ShooterComponent::InitShooter(m_objectController);
    
    // Load List of objects within scene
    u_XMLReader::LoadSceneXML("XML/TestObjects", m_objectController);
    m_name = sceneName;
    m_currentSceneID = sceneId;
    
    if (m_name.empty())
    {
        u_ErrorHandler::ThrowWarning("Scene name is empty, please give scene a name");
    }
    if (m_objectController.ReturnList().empty())
    {
        u_ErrorHandler::ThrowError("No objects has been loaded into scene");
    }
}

void Scene::ShutDownScene()
{
    // clear out objects in this scene
    m_objectController.RemoveAll();
    
    if (!m_objectController.ReturnList().empty())
    {
        u_ErrorHandler::ThrowError("Game Object list not cleared properly");
    }
}

void Scene::StepSceneForwardFrame(float deltaTime)
{
    // Update -> Clean Up -> Render Loop
    m_objectController.UpdateAll(deltaTime);
    m_objectController.RenderAll();
}
