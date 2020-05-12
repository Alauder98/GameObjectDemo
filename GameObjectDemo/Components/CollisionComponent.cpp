//
//  Collision.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "CollisionComponent.h"
#include "u_XMLReader.h"
#include "u_ErrorHandler.h"
#include <iostream>

// Function to set collision shape of the object
void CollisionComponent::SetColliderShape(const int collisionShapeID)
{
    for (const Shape& indvShape : m_possibleShapes)
    {
        if (indvShape.ID() == collisionShapeID)
        {
            m_colliderShape = indvShape;
            m_gameShapes.push_back(this);
            return;
        }
    }
    
    u_ErrorHandler::ThrowError("Shape ID does not corrospond with any IDs in Shapes.xml");
}

std::vector<Shape> CollisionComponent::m_possibleShapes;

std::vector<CollisionComponent *> CollisionComponent::m_gameShapes;

CollisionComponent::CollisionComponent()
{
    if (m_possibleShapes.empty())
    {
        m_possibleShapes = u_XMLReader::LoadShapeXML();
    }
}

e_CollisionTypes const CollisionComponent::CheckCollision(){
    
    // For Each on all of the collision shapes with the exception of our shape
    for (CollisionComponent * const other : m_gameShapes)
    {
        if (other != this && other != nullptr)
        {
            // check if our shape intersects the other
            if (GetShape().Shape::CheckIntersection(other->GetShape().Shape::ReturnPoints()))
            {
                return other->getCollisionType();
            }
        }
    }
    
    return e_CollisionTypes::NONE;
}

void CollisionComponent::AddCollisionType(e_CollisionTypes newType){
    m_collisionType = static_cast<e_CollisionTypes>(static_cast<int>(m_collisionType) |
                                                    static_cast<int>(newType));
}

void CollisionComponent::SetShapePos(Vector2 newPos)
{
    m_colliderShape.setPos(newPos);
}

