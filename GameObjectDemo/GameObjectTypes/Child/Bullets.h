//
//  Bullets.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "a_GameObject.h"
#include "CollisionComponent.h"

// Class to create a bullet object
class Bullet: public a_GameObject
{
public:
    // Constructor
    Bullet();
    ~Bullet() = default;
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void ProcessCollision(e_CollisionTypes type);
    void SetActive(bool newValue);
    inline bool ReturnOwned() const { return m_currentlyOwned; };
    void SetOwned(bool newOwnedValue);
    
private:
    float m_lifespan; // the lifespan of this bullet
    CollisionComponent m_collisionComponent;
    bool m_currentlyOwned;
};
