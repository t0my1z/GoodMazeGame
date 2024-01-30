#include "../../Public/Builders/MazeConcreteBuilder2.h"
#include <iostream>
#include <windows.h>

MazeConcreteBuilder2::MazeConcreteBuilder2(int offset, MazeBaseFactory* factory)
	:
	MazeBuilderBase(offset, factory)
{
	//Setup Wall positions
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 3));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 4));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 6));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 3));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 4));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 6));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 7));
	//Setup Door positions
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 2), 3));
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 3), 6));
	//Setup Room positions
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 1));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 2));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 4));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 5));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 6));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 3), 1));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 3), 2));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 3), 4));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 5), 6));
	//m_roomTransforms.push_back(Transform(static_cast<short>(offset + 7), 10));
}

std::vector<MazeElement*> MazeConcreteBuilder2::CreateMaze()
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

void MazeConcreteBuilder2::InitMazeElements(std::vector<BaseWall*>& walls, std::vector<BaseDoor*>& doors, std::vector<BaseRoom*>& rooms,
	std::vector<MazeElement*>& AllElements)
{
	//Get the neighbours for rooms 
	for (size_t i = 0; i < rooms.size(); i++)
	{
		rooms[i]->GetNeighbourElements(AllElements);
	}
	//Get the neighbours for doors 
	for (size_t i = 0; i < doors.size(); i++)
	{
		doors[i]->GetNeighbours(rooms);		
	}

	//To show that this actually works, I'm going to print to screen a room and its neighbours, and the same with a door
	//I check if they actually have neighbours as a precaution
	//Write up neighbour
	if (rooms[0]->GetNeighbour(EDirection::Up))
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 15 });
		std::cout << "First room -> Up    -> " << rooms[0]->GetNeighbour(EDirection::Up)->GetVisual() << std::endl;
	}
	//Write down neighbour
	if (rooms[0]->GetNeighbour(EDirection::Down))
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 16 });
		std::cout << "First room -> Down  -> " << rooms[0]->GetNeighbour(EDirection::Down)->GetVisual() << std::endl;
	}
	//Write left neighbour
	if (rooms[0]->GetNeighbour(EDirection::Left))
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 17 });
		std::cout << "First room -> Left  -> " << rooms[0]->GetNeighbour(EDirection::Left)->GetVisual() << std::endl;
	}
	//Write right neighbour
	if (rooms[0]->GetNeighbour(EDirection::Right))
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 18 });
		std::cout << "First room -> Right -> " << rooms[0]->GetNeighbour(EDirection::Right)->GetVisual() << std::endl;
	}

	////Write up and down neighbour
	if (doors[0]->neighbourElements[EDirection::Up])
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 20 });
		std::cout << "First door -> Up    -> " << doors[0]->neighbourElements[EDirection::Up]->GetVisual() << std::endl;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 21 });
		std::cout << "First door -> Down  -> " << doors[0]->neighbourElements[EDirection::Down]->GetVisual() << std::endl;
	}
	//Write left and right neighbour
	else if (doors[0]->neighbourElements[EDirection::Left])
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 22 });
		std::cout << "First door -> Left  -> " << doors[0]->neighbourElements[EDirection::Left]->GetVisual() << std::endl;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(m_Offset * 2.2f), 23 });
		std::cout << "First door -> Right -> " << doors[0]->neighbourElements[EDirection::Right]->GetVisual() << std::endl;
	}
}
