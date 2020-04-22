//
//  SpaceShip.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef SpaceShip_hpp
#define SpaceShip_hpp

#include "a_GameObject.hpp"
#include "i_Shooter.hpp"
#include "i_Collision.hpp"

// Class to create spaceship
class SpaceShip: public a_GameObject, i_Shooter, i_Collision
{
public:
    // Constructor / Destructor
    SpaceShip();
    ~SpaceShip() = default;
    
    // Functions
    void Update(float DeltaTime) override;
    void Render() override;
    void Init() override;
    void Shoot() override;
    void ProcessCollision() override;
    void Hit();
    
private:
    int m_health; // The health of the player
};

#endif /* SpaceShip_hpp */
