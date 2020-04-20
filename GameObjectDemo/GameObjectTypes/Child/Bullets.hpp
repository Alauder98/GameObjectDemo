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
#include "GameObject.hpp"
#include "Collision.hpp"

// Class to create a bullet object
class Bullet: public GameObject, Collision{
public:
    // Constructor
    Bullet();
    ~Bullet();
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void CheckCollision() override;
    
private:
    float lifespan; // the lifespan of this bullet
};

#endif /* Bullets_hpp */
