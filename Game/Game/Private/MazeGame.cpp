#include "../Public/MazeGame.h"
#include <iostream>
#include <windows.h>

MazeGame::MazeGame()
    :
    m_Maze(new Maze())
{

}

void MazeGame::CreateMazeEx12()
{
    //Create list of MazeElements
    std::vector<MazeElement*> MazeElements;

    //Create 8 hardcoded walls :D
    MazeElements.push_back(new BaseWall({ 1,0 }));
    MazeElements.push_back(new BaseWall({ 1,1 }));
    MazeElements.push_back(new BaseWall({ 1,2 }));
    MazeElements.push_back(new BaseWall({ 2,0 }));
    MazeElements.push_back(new BaseWall({ 2,2 }));
    MazeElements.push_back(new BaseWall({ 3,0 }));
    MazeElements.push_back(new BaseWall({ 3,2 }));
    MazeElements.push_back(new BaseWall({ 4,0 }));
    MazeElements.push_back(new BaseWall({ 4,2 }));
    MazeElements.push_back(new BaseWall({ 5,0 }));
    MazeElements.push_back(new BaseWall({ 5,2 }));
    MazeElements.push_back(new BaseWall({ 6,0 }));
    MazeElements.push_back(new BaseWall({ 6,1 }));
    MazeElements.push_back(new BaseWall({ 6,2 }));

    //Create 1 hardcoded door :D
    MazeElements.push_back(new BaseDoor({ 3, 1 }));

    //Create 2 Rooms
    m_Maze->AddRoom({ 2,1 });
    m_Maze->AddRoom({ 5,1 });

    //Add each created room to our MazeElement list
    if (m_Maze->GetMaxNumOfRooms() > 0)
    {
        for (size_t i = 0; i < m_Maze->GetMaxNumOfRooms(); i++)
        {
            MazeElements.push_back(m_Maze->RoomNo(i));
        }
    }

    PrintMaze(MazeElements);
}

void MazeGame::CreateMazeEx3(MazeBaseFactory* factory, short offset)
{
    std::vector<MazeElement*> MazeElements;
    //Add walls
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 1),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 1),1 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 1),2 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 2),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 2),2 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 3),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 3),2 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 4),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 4),2 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 5),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 5),2 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 6),0 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 6),1 }));
    MazeElements.push_back(factory->AddWall({ static_cast<short>(offset + 6),2 }));
    //Add door
    MazeElements.push_back(factory->AddDoor({ static_cast<short>(offset + 3),1 }));
    //Add rooms
    MazeElements.push_back(factory->AddRoom({ static_cast<short>(offset + 2),1 }));
    MazeElements.push_back(factory->AddRoom({ static_cast<short>(offset + 5),1 }));
    //Print Maze
    PrintMaze(MazeElements);
}

void MazeGame::CreateMazeEx4(MazeBuilderBase*& builder)
{
    std::vector<MazeElement*> MazeElements = builder->CreateMaze();

    PrintMaze(MazeElements);
}

void MazeGame::PrintMaze(std::vector<MazeElement*>& MazeElements)
{
    for (size_t i = 0; i < MazeElements.size(); i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MazeElements[i]->GetTransform().GetScreenPos());

        std::cout << MazeElements[i]->GetVisual() << std::endl;
    }
}