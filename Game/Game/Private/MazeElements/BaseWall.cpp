#include "../../Public/MazeElements/BaseWall.h"

BaseWall::BaseWall(Transform transform)
	:
	MazeElement("X", transform)
{

}

BaseWall::BaseWall(const char* visual)
	:
	MazeElement(visual, { 0,0 })
{

}

BaseWall::BaseWall(const char* visual, Transform transform)
	:
	MazeElement(visual, transform)
{

}


void BaseWall::Enter()
{
}
