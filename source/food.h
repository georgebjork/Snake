#pragma once
#include "GameObject.h"
#include "windows.h"
class Food : public GameObject {
    public:
        //Default const
        Food();
        //This will set the food postion randomly
        void setCoord();
        //This will return the shape of the object which is needed to print out objects
        std::string getShape();
};