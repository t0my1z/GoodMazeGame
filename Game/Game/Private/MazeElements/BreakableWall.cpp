#include "../../Public/MazeElements/BreakableWall.h"

BreakableWall::BreakableWall(Transform transform) 
	:
	BaseWall("B", transform)
{

}
BreakableWall::BreakableWall(const char* visual)
	:
	BaseWall(visual)
{

}
BreakableWall::BreakableWall(const char* visual, Transform transform)
	:
	BaseWall(visual, transform)
{

}
