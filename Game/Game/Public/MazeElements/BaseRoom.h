#pragma once
#include "MazeElement.h"
#include "../EDirection.h"
#include <map>
#include <vector>

class BaseRoom : public MazeElement
{
public:
	BaseRoom(Transform transform);
	BaseRoom(const char* visual);
	BaseRoom(const char* visual, Transform transform);

private:

	std::map<EDirection, MazeElement*> neighbourElements;

public:
	virtual void Enter() override;
	void GetNeighbourElements(std::vector<MazeElement*> elementsToCheck);
	MazeElement* GetNeighbour(EDirection direction);
};

