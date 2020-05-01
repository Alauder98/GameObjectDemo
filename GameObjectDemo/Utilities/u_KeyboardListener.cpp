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
    #include <Carbon/Carbon.h>
#elif defined _WIN32 || defined _WIN64
    #include <windows.h>
#endif

// Function to query a key down
bool u_KeyboardListener::GetKey(const e_Keys key)
{
#ifdef __APPLE__
    // OS X implementation
    unsigned char keyMap[16];
    GetKeys((BigEndianUInt32*) &keyMap);
    return (0 != ((keyMap[ int(key) >> 3] >> (int(key) & 7)) & 1));
#elif defined _WIN32 || defined _WIN64
    // Windows implementation
    return GetAsyncKeyState((int) key);
#endif
}
