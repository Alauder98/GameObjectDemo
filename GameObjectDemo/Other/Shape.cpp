//
//  Shape.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 22/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include <stdio.h>
#include "Shape.h"

// constructor for passed arguments
Shape::Shape(float x, float y, int newID):
m_xWidth(x), m_yHeight(y), m_id(newID), m_position(Vector2(0,0))
{
}

void Shape::setPos(Vector2 newPos)
{
    m_position = newPos;
    UpdatePoints();
}

void Shape::UpdatePoints()
{
    // generate each point in our square
    points.m_LT = Vector2(m_position.x() * (m_xWidth * -1), m_position.y() * m_yHeight);
    points.m_RB = Vector2(m_position.x() * m_xWidth, m_position.y() * (m_yHeight * -1));
}

bool Shape::CheckIntersection(const PointsPos& other) const
{
    // If one rectangle is on left side of other
    if (points.m_LT.x() >= other.m_RB.x() || other.m_LT.x() >= points.m_RB.x())
    {
        return false;
    }
    
      // If one rectangle is above other
    if (points.m_LT.y() <= other.m_RB.y() || other.m_LT.y() <= points.m_RB.y())
    {
        return false;
    }
    return true;
}

