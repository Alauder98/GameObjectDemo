//
//  Clock.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <chrono>

// class to manage a clock to calcualte frame time
class Clock
{
public:
    // constructor / destructor
    Clock();
    ~Clock() = default;
    
    // functions
    void Tick();
    inline float GetDeltaTime() const { return m_deltaTime.count(); } ;
    void Reset();
    void TimeScale (float t = 1.0f);
    inline float GetTimeScale() const { return m_timeScale; } ;
    
private:
    std::chrono::system_clock::time_point m_startTime;
    std::chrono::duration<float> m_deltaTime;
    float m_timeScale;
    
    
};
