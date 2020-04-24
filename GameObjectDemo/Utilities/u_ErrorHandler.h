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
    u_ErrorHandler();
    ~u_ErrorHandler();
    
    
    const void ThrowError(const std::string& message);
    const void ThrowMessage(const std::string& message);
    const void ThrowWarning(const std::string& message);
};

static u_ErrorHandler * ErrorHandler;
