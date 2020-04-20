//
//  Vector2.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 15/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>

// class for a vector that stores x and y values
class Vector2{
public:
    // constructor and destructor
    Vector2();
    Vector2(float x, float y);
    ~Vector2();
    
    // operator overrides
    inline Vector2 operator +(const Vector2 & other) const;
    inline Vector2 operator -(const Vector2 & other) const;
    inline void operator *(const int multiplier);
    inline void operator /(const int divider);
    
    // return functions
    int x() const {return _x;}
    int y() const {return _y;}
    
private:
    // x and y values
    float _x, _y;
};

#endif /* Vector2_hpp */
