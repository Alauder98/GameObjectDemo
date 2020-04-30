//
//  u_KeyboardListener.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

// This file is windows only
// TODO OSX implementation

#include "u_KeyboardListener.h"
//#include <windows.h>

// Function to query a key down
bool u_KeyboardListener::GetKey(const e_Keys key)
{
    return true;
    //return GetAsyncKeyState((int) key);
}
