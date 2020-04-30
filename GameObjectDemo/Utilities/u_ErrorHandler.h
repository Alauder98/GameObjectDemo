//
//  u_ErrorHandler.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 24/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include <string>

class u_ErrorHandler
{
public:
    // Constructor / destructor
    u_ErrorHandler() = default;
    ~u_ErrorHandler() = default;
    
    // Functions
    static void ThrowError(const std::string& message);
    static void ThrowMessage(const std::string& message);
    static void ThrowWarning(const std::string& message);
};


