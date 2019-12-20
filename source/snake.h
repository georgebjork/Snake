#pragma once
#include "GameObject.h"
#include "windows.h"
class Snake : public GameObject {
    private:
        bool is_head;
    public:
        //Default const
        Snake(COORD c, std::string s);

        //This will return the shape of the object which is needed to print out objects
        std::string getShape();
};