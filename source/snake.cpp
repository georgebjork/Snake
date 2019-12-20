#include "Snake.h"

Snake::Snake(COORD c) : GameObject("*")
{
    coord = c;
    //The head will always spawn at (15,15) therefore, it must be the head
    if(c.X == 16 && c.Y == 15)
    {
        is_head = true;
    }
    else
    {
        is_head = false;
    }
   
}

//This will return the shape of the object which is needed to print out objects
std::string Snake::getShape()
{
    return GameObject::getShape();
}