#pragma once
#include "MazeBuilderBase.h"

class MazeConcreteBuilder2 : public MazeBuilderBase
{
public:
	MazeConcreteBuilder2(int offset, MazeBaseFactory* factory);
	virtual std::vector<MazeElement*> CreateMaze() override;
};

