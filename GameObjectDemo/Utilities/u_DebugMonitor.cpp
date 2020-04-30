//
//  u_DebugMonitor.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "u_DebugMonitor.h"
#include <iostream>

int u_DebugMonitor::m_CurrentGameObjects = 0;

float u_DebugMonitor::m_CurrentTimeBetweenFrames = 0.0f;

void u_DebugMonitor::AddGameObject()
{
    m_CurrentGameObjects++;
}

void u_DebugMonitor::RemoveGameObject()
{
    m_CurrentGameObjects--;
}

void u_DebugMonitor::SetFrameTime(float newTime)
{
    m_CurrentTimeBetweenFrames = newTime;
}

void u_DebugMonitor::PrintToConsole()
{
    std::cout << "DEBUG DETAILS:" << std::endl << std::endl
    << "CURRENT OS: " <<
#ifdef __APPLE__
    "MAC OSX" << std::endl
#elif defined _WIN32 || defined _WIN64
    "WINDOWS" << std::endl
#endif
    << "GAMEOBJECTS CURRENTLY LOADED: " << m_CurrentGameObjects << std::endl
    << "TIME BETWEEN FRAMES: " << m_CurrentTimeBetweenFrames << std::endl;
}
