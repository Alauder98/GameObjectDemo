//
//  u_XMLReader.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 23/04/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#include "u_XMLReader.h"
#include "tinyxml2.h"
#include <assert.h>

std::vector<Shape> u_XMLReader::ReadXML()
{
    std::vector<Shape> returnList;
    bool nextChild = true;
    tinyxml2::XMLDocument file;
    
    // Open file and check we have no errors doing so
    file.LoadFile("Shapes.xml");
    assert(!file.Error());
    
    // get the "Shapes tag"
    tinyxml2::XMLElement * shapes =
    file.FirstChildElement( "shapes" );
    
    // Get our first "Shape tag"
    tinyxml2::XMLElement * shape = shapes->FirstChildElement("shape");
    
    // pushing in the first shape
    returnList.push_back(Shape(
    std::stof(shape->FirstChildElement("x")->FirstChild()->Value()),
    std::stof(shape->FirstChildElement("y")->FirstChild()->Value()),
    shape->FirstChildElement("name")->FirstChild()->Value()
                            ));
    
    // loop that will push in subsequent shapes
    while (nextChild)
    {
        shape = shape->NextSiblingElement();
        
        returnList.push_back(Shape(
        std::stof(shape->FirstChildElement("x")->FirstChild()->Value()),
        std::stof(shape->FirstChildElement("y")->FirstChild()->Value()),
        shape->FirstChildElement("name")->FirstChild()->Value()
                                ));
        
        // if we have pushed the last element, stop the loop
        if (shape == shapes->LastChildElement())
        {
            nextChild = false;
        }
    }
    
    return returnList;
}
