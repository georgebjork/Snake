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

int last_movement;
bool is_alive = true;

HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

//Vector for all snake objects and food objects
std::vector<GameObject *> snake;
std::vector<GameObject *> food;

// Function to hide the console cursor
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

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

bool keyInput()
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
                last_movement = ascii_value_;
                return true;
            }
            else if (ascii_value_ == 77)
            {
                //Move right
                snake[0]->moveRight();
                last_movement = ascii_value_;
                return true;
            }
            else if (ascii_value_ == 80)
            {
                //Move down
                snake[0]->moveDown();
                last_movement = ascii_value_;
                return true;
            }
            else if (ascii_value_ == 72)
            {
                //Move up
                snake[0]->moveUp();
                last_movement = ascii_value_;
                return true;
            }
        }

        else if (interval == 1000)
        {
            i = 0;
            return false;
        }

        else
        {
            i++;
        }
    }

    return false;
}

//This will move the snake if no inputs are made
void forceMove(int lm)
{
    if (lm == 75)
    {
        if (snake[0]->moveLeft() == false)
        {
            is_alive = false;
        }
    }
    else if (lm == 77)
    {
        if (snake[0]->moveRight() == false)
        {
            is_alive = false;
        }
    }
    else if (lm == 80)
    {
        if (snake[0]->moveDown() == false)
        {
            is_alive = false;
        }
    }
    else if (lm == 72)
    {
        if (snake[0]->moveUp() == false)
        {
            is_alive = false;
        }
    }
}

void moveBody()
{
    for (int i = snake.size() - 1; i > 0; i--)
    {
        snake[i]->setCoord(snake[i - 1]->getCoord());
    }
}

//This will compare the coordinates of the two objects to see if they are the same
void checkCollisonFood()
{
    if (*snake[0] == *food[0])
    {
        food.erase(food.begin());
    }
}

//This will create a new piece of snake to the very end
void newSnake()
{
    COORD c;
    int i = snake.size() - 1;
    //Get the tail coord
    c = snake[i]->getCoord();
    c.X += 1;
    snake.push_back(new Snake(c, "o"));
}

void endGame()
{
    for(int i = 0; i < snake.size(); i++)
    {
        snake[i]->setShape("x");
    }
    system("cls");
    draw(snake);
}

void checkCollisonSelf()
{
    for(int i = 1; i < snake.size(); i++)
    {
        if(*snake[0] == *snake[i])
        {
            is_alive = false;
        }
    }
}

//The gameLoop will run here
void gameLoop()
{

    int count = 0;
    ShowConsoleCursor(false);
    while (true)
    {
        //Clear the screen
        system("cls");

        //Draw everything
        draw(snake);
        draw(food);

        //This will move the body of the snake
        if (snake.size() > 1)
        {
            moveBody();
        }

        //KeyInput
        if (keyInput() == false)
        {
            //Force the snake to move if there are no inputs
            forceMove(last_movement);
        }

        //This will spawn in a new piece of food if there is not piece of food currently
        if (food.size() == 0)
        {
            food.push_back(new Food());
            if (count > 0)
            {
                newSnake();
            }
        }

        //This will check collison with food
        checkCollisonFood();

        //This will check collison with its self
        checkCollisonSelf();

        if(is_alive == false)
        {
            break;
        }

        Sleep(50);

        count++;
    }

    endGame();

}

int main()
{
    //Seeding random
    srand(unsigned(time(NULL)));

    //Getting the standard input and output
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD c;
    c.X = 16;
    c.Y = 15;

    snake.push_back(new Snake(c, "0"));

    //This will run the gameLoop
    gameLoop();

    return 0;
}