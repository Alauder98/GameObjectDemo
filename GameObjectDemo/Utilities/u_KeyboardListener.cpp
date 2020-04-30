//
//  u_KeyboardListener.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

// TODO OSX implementation

#include "u_KeyboardListener.h"

#ifdef __APPLE__

#elif defined _WIN32 || defined _WIN64
    #include <windows.h>
#endif

// Function to query a key down
bool u_KeyboardListener::GetKey(const e_Keys key)
{
#ifdef __APPLE__
    return true;
#elif defined _WIN32 || defined _WIN64
    return GetAsyncKeyState((int) key);
#endif
}
