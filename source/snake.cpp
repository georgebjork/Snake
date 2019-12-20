#include "Snake.h"

Snake::Snake(COORD c) : GameObject("*")
{
    coord = c;
}

//This will return the shape of the object which is needed to print out objects
std::string Snake::getShape()
{
    return GameObject::getShape();
}