//
//  Vector2.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 15/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Vector2.h"

// Constructor which has passed values (Deafult)
Vector2::Vector2(float newX, float newY):m_x(newX), m_y(newY)
{
}

// constructor for when no values are passed
Vector2::Vector2():m_x(0.0f), m_y(0.0f)
{
}

Vector2 const Vector2::operator +(const Vector2& other)
{
    return Vector2( x() + other.x(), y() + other.y());
}

Vector2 const Vector2::operator-(const Vector2& other)
{
    return Vector2( m_x - other.x(), m_y - other.y());
}

void Vector2::operator*(const int multiplier)
{
    m_x *= multiplier;
    m_y *= multiplier;
}

void Vector2::operator/(const int divider)
{
    m_x /= divider;
    m_y /= divider;
}

bool Vector2::operator==(const Vector2& other) const
{
    return m_x == other.x() && m_y == other.y();
}

void Vector2::Set(float x, float y)
{
    m_x = x;
    m_y = y;
}

bool Vector2::operator!=(const Vector2& other)
{
    return !(* this == other);
}
