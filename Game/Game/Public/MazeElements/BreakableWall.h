#pragma once
#include "BaseWall.h"

//Example wall with a different visual representation so we can test 
//that our factories are working correctly
class BreakableWall : public BaseWall
{
public:
	BreakableWall(Transform transform);
	BreakableWall(const char* visual);
	BreakableWall(const char* visual, Transform transform);
};

