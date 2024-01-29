#pragma once
#include <windows.h>

class Transform
{
public:
	Transform();
	Transform(short xPos, short yPos);

private:

	COORD m_screenPos;

public:
	int GetXPos() const { return m_screenPos.X; }
	int GetYPos() const { return m_screenPos.Y; }
	COORD GetScreenPos() const { return m_screenPos; }
	void SetPos(int newXPos, int newYPos);
	void SetXPos(int newXPos) { m_screenPos.X = newXPos; }
	void SetYPos(int newYPos) { m_screenPos.Y = newYPos; }
};

