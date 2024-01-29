#include "../Public/Transform.h"

Transform::Transform()
	:
	m_screenPos{ 0,0 }

{

}

Transform::Transform(short xPos, short yPos)
	:
	m_screenPos{ xPos, yPos }
{

}

void Transform::SetPos(int newXPos, int newYPos)
{
	m_screenPos.X = newXPos;
	m_screenPos.Y = newYPos;
}
