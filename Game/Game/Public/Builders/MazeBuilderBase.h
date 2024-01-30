#pragma once
#include "../Factories/MazeBaseFactory.h"


class MazeBuilderBase
{
public:
	//Constructor that takes an offset and a factory and sets our private variables with them
	MazeBuilderBase(int offset, MazeBaseFactory* factory)
	:
		m_Offset(offset),
		m_factory(factory)
	{

	};

protected: 
	//Private vector of the positions for each of the elements we are going to create
	//We use the constructor to set the positions we want our maze elements to be on,
	//and then use them in the CreateMaze method so we create the elements in the position we define in the Concrete Builders
	//To see this implemented, go to the concrete builders .cpp
	std::vector<Transform> m_wallTransforms;
	std::vector<Transform> m_roomTransforms;
	std::vector<Transform> m_doorTransforms; 
	MazeBaseFactory* m_factory;
public:
	//Offset used to print the maze
	int m_Offset;
	//Method that concrete builders need to implement, and in which they will create the actual maze
	virtual std::vector<MazeElement*> CreateMaze() = 0;
	//Method that will Initialize the different kind of MazeElements we have. Currently used to get the neighbours of rooms and doors
	virtual void InitMazeElements(std::vector<BaseWall*>& walls, std::vector<BaseDoor*>& doors, std::vector<BaseRoom*>& rooms, std::vector<MazeElement*>& AllElements) = 0;
};

