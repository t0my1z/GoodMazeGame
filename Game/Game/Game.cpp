// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Public/MazeGame.h"
#include "Public/Factories/MazeConcreteFactory1.h"

int main()
{
    MazeGame* m_mazeGame = new MazeGame();
    MazeBaseFactory* m_mazeFactory = new MazeConcreteFactory1();
    //m_mazeGame->CreateMazeEx12();
    m_mazeGame->CreateMazeEx3(m_mazeFactory, 0);

    std::cin;
}

