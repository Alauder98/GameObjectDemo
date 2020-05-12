//
//  Shooter.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#define BULLET_PER_INSTANCE 5 // how many bullets can be owned per instance

#include <vector>
#include "Bullets.h"

// forward declerations
class GameObjectController;

// interface to manage shooting of bullets for child class
class ShooterComponent
{
public:
    // Constructor / destructor
    ShooterComponent();
    ~ShooterComponent();
    
    // functions
    void Fire(float xPos, float yPos, e_CollisionTypes collisionType);
    static void InitShooter(GameObjectController& controller);
    void ReserveBullets();
    
private:
    // vector of bullets
    static std::vector<Bullet *> m_bullets;
    Bullet* m_instanceBullets[BULLET_PER_INSTANCE];
};
