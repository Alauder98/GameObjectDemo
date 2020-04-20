//
//  Alien.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Shooter.hpp"
#include "Collision.hpp"

// Class to create alien object
class Alien: public GameObject, Shooter, Collision{
public:
    // Constructor / destructor
    Alien();
    ~Alien();
    
    // Functions
    void Update(float deltaTime) override;
    void Render() override;
    void Init() override;
    void Shoot() override;
    void CheckCollision() override;
};

#endif /* Alien_hpp */
