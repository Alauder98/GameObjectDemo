//
//  Vector2.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 15/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp

// class for a vector that stores x and y values
class Vector2
{
public:
    // constructor and destructor
    Vector2();
    Vector2(float x, float y);
    ~Vector2() = default;
    
    // operator overrides
    inline Vector2 operator +(const Vector2 & other) const;
    inline Vector2 operator -(const Vector2 & other) const;
    inline void operator *(const int multiplier);
    inline void operator /(const int divider);
    
    // return functions
    float x() const {return m_x;}
    float y() const {return m_y;}
    
    // Set function
    void Set(float x, float y);
    
private:
    // x and y values
    float m_x, m_y;
};

#endif /* Vector2_hpp */
