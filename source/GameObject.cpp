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

void GameObject::setShape(std::string s)
{
    shape = s;
}
//move an object left
bool GameObject::moveLeft()
{
    if (coord.X <= 0)
    {
        coord.X = 0;
        return false;
    }

    else
    {
        coord.X -= 2;
        return true;
    }

    return true;
}
//move and object right
bool GameObject::moveRight()
{
    if (coord.X >= MAX_X)
    {
        coord.X = MAX_X;
        return false;
    }

    else
    {
        coord.X += 2;
        return true;
    }

    return true;
}
//move and object down
bool GameObject::moveDown()
{
    if (coord.Y >= MAX_Y)
    {
        coord.Y = MAX_Y;
        return false;
    }

    else
    {
        coord.Y += 1;
        return true;
    }

    return true;
}
//move and object up
bool GameObject::moveUp()
{
    if (coord.Y <= 0)
    {
        coord.Y = 0;
        return false;
    }

    else
    {
        coord.Y -= 1;
        return true;
    }

    return true;
}