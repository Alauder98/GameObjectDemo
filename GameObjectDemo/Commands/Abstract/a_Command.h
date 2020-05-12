//
//  Command.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once
#include "a_GameObject.h"

class a_Command
{
public:
    a_Command() = default;
    virtual ~a_Command() = default;
    
    virtual void Execute(a_GameObject * actor) = 0;
};
