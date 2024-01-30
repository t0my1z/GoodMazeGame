#pragma once
#include "MazeElement.h"
#include "BaseRoom.h"
#include "../EDirection.h"
#include <map>
#include <vector>

class BaseDoor : public MazeElement
{
public:
	//Public constructors -> We give a few different options so we have more options when we create the maze,
	//like first deciding positions, or overriding the base look 
	BaseDoor(Transform transform);
	BaseDoor(const char* visual);
	BaseDoor(const char* visual, Transform transform);
	//Bool to know if the door was opened or not
	bool m_IsOpen;
	std::map<EDirection, BaseRoom*> neighbourElements; 

public:
	//We set our door as entered
	virtual void Enter() override;
	//check the rooms we pass and see if they are neighbours. We store them in our neighbourElements maps.
	//if we only have a connection in one direction, like for example up, but we don't have a conexion down, we discard this conexions
	//and the neighbourMap will be empty. We do this because we don't want doors that dont connect from both sides
	//Possible dirs are up/down or left/right
	void GetNeighbours(std::vector<BaseRoom*> rooms);
	bool IsOpen() { return m_IsOpen; }
};

