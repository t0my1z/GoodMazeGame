#pragma once
#include "../MazeElements/BaseRoom.h"
#include "../MazeElements/BaseDoor.h"
#include "../MazeElements/BaseWall.h"
#include"../Transform.h"

class MazeBaseFactory
{
public:
	//Abstract methods that need to be implemented by the concrete factories. Each method creates the thing they are meant to
	//Concrete factories are expected to create whatever rooms, walls and doors they want, and they can be whatever the concrete factory wants
	//as long as they inherit from the Base classes
	virtual BaseRoom* AddRoom(Transform pos) const = 0;
	virtual BaseWall* AddWall(Transform pos) const = 0;
	virtual BaseDoor* AddDoor(Transform pos) const = 0;
};

