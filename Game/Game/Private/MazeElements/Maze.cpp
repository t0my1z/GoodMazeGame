#include "../../Public/MazeElements/Maze.h"

void Maze::AddRoom()
{
	m_Rooms.push_back(new BaseRoom(" "));
}

void Maze::AddRoom(Transform pos)
{
	m_Rooms.push_back(new BaseRoom(" ", pos));
}



BaseRoom* Maze::RoomNo(int id)
{
	if (m_Rooms[id])
	{
		return m_Rooms[id];
	}
	else return nullptr;
}

const int Maze::GetMaxNumOfRooms()
{
	if (m_Rooms.size() > 0)
	{
		return m_Rooms.size();
	}
	else return 0;
}