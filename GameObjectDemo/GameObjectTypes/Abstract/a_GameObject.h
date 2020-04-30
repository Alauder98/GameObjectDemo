//
//  GameObject.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "Vector2.h"

// Class GameObject
// Abstract class for general gameobejct type
class a_GameObject
{
public:
    // Constuctors
    a_GameObject();
    virtual ~a_GameObject() = default;
    
    // Functions
    virtual void Update(float DeltaTime) = 0;
    virtual void Init() = 0;
    virtual void Render() = 0;
    virtual void SetActive(bool newValue);
    inline bool GetActive() const { return m_isActive; };
    void setPos(float x, float y);
    inline const Vector2 GetPos() const { return m_position; };
    
protected:
    bool m_isActive; // is object active
    Vector2 m_position; // the 2D position of the object
};
