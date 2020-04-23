//
//  Collision.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <string>
#include "Shape.h"

enum e_CollisionTypes{
    NONE = 1,
    PLAYER = 2,
    ENEMY = 4,
    BULLET = 8
};

// forward decleration of class shape
class Shape;

// Class to handle collisions for objects
class i_Collision
{
public:
    // Constructor / Destructor
    i_Collision(e_CollisionTypes collisionType);
    virtual ~i_Collision() = default;
    
    // Functions
    void SetColliderShape(const std::string& shape);
    virtual void ProcessCollision(e_CollisionTypes type) = 0;
    e_CollisionTypes const CheckCollision();
    Shape& GetShape() {return m_colliderShape; };
    void AddCollisionType(e_CollisionTypes newType);
    e_CollisionTypes const getCollisionType() {return m_collisionType; };
    
private:
    // the shape of this object
    Shape m_colliderShape;
    e_CollisionTypes m_collisionType;
    static std::vector<Shape> m_possibleShapes;
};
