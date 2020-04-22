//
//  Shape.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 22/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

// Class to store a shape
class Shape{
public:
    // Constructors / destructors
    Shape();
    Shape(float x, float y);
    ~Shape() = default;
    
    // Functions
    float const x() { return m_xWidth; };
    float const y() { return m_yHeight; };
    
private:
    // x and y height
    float m_yHeight;
    float m_xWidth;
};

#endif /* Shape_h */
