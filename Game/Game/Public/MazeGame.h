#pragma once
#include "MazeElements/Maze.h"
#include "MazeElements/BaseWall.h"
#include "MazeElements/BaseDoor.h"
#include "Factories/MazeBaseFactory.h"

class MazeGame
{
public:

	MazeGame();

private:

	Maze* m_Maze;
	std::vector<BaseWall*> m_Walls;
	std::vector<BaseDoor*> m_Doors;

public:

	void CreateMazeEx12();

	void CreateMazeEx3(MazeBaseFactory*& factory, short offset);

private:

	void PrintMaze(std::vector<MazeElement*>& MazeElements);
};

