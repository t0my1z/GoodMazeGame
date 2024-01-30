#pragma once
#include "MazeBuilderBase.h"

class MazeConcreteBuilder1 : public MazeBuilderBase
{
public:
	//For info into what this do, please go to the MazeBuilderBase.h
	MazeConcreteBuilder1(int offset, MazeBaseFactory* factory);
	virtual std::vector<MazeElement*> CreateMaze() override;
	//Sets up the connections of the elements
	virtual void InitMazeElements(std::vector<BaseWall*>& walls, std::vector<BaseDoor*>& doors, std::vector<BaseRoom*>& rooms, std::vector<MazeElement*>& AllElements) override;
};

