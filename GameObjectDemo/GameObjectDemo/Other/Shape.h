//
//  Shape.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 22/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include <string>
#include "Vector2.h"

// struct to store 4 points of shpae
struct PointsPos {
    Vector2 m_LT;
    Vector2 m_RB;
};

// Class to store a shape
class Shape{
public:
    // Constructors / destructors
    Shape();
    Shape(float x, float y, std::string name);
    ~Shape() = default;
    
    // Functions
    inline float const X() { return m_xWidth; };
    inline float const Y() { return m_yHeight; };
    inline std::string Name() const { return m_name; };
    void setPos(Vector2 newPos);
    inline const Vector2 GetPos() { return m_position; };
    void UpdatePoints();
    bool CheckIntersection(const PointsPos& other) const;
    inline PointsPos ReturnPoints() const { return points; } ;
    
private:
    // x and y height
    float m_yHeight;
    float m_xWidth;
    Vector2 m_position;
    std::string m_name;
    PointsPos points;
    
};
