// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Public/MazeGame.h"
#include "Public/Factories/MazeConcreteFactory1.h"
#include "Public/Factories/MazeConcreteFactory2.h"
#include "Public/Builders/MazeConcreteBuilder1.h"
#include "Public/Builders/MazeConcreteBuilder2.h"

int main()
{
    MazeGame* m_mazeGame = new MazeGame();

    //m_mazeGame->CreateMazeEx12();
    //m_mazeGame->CreateMazeEx3(m_mazeConcreteFactory1, 0);
    //m_mazeGame->CreateMazeEx3(m_mazeConcreteFactory2, 10);

    MazeBuilderBase* m_mazeConcreteBuilder1 = new MazeConcreteBuilder1(0, new MazeConcreteFactory1());
    MazeBuilderBase* m_mazeConcreteBuilder2 = new MazeConcreteBuilder1(20, new MazeConcreteFactory2());
    MazeBuilderBase* m_mazeConcreteBuilder3 = new MazeConcreteBuilder2(10, new MazeConcreteFactory1());
    MazeBuilderBase* m_mazeConcreteBuilder4 = new MazeConcreteBuilder2(30, new MazeConcreteFactory2());

    m_mazeGame->CreateMazeEx4(m_mazeConcreteBuilder1);
    m_mazeGame->CreateMazeEx4(m_mazeConcreteBuilder2);
    m_mazeGame->CreateMazeEx4(m_mazeConcreteBuilder3);
    m_mazeGame->CreateMazeEx4(m_mazeConcreteBuilder4);
    
    std::cin;
}

