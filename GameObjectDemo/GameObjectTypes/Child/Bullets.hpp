//
//  Bullets.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Bullets_hpp
#define Bullets_hpp

#include <stdio.h>
#include "a_GameObject.hpp"
#include "i_Collision.hpp"

// Class to create a bullet object
class Bullet: public a_GameObject, i_Collision
{
public:
    // Constructor
    Bullet();
    ~Bullet() = default;
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void ProcessCollision() override;
    void SetActive(bool newValue) override;
    
private:
    float m_lifespan; // the lifespan of this bullet
};

#endif /* Bullets_hpp */
