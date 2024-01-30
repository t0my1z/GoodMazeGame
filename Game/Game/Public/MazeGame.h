#pragma once
#include "MazeElements/Maze.h"
#include "MazeElements/BaseWall.h"
#include "MazeElements/BaseDoor.h"
#include "Factories/MazeBaseFactory.h"
#include "Builders/MazeBuilderBase.h"

class MazeGame
{
public:
	//Constructor that creates a new maze and stores it in our m_Maze member variable
	MazeGame();

private:

	//Only used in the CreateMazeEx12 since we dont have a factory yet, and we create rooms through the Maze class
	Maze* m_Maze;

public:
	//Method for the first and second points
	void CreateMazeEx12();
	//Method for the third point -> Using a factory, creates a maze. 
	// Receives an offset so we can print more than one maze by offsetting the position of one of them by the amount we want
	void CreateMazeEx3(MazeBaseFactory* factory, short offset);
	//Method for the fourth point -> Using a builder, create a maze using the factory that the builder has. 
	// You set this factory on the builder constructors.
	void CreateMazeEx4(MazeBuilderBase*& builder);

private:
	//Simply prints the elements in their position and with their visual representation
	void PrintMaze(std::vector<MazeElement*>& MazeElements);
};

