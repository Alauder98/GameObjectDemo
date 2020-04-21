//
//  Shooter.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Shooter_hpp
#define Shooter_hpp

#include <vector>
#include "Bullets.hpp"

// interface to manage shooting of bullets for child class
class Shooter{
public:
    // Constructor / destructor
    Shooter();
    virtual ~Shooter() = default;
    
    // functions
    void Fire(float xPos, float yPos);
    virtual void Shoot() = 0;
    void Update(float deltaTime);
    
private:
    // vector of bullets
    std::unique_ptr<std::vector<std::unique_ptr<Bullet>>> bullets;
};

#endif /* Shooter_hpp */
