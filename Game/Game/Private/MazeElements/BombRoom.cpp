#include "../../Public/MazeElements/BombRoom.h"

BombRoom::BombRoom(Transform transform)
	:
	BaseRoom("*", transform)
{

}

BombRoom::BombRoom(const char* visual)
	:
	BaseRoom(visual)
{

}

BombRoom::BombRoom(const char* visual, Transform transform)
	:
	BaseRoom(visual, transform)
{

}
