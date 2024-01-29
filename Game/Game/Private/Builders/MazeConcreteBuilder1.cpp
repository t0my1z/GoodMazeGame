#include "../../Public/Builders/MazeConcreteBuilder1.h"

MazeConcreteBuilder1::MazeConcreteBuilder1(int offset, MazeBaseFactory* factory)
	:
	MazeBuilderBase(offset, factory)
{
	//Setup Wall positions
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 2));
	//Setup Door positions
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 3), 1));
	//Setup Room positions
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 1));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 5), 1));
}

std::vector<MazeElement*> MazeConcreteBuilder1::CreateMaze()
{
    std::vector<MazeElement*> MazeElements;

	for (size_t i = 0; i < m_wallTransforms.size(); i++)
	{
		MazeElements.push_back(m_factory->AddWall(m_wallTransforms[i]));
	}

	for (size_t i = 0; i < m_doorTransforms.size(); i++)
	{
		MazeElements.push_back(m_factory->AddDoor(m_doorTransforms[i]));
	}

	for (size_t i = 0; i < m_roomTransforms.size(); i++)
	{
		MazeElements.push_back(m_factory->AddRoom(m_roomTransforms[i]));
	}

    return MazeElements;
}
