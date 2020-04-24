//
//  u_errorHandler.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 24/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include <iostream>
#include "u_ErrorHandler.h"

u_ErrorHandler::u_ErrorHandler()
{
    if (s_ErrorHandler != nullptr)
    {
        s_ErrorHandler = new u_ErrorHandler();
    }
}

u_ErrorHandler::~u_ErrorHandler()
{
    if (s_ErrorHandler != nullptr)
    {
        delete s_ErrorHandler;
        s_ErrorHandler = nullptr;
    }
}

const void u_ErrorHandler::ThrowMessage(const std::string& message)
{
    std::cout << "DEBUG: " << message << "\n";
}

const void u_ErrorHandler::ThrowWarning(const std::string& message)
{
    std::cout << "WARNING: " << message << "\n";
}

const void u_ErrorHandler::ThrowError(const std::string& message)
{
    std::cout << "ERROR: " << message << "\n";
    assert(false);
}

