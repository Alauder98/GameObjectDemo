//
//  Collision.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#define TAG_PLAYER 2
#define TAG_ENEMY 4
#define TAG_PLAYER_BULLET 10
#define TAG_ENEMY_BULLET 12

#include <string>
#include "Shape.h"

enum e_CollisionTypes{
    NONE = 1 << 0,
    PLAYER = 1 << 1,
    ENEMY = 1 << 2,
    BULLET = 1 << 3
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
    void SetColliderShape(const int shape);
    virtual void ProcessCollision(e_CollisionTypes type) = 0;
    e_CollisionTypes const CheckCollision();
    inline const Shape GetShape() const {return m_colliderShape; };
    void SetShapePos(Vector2 newPos);
    void AddCollisionType(e_CollisionTypes newType);
    inline e_CollisionTypes getCollisionType() const {return m_collisionType; };
    inline const Vector2 GetPos() const { return m_colliderShape.GetPos(); };
    
private:
    // the shape of this object
    Shape m_colliderShape;
    e_CollisionTypes m_collisionType;
    static std::vector<Shape> m_possibleShapes;
    static std::vector<i_Collision *> m_gameShapes;
};
