//
//  GameObject.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 14/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "a_GameObject.h"

a_GameObject::a_GameObject()
{
    m_isActive = false;
    m_ToDelete = false;
    m_position.Set(0.0f, 0.0f);
}

void a_GameObject::setPos(float x, float y)
{
    m_position.Set(x, y);
}
