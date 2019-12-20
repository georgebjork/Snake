#include "Food.h"

Food::Food() : GameObject("F")
{
    setCoord();
}

//Set coord for food
void Food::setCoord()
{
    //Set random X thats an even number
    while(true)
    {
        coord.X = rand() % (MAX_X - 1) + 1;
        //Check to see if its an even number
        if(coord.X % 2 == 0){break;}
        else{}
    }
    
    //Set random Y
    coord.Y = rand () % (MAX_Y - 1) + 1;
}

//This will return the shape of the object which is needed to print out objects
std::string Food::getShape()
{
    return GameObject::getShape();
}