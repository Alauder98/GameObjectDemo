//
//  h_InputHandler.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "h_InputHandler.h"

h_InputHandler::h_InputHandler()
{
    m_Key_D = m_Key_W = m_Key_X = m_Key_Z = m_Key_A = m_Key_S = m_Key_Space = nullptr;
}

h_InputHandler::~h_InputHandler()
{
    if (m_Key_Space) {delete m_Key_Space;}
    if (m_Key_S) {delete m_Key_S;}
    if (m_Key_A) {delete m_Key_A;}
    if (m_Key_Z) {delete m_Key_Z;}
    if (m_Key_X) {delete m_Key_X;}
    if (m_Key_W) {delete m_Key_W;}
    if (m_Key_D) {delete m_Key_D;}
    
    m_Key_D = m_Key_W = m_Key_X = m_Key_Z = m_Key_A = m_Key_S = m_Key_Space = nullptr;
}

a_Command * h_InputHandler::HandleInput()
{
    // attempt key, if true, execute input, ordered based on priority
    if (u_KeyboardListener::GetKey(SPACE)) { return m_Key_Space; }
    else if (u_KeyboardListener::GetKey(X)) { return m_Key_X; }
    else if (u_KeyboardListener::GetKey(Z)) { return m_Key_Z; }
    else if (u_KeyboardListener::GetKey(W)) { return m_Key_W; }
    else if (u_KeyboardListener::GetKey(A)) { return m_Key_A; }
    else if (u_KeyboardListener::GetKey(S)) { return m_Key_S; }
    else if (u_KeyboardListener::GetKey(D)) { return m_Key_D; }
    
    // if none return a nullptr
    return nullptr;
}

bool h_InputHandler::SetInput(e_Keys key, a_Command * command)
{
    // set details for the key we've passed
    switch(key)
    {
        case X:
            m_Key_X = command;
            return true;
        case Z:
            m_Key_Z = command;
            return true;
        case W:
            m_Key_W = command;
            return true;
        case A:
            m_Key_A = command;
            return true;
        case S:
            m_Key_S = command;
            return true;
        case D:
            m_Key_D = command;
            return true;
        case SPACE:
            m_Key_Space = command;
            return true;
    }
    
    // If we haven't set a key return false
    return false;
}
