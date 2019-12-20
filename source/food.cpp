#include "Food.h"

Food::Food(COORD c) : GameObject("F")
{
    coord = c;
    setCoord();
}

//Set coord for food
void Food::setCoord()
{
    //Set random X
    coord.X = rand() % (MAX_X - 1) + 1;
    //Set random Y
    coord.Y = rand () % (MAX_Y - 1) + 1;
}

//This will return the shape of the object which is needed to print out objects
std::string Food::getShape()
{
    return GameObject::getShape();
}