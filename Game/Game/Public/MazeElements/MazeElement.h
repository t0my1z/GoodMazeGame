#pragma once
#include "../Transform.h"
#include <string>

class MazeElement
{
private:
	std::string m_visual;

protected:
	Transform m_transform;

public:
	//Constructor that inits variables to empty values
	MazeElement();
	//Constrcutor that inits transform to the passed positions
	MazeElement(Transform transform);
	//Constructor that inits visual to the passed visual and sets transform to the passed positions
	MazeElement(const char* visualRep, Transform transform);
	//Abstract method that child classes should implement
	virtual void Enter() {};
	//Virtual destructor so classes can implement their own destructors
	virtual ~MazeElement() {}

	//Get & Set for visual representation
	const std::string& GetVisual() const { return m_visual; }
	void SetVisual(char* newVisual) { m_visual = newVisual; }
	// Get & Set for transform
	Transform GetTransform() const { return m_transform; }
	void SetTransform(const Transform& newTransform) { m_transform = newTransform; }
};

