#include "../../Public/MazeElements/BaseDoor.h"

BaseDoor::BaseDoor(Transform transform)
	:
	m_IsOpen(false),
	MazeElement("[]", transform)
{

}

BaseDoor::BaseDoor(const char* visual)
	:
	m_IsOpen(false),
	MazeElement(visual, { 0,0 })
{

}

BaseDoor::BaseDoor(const char* visual, Transform transform)
	:
	m_IsOpen(false),
	MazeElement(visual, transform)
{

}


void BaseDoor::Enter()
{

}

void BaseDoor::GetNeighbours(std::vector<BaseRoom*> rooms)
{
	//We find all the neighbour rooms we have, and set them in the corresponding direction
	for (size_t i = 0; i < rooms.size(); i++)
	{
		if (rooms[i]->GetTransform().GetXPos() == m_transform.GetXPos())
		{
			if (rooms[i]->GetTransform().GetYPos() == m_transform.GetYPos() - 1)
			{
				neighbourElements[EDirection::Up] = rooms[i];
				
			}
			else if (rooms[i]->GetTransform().GetYPos() == m_transform.GetYPos() + 1)
			{
				neighbourElements[EDirection::Down] = rooms[i];
			}
		}
		else if (rooms[i]->GetTransform().GetYPos() == m_transform.GetYPos())
		{
			if (rooms[i]->GetTransform().GetXPos() == m_transform.GetXPos() + 1)
			{
				neighbourElements[EDirection::Right] = rooms[i];
				
			}
			else if (rooms[i]->GetTransform().GetXPos() == m_transform.GetXPos() - 1)
			{
				neighbourElements[EDirection::Left] = rooms[i];
			}
		}
	}

	//Bools used to know if we have a room in both directions, either up/down or left/right
	bool canBeUpConexion = false;
	bool canBeSideConexion = false;

	//Check that we have up and down
	if (neighbourElements[EDirection::Up])
	{
		if (neighbourElements[EDirection::Down])
		{
			canBeUpConexion = true;
		}
		else canBeUpConexion = false;
	}
	//Check that we have left and right
	if (neighbourElements[EDirection::Left])
	{
		if (neighbourElements[EDirection::Right])
		{
			canBeSideConexion = true;
		}
		else canBeSideConexion = false;
	}

	//If we dont have a room in both directions, up/down or left/right, we don't have neighbours since we can't connect between them
	//as a door would
	if (!canBeSideConexion && !canBeUpConexion) neighbourElements.clear();

	if (canBeSideConexion && !canBeUpConexion)
	{
		neighbourElements.erase(EDirection::Up);
		neighbourElements.erase(EDirection::Down);
	}

	if (canBeUpConexion && !canBeSideConexion)
	{
		neighbourElements.erase(EDirection::Left);
		neighbourElements.erase(EDirection::Right);
	}

}
