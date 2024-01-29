#include "../Public/MazeGame.h"
#include <iostream>
#include <windows.h>

MazeGame::MazeGame()
    :
    m_Maze(new Maze()),
    m_Doors(),
    m_Walls()
{

}

void MazeGame::CreateMazeEx12()
{
    //Create 8 hardcoded walls :D
    m_Walls.push_back(new BaseWall({ 1,0 }));
    m_Walls.push_back(new BaseWall({ 1,1 }));
    m_Walls.push_back(new BaseWall({ 1,2 }));
    m_Walls.push_back(new BaseWall({ 2,0 }));
    m_Walls.push_back(new BaseWall({ 2,2 }));
    m_Walls.push_back(new BaseWall({ 3,0 }));
    m_Walls.push_back(new BaseWall({ 3,2 }));
    m_Walls.push_back(new BaseWall({ 4,0 }));
    m_Walls.push_back(new BaseWall({ 4,2 }));
    m_Walls.push_back(new BaseWall({ 5,0 }));
    m_Walls.push_back(new BaseWall({ 5,2 }));
    m_Walls.push_back(new BaseWall({ 6,0 }));
    m_Walls.push_back(new BaseWall({ 6,1 }));
    m_Walls.push_back(new BaseWall({ 6,2 }));

    //Create 1 hardcoded door :D
    m_Doors.push_back(new BaseDoor({ 3, 1 }));

    //Create 2 Rooms
    m_Maze->AddRoom({ 2,1 });
    m_Maze->AddRoom({ 5,1 });

    //Create list of MazeElements
    std::vector<MazeElement*> MazeElements;

    //Add each created floor to our MazeElement list
    if (m_Doors.size() > 0)
    {
        for (size_t i = 0; i < m_Doors.size(); i++)
        {
            MazeElements.push_back(m_Doors[i]);
        }
    }
    //Add each created wall to our MazeElement list
    if (m_Walls.size() > 0)
    {
        for (size_t i = 0; i < m_Walls.size(); i++)
        {
            MazeElements.push_back(m_Walls[i]);
        }
    }
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

void MazeGame::CreateMazeEx3(MazeBaseFactory*& factory, short offset)
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
    MazeElements.push_back(factory->AddDoor({ 3, 1 }));
    //Add walls
    MazeElements.push_back(factory->AddRoom({ 2,1 }));
    MazeElements.push_back(factory->AddRoom({ 5,1 }));
    //Print Maze
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