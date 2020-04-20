//
//  Vector2.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 15/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Vector2.hpp"

// Constructor which has passed values (Deafult)
Vector2::Vector2(float newX, float newY)
{
    _x = newX;
    _y = newY;
}

// constructor for when no values are passed
Vector2::Vector2(){
    _x = _y = 0;
}

// Destructor
Vector2::~Vector2(){}

// + operator
Vector2 Vector2::operator +(const Vector2& other) const{
    return Vector2( x() + other.x(), y() + other.y());
}

// - opertaor
Vector2 Vector2::operator-(const Vector2& other) const{
    return Vector2( _x - other.x(), _y - other.y());
}

// * operator
void Vector2::operator*(const int multiplier){
    _x *= multiplier;
    _y *= multiplier;
}

// / operator
void Vector2::operator/(const int divider){
    _x /= divider;
    _y /= divider;
}
