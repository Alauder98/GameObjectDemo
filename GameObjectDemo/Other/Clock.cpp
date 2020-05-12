//
//  Clock.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Clock.h"
#include <assert.h>

Clock::Clock(){
    Reset();
    m_timeScale = 1.0f;
    m_deltaTime = std::chrono::duration<float>(0.0f);
}

void Clock::Reset()
{
    m_startTime = std::chrono::system_clock::now();
}

void Clock::TimeScale(float t /* = 1.0f */)
{
    m_timeScale = t;
}

void Clock::Tick()
{
    m_deltaTime = std::chrono::system_clock::now() - m_startTime;
    assert(m_deltaTime > (std::chrono::duration<float>)0.0f);
}




