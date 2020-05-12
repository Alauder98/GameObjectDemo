//
//  u_XMLReader.cpp
//  GameObjectDemo
//
//  Created by Alec Lauder on 11/05/2020.
//  Copyright © 2020 Alec Lauder. All rights reserved.
//

#define TYPEID_SPACESHIP 1
#define TYPEID_ALIEN 2

#include "u_XMLReader.h"
#include "GameObjectsLibrary.h"
#include "u_DebugMonitor.h"


#include <iostream>

std::vector<Shape> u_XMLReader::LoadShapeXML()
{
    tinyxml2::XMLDocument file;
    static std::vector<Shape> returnList;
    
    // Open file and check we have no errors doing so
    file.LoadFile("XML/Shapes.xml");
    
    // get the "Shapes tag"
    tinyxml2::XMLElement * shapes =
    file.FirstChildElement( "shapes" );
    
    if (shapes == nullptr)
    {
        u_ErrorHandler::ThrowError("Shape XML File Not Found");
    }

    // Get our first "Shape tag"
    tinyxml2::XMLElement * shape = shapes->FirstChildElement("shape");
    
    // loop that will push in subsequent shapes
    while (shape)
    {
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
        else
        {
            shape = shape->NextSiblingElement();
        }
    }
    
    return returnList;
}

void u_XMLReader::LoadSceneXML(const char *sceneFileName, GameObjectController & list)
{
    tinyxml2::XMLDocument file;
    
    // Open file and check we have no errors doing so
    file.LoadFile(sceneFileName);
    
    // get the "Objects tag"
    tinyxml2::XMLElement * objects =
    file.FirstChildElement( "objects" );
    
    if (objects == nullptr)
    {
        u_ErrorHandler::ThrowError("Scene XML File Not Found");
    }
    
    // Get our first "Object tag"
    tinyxml2::XMLElement * object = objects->FirstChildElement("object");
    
    while (object)
    {
        a_GameObject * tempHold = nullptr;
       
        switch (std::stoi(object->FirstChildElement("type")->FirstChild()->Value()))
        {
            case TYPEID_SPACESHIP:
                tempHold = new SpaceShip();
                break;
            case TYPEID_ALIEN:
                tempHold = new Alien();
                break;
            default:
                tempHold = nullptr;
                u_ErrorHandler::ThrowError("Type ID provided is not valid");
        }
        
        tempHold->setPos(std::stof(object->FirstChildElement("x")->FirstChild()->Value()), std::stof(object->FirstChildElement("y")->FirstChild()->Value()));
        list.Add(tempHold);
        
        if (object == object->LastChildElement())
        {
            object = nullptr;
        }
        else
        {
            object = object->NextSiblingElement();
        }
    }
}
