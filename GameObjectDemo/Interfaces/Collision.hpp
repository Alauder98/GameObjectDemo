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

// Class to handle collisions for objects
class Collision{
public:
    // Constructor / Destructor
    Collision();
    ~Collision();
    
    // Functions
    void SetColliderShape(std::string shape);
    virtual void CheckCollision() = 0;
    std::string UpdateCollider();
    
private:
    // the shape of this object
    class Shape colliderShape();
};

#endif /* Collision_hpp */
