//
//  Shape.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 22/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include "Vector2.h"

// Class to store a shape
class Shape{
public:
    // Constructors / destructors
    Shape();
    Shape(float x, float y);
    ~Shape() = default;
    
    // Functions
    float const X() { return m_xWidth; };
    float const Y() { return m_yHeight; };
    void setPos(Vector2 newPos);
    
private:
    // x and y height
    float m_yHeight;
    float m_xWidth;
    Vector2 m_position;
    
};
