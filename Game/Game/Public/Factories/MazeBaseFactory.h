#pragma once
#include "../MazeElements/BaseRoom.h"
#include "../MazeElements/BaseDoor.h"
#include "../MazeElements/BaseWall.h"
#include"../Transform.h"

class MazeBaseFactory
{
public:
	virtual BaseRoom* AddRoom(Transform pos) const = 0;
	virtual BaseWall* AddWall(Transform pos) const = 0;
	virtual BaseDoor* AddDoor(Transform pos) const = 0;
};

