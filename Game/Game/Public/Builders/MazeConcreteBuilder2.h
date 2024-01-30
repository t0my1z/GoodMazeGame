#pragma once
#include "MazeBuilderBase.h"

class MazeConcreteBuilder2 : public MazeBuilderBase
{
public:
	//For info into what this do, please go to the MazeBuilderBase.h
	MazeConcreteBuilder2(int offset, MazeBaseFactory* factory);
	virtual std::vector<MazeElement*> CreateMaze() override;
	//Sets up the connections of the elements, and also prints them so we can see that it works.
	virtual void InitMazeElements(std::vector<BaseWall*>& walls, std::vector<BaseDoor*>& doors, std::vector<BaseRoom*>& rooms, std::vector<MazeElement*>& AllElements) override;
};

