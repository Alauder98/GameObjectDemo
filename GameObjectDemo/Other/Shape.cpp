//
//  Shape.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 22/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include <stdio.h>
#include "Shape.h"

// constructor for no provided arguments
Shape::Shape():m_yHeight(0.0f),m_xWidth(0.0f),m_name("NULL")
{
}

// constructor for passed arguments
Shape::Shape(float x, float y, std::string newName)
{
    m_xWidth = x;
    m_yHeight = y;
    m_name = newName;
}

void Shape::setPos(Vector2 newPos)
{
    m_position = newPos;
}
