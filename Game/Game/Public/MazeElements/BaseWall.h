#pragma once
#include "MazeElement.h"

class BaseWall : public MazeElement
{
public:
	//Base constructors needed for the class.
	BaseWall(Transform transform);
	BaseWall(const char* visual);
	BaseWall(const char* visual, Transform transform);

public:
	virtual void Enter() override;
};

