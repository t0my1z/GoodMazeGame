#pragma once
#include "MazeBaseFactory.h"

class MazeConcreteFactory1 : public MazeBaseFactory
{
	virtual BaseRoom* AddRoom(Transform pos) const override;
	virtual BaseWall* AddWall(Transform pos) const override;
	virtual BaseDoor* AddDoor(Transform pos) const override;
};

