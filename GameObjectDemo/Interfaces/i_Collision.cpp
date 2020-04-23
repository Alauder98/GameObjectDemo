//
//  Collision.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "i_Collision.h"
#include "u_XMLReader.h"
#include <iostream>

// Function to set collision shape of the object
void i_Collision::SetColliderShape(const std::string& collisionShape)
{
    for (Shape indvShape : m_possibleShapes)
    {
        if (indvShape.Name().compare(collisionShape) == 0)
        {
            m_colliderShape = indvShape;
            return;
        }
    }
    
    // if we get past this point, we've provided an invaled name
    std::cout << "Invalid Shape Name provided" << "\n";
}

std::vector<Shape> i_Collision::m_possibleShapes;

i_Collision::i_Collision(e_CollisionTypes collisionType):m_collisionType(collisionType)
{
    if (m_possibleShapes.empty())
    {
        u_XMLReader l_xmlReader;
        m_possibleShapes = l_xmlReader.ReadXML();
    }
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

