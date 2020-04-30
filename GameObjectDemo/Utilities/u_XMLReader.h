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

#include <iostream>

template <typename T>
// Class to readaCSV and return a list of shapes
class u_XMLReader
{
public:
    u_XMLReader() = default;
    ~u_XMLReader() = default;
    
    const std::vector<T>& ReadXML() const;
};

template <typename T>
const std::vector<T>& u_XMLReader<T>::ReadXML() const
{
    tinyxml2::XMLDocument file;
    static std::vector<T> returnList;
    
    // parse which type we want
    if (typeid(T) == typeid(Shape)) { LoadShapeXML(file, returnList); }
    
    return returnList;
}

// function for loading shape xml
void LoadShapeXML(tinyxml2::XMLDocument & file, std::vector<Shape>& returnList)
{
    // Open file and check we have no errors doing so
    file.LoadFile("Shapes.xml");
    
    // get the "Shapes tag"
    tinyxml2::XMLElement * shapes =
    file.FirstChildElement( "shapes" );
    
    if (shapes == nullptr)
    {
        u_ErrorHandler::ThrowError("FileNotFound");
    }

    // Get our first "Shape tag"
    tinyxml2::XMLElement * shape = shapes->FirstChildElement("shape");
    
    // pushing in the first shape
    returnList.push_back(Shape(
    std::stof(shape->FirstChildElement("x")->FirstChild()->Value()),
    std::stof(shape->FirstChildElement("y")->FirstChild()->Value()),
    std::stoi(shape->FirstChildElement("id")->FirstChild()->Value())
                            ));
    
    // loop that will push in subsequent shapes
    while (shape)
    {
        shape = shape->NextSiblingElement();
        
        returnList.push_back(Shape(
        std::stof(shape->FirstChildElement("x")->FirstChild()->Value()),
        std::stof(shape->FirstChildElement("y")->FirstChild()->Value()),
        std::stoi(shape->FirstChildElement("id")->FirstChild()->Value())
                                ));
        
        // if we have pushed the last element, stop the loop
        if (shape == shapes->LastChildElement())
        {
            shape = nullptr;
        }
    }
}
