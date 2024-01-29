#pragma once
#include"BaseRoom.h"
#include <vector>

class Maze
{
private:
	std::vector<BaseRoom*> m_Rooms;

public:
	void AddRoom();
	void AddRoom(Transform pos);

	BaseRoom* RoomNo(int id);
	const int GetMaxNumOfRooms();
};

