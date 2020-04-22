//
//  Clock.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
// class to manage a clock to calcualte frame time
class Clock
{
public:
    // constructor / destructor
    Clock() = default;
    ~Clock() = default;
    
    // functions
    void Tick();
    float GetTime() const;
    void Start();
    
private:
    int m_freqeuncy; // how often the clock is called
    int m_start; // when we started
    int m_end; // when we are called
    float m_elapsedTime; // how long has elapesed between calls
};
