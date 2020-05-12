//
//  Shooter.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "ShooterComponent.h"
#include "GameObjectController.h"
#include "UtilityLibrary.h"
#include <iostream>

#define BULLET_POOL_SIZE 100 // how many bullets can be fired at once

std::vector<Bullet *> ShooterComponent::m_bullets;

ShooterComponent::ShooterComponent()
{
    ReserveBullets();
}

ShooterComponent::~ShooterComponent()
{
    for(Bullet * & bullet : m_instanceBullets)
    {
        bullet->SetOwned(false);
    }
}

void ShooterComponent::InitShooter(GameObjectController & controller)
{
    if (m_bullets.empty())
    {
        //intialising bullets
        m_bullets.reserve(BULLET_POOL_SIZE);
        
        for (int i = 0; i < BULLET_POOL_SIZE; i++)
        {
            Bullet * newBullet = new Bullet();
            controller.Add(newBullet);
            m_bullets.push_back(newBullet);
        }
    }
}

// function to fire a bullet
void ShooterComponent::Fire(float xPos, float yPos, e_CollisionTypes type)
{    
    for (Bullet * & bullet : m_instanceBullets)
    {
        if (!bullet->GetActive())
        {
            bullet->setPos(xPos, yPos);
            bullet->SetActive(true);
            return;
        }
    }
}

void ShooterComponent::ReserveBullets()
{
    int currentIndex = 0;
    
    for (Bullet * & bullet : m_bullets)
    {
        if (!bullet->ReturnOwned())
        {
            m_instanceBullets[currentIndex] = bullet;
            currentIndex++;
            if (currentIndex == BULLET_PER_INSTANCE)
            {
                return;
            }
        }
    }
    
    u_ErrorHandler::ThrowWarning("The amount of bullets assigned has exceeded the bullets that are in the pool");
}



