//
//  Collision.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "i_Collision.h"

// Function to set collision shape of the object
void i_Collision::SetColliderShape(const std::string& collisionShape)
{
    // would parse shape and set accordingly
}

i_Collision::i_Collision(e_CollisionTypes collisionType):m_collisionType(collisionType)
{
}

e_CollisionTypes const i_Collision::CheckCollision(){
    
    //Logic for if another shape intersects this objects shape
    // if we flag a collision get its collision type and return it
    // if not, return null
    
    return m_collisionType;
}

void i_Collision::AddCollisionType(e_CollisionTypes newType){
    m_collisionType = static_cast<e_CollisionTypes>(static_cast<int>(m_collisionType) |
                                                    static_cast<int>(newType));
}

