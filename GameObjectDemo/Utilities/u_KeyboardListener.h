//
//  u_KeyboardListener.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

enum e_Keys
{
    W = 80,
    A = 65,
    S = 83,
    D = 68,
    SPACE = 32,
    X = 88,
    Z = 90
};

class u_KeyboardListener
{
public:
    u_KeyboardListener() = default;
    ~u_KeyboardListener() = default;
    
    static bool GetKey(const e_Keys key);
};
