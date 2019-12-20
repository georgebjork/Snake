#include "GameObject.h"

//Default const
GameObject::GameObject(std::string s)
{
    shape = s;
}

//This will return the coord of the object
COORD GameObject::getCoord()
{
    return coord;
}

//This will return the shape of the object which is needed to print out objects
std::string GameObject::getShape()
{
    return shape;
}