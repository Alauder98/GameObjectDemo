//
//  Collision.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "i_Collision.h"
#include "u_XMLReader.h"
#include "u_ErrorHandler.h"
#include <iostream>

// Function to set collision shape of the object
void i_Collision::SetColliderShape(const std::string& collisionShape)
{
    for (const Shape& indvShape : m_possibleShapes)
    {
        if (indvShape.Name().compare(collisionShape) == 0)
        {
            m_colliderShape = indvShape;
            m_gameShapes.push_back(this);
            return;
        }
    }
    
    ErrorHandler->ThrowError("Invalid shape name provided");
}

std::vector<Shape> i_Collision::m_possibleShapes;

std::vector<i_Collision *> i_Collision::m_gameShapes;

i_Collision::i_Collision(e_CollisionTypes collisionType):m_collisionType(collisionType)
{
    if (m_possibleShapes.empty())
    {
        u_XMLReader l_xmlReader;
        m_possibleShapes = l_xmlReader.ReadXML();
    }
}

e_CollisionTypes const i_Collision::CheckCollision(){
    
    // For Each on all of the collision shapes with the exception of our shape
    for (i_Collision * const other : m_gameShapes)
    {
        if (other != this && other != nullptr)
        {
            // would compare intersection rather than position
            if (GetPos() == other->GetPos())
            {
                return other->getCollisionType();
            }
        }
    }
    
    return e_CollisionTypes::NONE;
}

void i_Collision::AddCollisionType(e_CollisionTypes newType){
    m_collisionType = static_cast<e_CollisionTypes>(static_cast<int>(m_collisionType) |
                                                    static_cast<int>(newType));
}

void i_Collision::SetShapePos(Vector2 newPos)
{
    m_colliderShape.setPos(newPos);
}

