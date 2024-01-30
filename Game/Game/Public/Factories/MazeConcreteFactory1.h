#pragma once
#include "MazeBaseFactory.h"

class MazeConcreteFactory1 : public MazeBaseFactory
{
	//For more info in what they do, go to the MazeBaseFactory
	//To look at the concrete implementation of this Factory, go to the .cpp file
	virtual BaseRoom* AddRoom(Transform pos) const override;
	virtual BaseWall* AddWall(Transform pos) const override;
	virtual BaseDoor* AddDoor(Transform pos) const override;
};

