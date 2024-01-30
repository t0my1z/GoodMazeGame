#pragma once
#include"BaseRoom.h"
#include <vector>

//Class used before we had a builder to create rooms
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

