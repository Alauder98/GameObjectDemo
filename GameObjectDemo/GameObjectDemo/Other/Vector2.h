//
//  Vector2.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 15/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
// class for a vector that stores x and y values
class Vector2
{
public:
    // constructor and destructor
    explicit Vector2();
    explicit Vector2(float x, float y);
    ~Vector2() = default;
    
    // operator overrides
    inline Vector2 const operator +(const Vector2 & other) ;
    inline Vector2 const operator -(const Vector2 & other);
    inline void operator *(const int multiplier);
    inline void operator /(const int divider);
    bool operator ==(const Vector2& other) const;
    bool operator != (const Vector2 & other);
    
    // return functions
    float x() const {return m_x;}
    float y() const {return m_y;}
    
    // Set function
    void Set(float x, float y);
    
private:
    // x and y values
    float m_x, m_y;
};
