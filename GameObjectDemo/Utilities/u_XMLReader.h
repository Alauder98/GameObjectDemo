//
//  u_XMLReader.h
//  GameObjectDemo
//
//  Created by Alec Lauder on 23/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#pragma once

#include <vector>
#include "Shape.h"
#include "tinyxml2.h"
#include "u_ErrorHandler.h"
#include "GameObjectController.h"

// Class to readaCSV and return a list of shapes
class u_XMLReader
{
public:
    u_XMLReader() = default;
    ~u_XMLReader() = default;
    
    static std::vector<Shape> LoadShapeXML ();
    static void LoadSceneXML (const char* sceneFileName, GameObjectController & list);
};
