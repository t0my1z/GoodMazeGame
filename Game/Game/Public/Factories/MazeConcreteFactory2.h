#pragma once
#include "MazeBaseFactory.h"
#include "../MazeElements/BombRoom.h"
#include "../MazeElements/BreakableWall.h"

class MazeConcreteFactory2 : public MazeBaseFactory
{
public:

	virtual BaseRoom* AddRoom(Transform pos) const override;
	virtual BaseWall* AddWall(Transform pos) const override;
	virtual BaseDoor* AddDoor(Transform pos) const override;


	int GetRandomNumber(int min, int max) const;
};

