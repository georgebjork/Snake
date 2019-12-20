#pragma once

#include <iostream>
#include <windows.h>

class GameObject {
    protected:
        //This is the coordinates for every gameobject
        COORD coord;
        //This is the shape of the object
        std::string shape;
        //This is how far right an object can go in the coordinate plane
        const int MAX_X = 30;
        //This will be how far down an object can go in the coordinate plane
        const int MAX_Y = 30;

    public:
        //Default const
        GameObject(std::string s);

        //Return the coord of the object
        COORD getCoord();

        //This will set the coord of an object
        void setCoord(COORD c);

        //This will return the shape of the object which is needed to print out objects
        virtual std::string getShape();

        //move and object left
        void moveLeft();
        //move an object right
        void moveRight();
        //move an object down
        void moveDown();
        //move and object up
        void moveUp();

        //We are going to overload the == operator to compare snake coord and food coord
        bool operator == (GameObject &b)
        {
            if(coord.X == b.coord.X && coord.Y == b.coord.Y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};