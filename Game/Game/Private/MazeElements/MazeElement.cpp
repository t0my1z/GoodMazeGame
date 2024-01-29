#include "../../Public/MazeElements/MazeElement.h"

MazeElement::MazeElement()
	:
	m_visual("ME"),
	m_transform(0, 0)
{

}

MazeElement::MazeElement(Transform transform)
	:
	m_visual("ME"),
	m_transform(transform.GetXPos(), transform.GetYPos())
{

}

MazeElement::MazeElement(const char* visualRep, Transform transform)
	:
	m_visual(visualRep),
	m_transform(transform.GetXPos(), transform.GetYPos())
{

}
