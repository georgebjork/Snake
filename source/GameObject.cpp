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

//This will set the coord of an object
void GameObject::setCoord(COORD c)
{
    coord = c;
}

//This will return the shape of the object which is needed to print out objects
std::string GameObject::getShape()
{
    return shape;
}
//move an object left
void GameObject::moveLeft()
{
    if (coord.X <= 0)
    {
        coord.X = 0;
    }

    else
    {
        coord.X -= 2;
    }
}
//move and object right
void GameObject::moveRight()
{
    if (coord.X >= MAX_X)
    {
        coord.X = MAX_X;
    }

    else
    {
        coord.X += 2;
    }
}
//move and object down
void GameObject::moveDown()
{
    if (coord.Y >= MAX_Y)
    {
        coord.Y = MAX_Y;
    }

    else
    {
        coord.Y += 1;
    }
}
//move and object up
void GameObject::moveUp()
{
    if (coord.Y <= 0)
    {
        coord.Y = 0;
    }

    else
    {
        coord.Y -= 1;
    }
}