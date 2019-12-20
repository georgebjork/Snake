#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <vector>
#include "GameObject.h"
#include "Food.h"
#include "Snake.h"
HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

//Vector for all snake objects and food objects
std::vector<GameObject *> snake;
std::vector<GameObject *> food;

//This will draw everything
template <typename T>
void draw(std::vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        //This is basically saying set the console postion to what the coord says and then print it out
        COORD c = v[i]->getCoord();
        SetConsoleCursorPosition(hStdout, c);
        std::cout << v[i]->getShape();
    }
}



void gameLoop()
{
    system("cls");
}

int main()
{
    //Seeding random
    srand(unsigned(time(NULL)));

    //Getting the standard input and output
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);



    return 0;
}