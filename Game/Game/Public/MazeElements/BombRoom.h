#pragma once
#include "BaseRoom.h"

class BombRoom : public BaseRoom
{
public:
	BombRoom(Transform transform);
	BombRoom(const char* visual);
	BombRoom(const char* visual, Transform transform);
};

