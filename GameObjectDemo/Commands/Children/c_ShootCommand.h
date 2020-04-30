//
//  Header.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include "a_Command.h"

class c_ShootCommand: public a_Command
{
public:
    void Execute(a_GameObject & actor);
};
