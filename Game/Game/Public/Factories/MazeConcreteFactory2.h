#pragma once
#include "MazeBaseFactory.h"
#include "../MazeElements/BombRoom.h"
#include "../MazeElements/BreakableWall.h"

class MazeConcreteFactory2 : public MazeBaseFactory
{
public:
	//For more info in what they do, go to the MazeBaseFactory
	//To look at the concrete implementation of this Factory, go to the .cpp file
	virtual BaseRoom* AddRoom(Transform pos) const override;
	virtual BaseWall* AddWall(Transform pos) const override;
	virtual BaseDoor* AddDoor(Transform pos) const override;

	//Gets a random number
	int GetRandomNumber(int min, int max) const;
};

