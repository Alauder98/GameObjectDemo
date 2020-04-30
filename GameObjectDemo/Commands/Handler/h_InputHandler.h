//
//  h_InputHandler.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "a_Command.h"
#include "u_KeyboardListener.h"

class h_InputHandler
{
public:
    h_InputHandler();
    ~h_InputHandler();
    a_Command* HandleInput();
    
    bool SetInput(e_Keys key, a_Command * command);

private:
    a_Command * m_Key_W, * m_Key_A, * m_Key_S, * m_Key_D,
    * m_Key_Z, * m_Key_X, * m_Key_Space;
};
