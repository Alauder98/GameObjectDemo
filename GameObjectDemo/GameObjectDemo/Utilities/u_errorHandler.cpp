//
//  u_errorHandler.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 24/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include <iostream>
#include "u_ErrorHandler.h"

void u_ErrorHandler::ThrowMessage(const std::string& message)
{
    std::cout << "DEBUG: " << message << "\n";
}

void u_ErrorHandler::ThrowWarning(const std::string& message)
{
    std::cout << "WARNING: " << message << "\n";
}

void u_ErrorHandler::ThrowError(const std::string& message)
{
    std::cout << "ERROR: " << message << "\n";
    assert(false);
}
