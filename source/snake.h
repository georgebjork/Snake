#pragma once
#include "GameObject.h"
#include "windows.h"
class Snake : public GameObject {
    public:
        //Default const
        Snake(COORD c);

        //This will return the shape of the object which is needed to print out objects
        std::string getShape();
};