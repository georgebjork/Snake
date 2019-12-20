#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>
#include "GameObject.h"
#include "Food.h"
#include "Snake.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
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

void keyInput()
{
    char key_;
    int ascii_value_;
    int interval = 1000;
    int i = 0;
    while (i < interval)
    {
        if (i < interval && kbhit())
        {

            key_ = _getch();
            ascii_value_ = key_;

            if (ascii_value_ == 75)
            {
                //Move left
                snake[0]->moveLeft();
                break;
            }
            else if (ascii_value_ == 77)
            {
                //Move right
                snake[0]->moveRight();
                break;
            }
            else if (ascii_value_ == 80)
            {
                //Move down
                snake[0]->moveDown();
                break;
            }
            else if (ascii_value_ == 72)
            {
                //Move up
                snake[0]->moveUp();
                break;
            }
        }
    }
}

void checkCollison()
{
    if(*snake[0] == *food[0])
    {
        food.erase(food.begin());
    }
}

//The gameLoop will run here
void gameLoop()
{
    while (true)
    {
        //Clear the screen
        system("cls");

        //Draw everything
        draw(snake);
        draw(food);

        //KeyInput
        keyInput();

        //This will spawn in a new piece of food if there is not piece of food currently
        if(food.size() == 0)
        {
            food.push_back(new Food());
        }

        checkCollison();

        Sleep(50);
    }
}

int main()
{
    //Seeding random
    srand(unsigned(time(NULL)));

    //Getting the standard input and output
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD c;
    c.X = 15;
    c.Y = 15;

    snake.push_back(new Snake(c));

    //This will run the gameLoop
    gameLoop();

    return 0;
}