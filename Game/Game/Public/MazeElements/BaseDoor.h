#pragma once
#include "MazeElement.h"

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

public:
	//We set our door as entered
	virtual void Enter() override;
	bool IsOpen() { return m_IsOpen; }
};

