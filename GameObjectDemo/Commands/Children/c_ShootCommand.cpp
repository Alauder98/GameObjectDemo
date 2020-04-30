//
//  c_ShootCommand.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 30/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "c_ShootCommand.h"
#include "SpaceShip.h"

void c_ShootCommand::Execute(a_GameObject & actor)
{
    SpaceShip & newActor = (SpaceShip &) actor;
    
    newActor.Shoot();
}
