//
//  Collision.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <string>

// forward decleration of class shape
class Shape;

// Class to handle collisions for objects
class Collision{
public:
    // Constructor / Destructor
    Collision() = default;
    virtual ~Collision() = default;
    
    // Functions
    void SetColliderShape(const std::string& shape);
    virtual void CheckCollision() = 0;
    std::string UpdateCollider();
    
private:
    // the shape of this object
    Shape colliderShape();
};

#endif /* Collision_hpp */
