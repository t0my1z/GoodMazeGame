#pragma once
#include "MazeBuilderBase.h"

class MazeConcreteBuilder1 : public MazeBuilderBase
{
public:
	MazeConcreteBuilder1(int offset, MazeBaseFactory* factory);
	virtual std::vector<MazeElement*> CreateMaze() override;
};

