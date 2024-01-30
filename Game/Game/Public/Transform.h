#pragma once
#include <windows.h>

//Class used mainly to keep track of the positions of all the MazeElements.
//we use this positions to print the different elements in their correct points and draw a Maze correctly
class Transform 
{
public:
	Transform();
	//Constructor that takes two shorts and sets our private m_screenPos with them. 
	// This m_screenPos is the one used to keep track of position
	Transform(short xPos, short yPos);

private:

	COORD m_screenPos;

public:
	//Getters & Setters
	int GetXPos() const { return m_screenPos.X; }
	int GetYPos() const { return m_screenPos.Y; }
	COORD GetScreenPos() const { return m_screenPos; }
	void SetPos(int newXPos, int newYPos);
	void SetXPos(int newXPos) { m_screenPos.X = newXPos; }
	void SetYPos(int newYPos) { m_screenPos.Y = newYPos; }
};

