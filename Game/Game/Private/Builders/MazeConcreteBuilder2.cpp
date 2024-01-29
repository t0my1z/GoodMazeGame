#include "../../Public/Builders/MazeConcreteBuilder2.h"

MazeConcreteBuilder2::MazeConcreteBuilder2(int offset, MazeBaseFactory* factory)
	:
	MazeBuilderBase(offset, factory)
{
	//Setup Wall positions
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 3));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 4));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 6));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 1), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 2), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 3), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 0));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 1));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 2));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 3));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 4));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 4), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 5), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 7));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 6), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 5));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 6));
	m_wallTransforms.push_back(Transform(static_cast<short>(offset + 7), 7));
	//Setup Door positions
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 2), 3));
	m_doorTransforms.push_back(Transform(static_cast<short>(offset + 3), 6));
	//Setup Room positions
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 1));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 2));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 4));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 5));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 2), 6));
	m_roomTransforms.push_back(Transform(static_cast<short>(offset + 5), 6));
	//m_roomTransforms.push_back(Transform(static_cast<short>(offset + 7), 10));
}

std::vector<MazeElement*> MazeConcreteBuilder2::CreateMaze()
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
