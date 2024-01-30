#pragma once
#include "MazeElement.h"
#include "../EDirection.h"
#include <map>
#include <vector>

class BaseRoom : public MazeElement
{
public:
	//Base constructors needed for the class.
	BaseRoom(Transform transform);
	BaseRoom(const char* visual);
	BaseRoom(const char* visual, Transform transform);

private:
	//A map in which we store our neighbours on. 
	std::map<EDirection, MazeElement*> neighbourElements;

public:
	virtual void Enter() override;
	//Method in which we get the neighbours we have in all directions
	void GetNeighbourElements(std::vector<MazeElement*> elementsToCheck);
	//Method that takes in a direction and returns the neighbour we have there
	MazeElement* GetNeighbour(EDirection direction);
};

