//
//  Clock.hpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#ifndef Clock_hpp
#define Clock_hpp

#include <stdio.h>

// class to manage a clock to calcualte frame time
class Clock{
public:
    // constructor / destructor
    Clock();
    ~Clock();
    
    // functions
    void Tick();
    float GetTime();
    void Start();
    
private:
    int freqeuncy; // how often the clock is called
    int start; // when we started
    int end; // when we are called
    float elapsedTime; // how long has elapesed between calls
};

#endif /* Clock_hpp */
