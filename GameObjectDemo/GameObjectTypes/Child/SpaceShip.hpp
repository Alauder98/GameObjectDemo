//
//  SpaceShip.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef SpaceShip_hpp
#define SpaceShip_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Shooter.hpp"
#include "Collision.hpp"

// Class to create spaceship
class SpaceShip: public GameObject, Shooter, Collision{
public:
    // Constructor / Destructor
    SpaceShip();
    ~SpaceShip();
    
    // Functions
    void Update(float DeltaTime) override;
    void Render() override;
    void Init() override;
    void Shoot() override;
    void CheckCollision() override;
    void Hit();
    
private:
    int health; // The health of the player
};

#endif /* SpaceShip_hpp */
