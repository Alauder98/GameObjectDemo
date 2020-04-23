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

// Class to readaCSV and return a list of shapes
class u_XMLReader
{
public:
    u_XMLReader() = default;
    ~u_XMLReader() = default;
    
    std::vector<Shape> ReadXML();
};
