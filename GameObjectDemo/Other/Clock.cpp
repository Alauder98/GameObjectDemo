//
//  Clock.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 16/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "Clock.hpp"

// deafult constuctor
Clock::Clock(){}

// destructor
Clock::~Clock(){}

// Move timer along based on when called
void Clock::Tick(){
  // Calculations
}

// return time
float Clock::GetTime(){
    return elapsedTime;
}

// Function called upon starting clock, define start time
void Clock::Start(){
    
}