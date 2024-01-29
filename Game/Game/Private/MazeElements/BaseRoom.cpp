#include "../../Public/MazeElements/BaseRoom.h"

BaseRoom::BaseRoom(Transform transform)
	:
	MazeElement((new char[3] {" "}), transform)
{

}

BaseRoom::BaseRoom(const char* visual)
	:
	MazeElement(visual, { 0,0 })
{

}

BaseRoom::BaseRoom(const char* visual, Transform transform)
	:
	MazeElement(visual, transform)
{

}

void BaseRoom::Enter()
{

}

void BaseRoom::GetNeighbourElements(std::vector<MazeElement*> elementsToCheck)
{
	for (size_t i = 0; i < elementsToCheck.size(); i++)
	{
		if (elementsToCheck[i]->GetTransform().GetXPos() == m_transform.GetXPos())
		{
			if (elementsToCheck[i]->GetTransform().GetYPos() == m_transform.GetYPos() + 1)
			{
				neighbourElements[EDirection::Up] = elementsToCheck[i];
			}
			else if (elementsToCheck[i]->GetTransform().GetYPos() == m_transform.GetYPos() - 1)
			{
				neighbourElements[EDirection::Down] = elementsToCheck[i];
			}
		}
		else if (elementsToCheck[i]->GetTransform().GetYPos() == m_transform.GetYPos())
		{
			if (elementsToCheck[i]->GetTransform().GetXPos() == m_transform.GetXPos() + 1)
			{
				neighbourElements[EDirection::Right] = elementsToCheck[i];
			}
			else if (elementsToCheck[i]->GetTransform().GetXPos() == m_transform.GetXPos() - 1)
			{
				neighbourElements[EDirection::Left] = elementsToCheck[i];
			}
		}
	}
}

MazeElement* BaseRoom::GetNeighbour(EDirection direction)
{
	if (neighbourElements[direction])
	{
		return neighbourElements[direction];
	}
	else return nullptr;
}
