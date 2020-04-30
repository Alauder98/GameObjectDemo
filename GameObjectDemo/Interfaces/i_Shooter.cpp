//
//  Shooter.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "i_Shooter.h"
#include "u_DebugMonitor.h"

#define BULLET_SIZE 3 // how many bullets can be fired at once

// constructor (Deafult)
i_Shooter::i_Shooter(e_CollisionTypes parentCollisionType)
{
    // intialising bullets
    m_bullets.reserve(BULLET_SIZE);
    
    for (int i = 0; i < BULLET_SIZE; i++)
    {
        Bullet newBullet;
        newBullet.AddCollisionType(parentCollisionType);
        m_bullets.push_back(newBullet);
        u_DebugMonitor::AddGameObject();
    }
}

// Update function to be called each frame
void i_Shooter::Update(float deltaTime)
{
    for (auto& bullet : m_bullets)
    {
        // if bullets are active, update them
        if (bullet.GetActive())
        {
            bullet.Update(deltaTime);
        }
    }
}

// function to fire a bullet
void i_Shooter::Fire(float xPos, float yPos)
{
    for (int i = 0; i < m_bullets.size(); i++)
    {
        // if inactive, fire
        if(!m_bullets.at(i).GetActive())
        {
            m_bullets.at(i).setPos(xPos, yPos);
            m_bullets.at(i).SetActive(true);
            return;
        }
    }
}



