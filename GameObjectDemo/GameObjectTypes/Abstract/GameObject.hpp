//
//  GameObject.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "Vector2.hpp"

// Class GameObject
// Abstract class for general gameobejct type
class GameObject{
public:
    // Constuctors
    GameObject();
    virtual ~GameObject() = default;
    
    // Functions
    virtual void Update(float DeltaTime) = 0;
    virtual void Init() = 0;
    virtual void Render() = 0;
    void SetActive(bool newValue);
    bool GetActive() const;
    void setPos(float x, float y);
    
protected:
    bool isActive; // is object active
    Vector2 position; // the 2D position of the object
};

#endif /* GameObject_hpp */
