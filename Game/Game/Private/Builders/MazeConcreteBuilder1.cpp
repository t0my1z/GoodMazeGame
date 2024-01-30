#include "../../Public/Builders/MazeConcreteBuilder1.h"
#include <iostream>
#include <windows.h>

MazeConcreteBuilder1::MazeConcreteBuilder1(int offset, MazeBaseFactory* factory)
	:
	MazeBuilderBase(offset, factory)
{
	//Setup Wall positions
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 2));
	//Setup Door positions
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 3), 1));
	//Setup Room positions
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 1));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 5), 1));
}

std::vector<MazeElement*> MazeConcreteBuilder1::CreateMaze()
{
	//Create lists for all relevant elements. 
	std::vector<MazeElement*> MazeElements;
	std::vector<BaseRoom*> rooms;
	std::vector<BaseDoor*> doors;
	std::vector<BaseWall*> walls;

	//Using the transforms setted in the constructor of the builder, create the corresponding MazeElements in their corresponding positions

	for (size_t i = 0; i < m_wallTransforms.size(); i++)
	{
		BaseWall* newWall = m_factory->AddWall(m_wallTransforms[i]);
		MazeElements.push_back(newWall);
		walls.push_back(newWall);
	}

	for (size_t i = 0; i < m_doorTransforms.size(); i++)
	{
		BaseDoor* newDoor = m_factory->AddDoor(m_doorTransforms[i]);
		MazeElements.push_back(newDoor);
		doors.push_back(newDoor);
	}

	for (size_t i = 0; i < m_roomTransforms.size(); i++)
	{
		BaseRoom* newRoom = m_factory->AddRoom(m_roomTransforms[i]);
		MazeElements.push_back(newRoom);
		rooms.push_back(newRoom);
	}

	//Pass the relevant lists so each element can Initialize correctly
	InitMazeElements(walls, doors, rooms, MazeElements);

	//Return all the created MazeElements
	return MazeElements;
}

void MazeConcreteBuilder1::InitMazeElements(std::vector<BaseWall*>& walls, std::vector<BaseDoor*>& doors, 
	std::vector<BaseRoom*>& rooms, std::vector<MazeElement*>& AllElements)
{
	for (size_t i = 0; i < rooms.size(); i++)
	{
		rooms[i]->GetNeighbourElements(AllElements);
	}

	for (size_t i = 0; i < doors.size(); i++)
	{
		doors[i]->GetNeighbours(rooms);
	}
}
