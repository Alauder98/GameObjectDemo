//
//  Collision.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <string>
#include "Shape.h"

// forward decleration of class shape
class Shape;

// Class to handle collisions for objects
class i_Collision
{
public:
    // Constructor / Destructor
    i_Collision() = default;
    virtual ~i_Collision() = default;
    
    // Functions
    void SetColliderShape(const std::string& shape);
    virtual void ProcessCollision() = 0;
    bool CheckCollision();
    Shape const returnColliderShape() { return m_colliderShape; };
    
private:
    // the shape of this object
    Shape m_colliderShape;
};

#endif /* Collision_hpp */
