#pragma once
#include "BaseWall.h"

class BreakableWall : public BaseWall
{
public:
	BreakableWall(Transform transform);
	BreakableWall(const char* visual);
	BreakableWall(const char* visual, Transform transform);
};

