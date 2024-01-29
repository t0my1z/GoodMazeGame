#include "../../Public/MazeElements/BaseDoor.h"

BaseDoor::BaseDoor(Transform transform)
	:
	m_IsOpen(false),
	MazeElement("[]", transform)
{

}

BaseDoor::BaseDoor(const char* visual)
	:
	m_IsOpen(false),
	MazeElement(visual, { 0,0 })
{

}

BaseDoor::BaseDoor(const char* visual, Transform transform)
	:
	m_IsOpen(false),
	MazeElement(visual, transform)
{

}


void BaseDoor::Enter()
{

}
