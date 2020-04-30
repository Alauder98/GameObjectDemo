//
//  u_DebugMonitor.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

class u_DebugMonitor
{
public:
    static void PrintToConsole();
    static void SetFrameTime(float newTime);
    static void AddGameObject();
    static void RemoveGameObject();

private:
    static float m_CurrentTimeBetweenFrames;
    static int m_CurrentGameObjects;
};
