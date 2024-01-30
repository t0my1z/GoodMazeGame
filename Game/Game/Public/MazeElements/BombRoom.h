#pragma once
#include "BaseRoom.h"

//Example room with a different visual representation so we can test 
//that our factories are working correctly
class BombRoom : public BaseRoom
{
public:
	BombRoom(Transform transform);
	BombRoom(const char* visual);
	BombRoom(const char* visual, Transform transform);
};

