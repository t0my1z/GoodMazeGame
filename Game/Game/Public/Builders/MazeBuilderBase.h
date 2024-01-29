#pragma once
#include "../Factories/MazeBaseFactory.h"


class MazeBuilderBase
{
public:
	MazeBuilderBase(int offset, MazeBaseFactory* factory)
	:
		m_Offset(offset),
		m_factory(factory)
	{

	};

protected: 
	std::vector<Transform> m_wallTransforms;
	std::vector<Transform> m_roomTransforms;
	std::vector<Transform> m_doorTransforms; 
	MazeBaseFactory* m_factory;
public:
	int m_Offset;
	virtual std::vector<MazeElement*> CreateMaze() = 0;
};

