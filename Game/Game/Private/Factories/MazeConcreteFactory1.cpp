#include "../../Public/Factories/MazeConcreteFactory1.h"


BaseRoom* MazeConcreteFactory1::AddRoom(Transform pos) const
{
    return new BaseRoom(pos);
}

BaseWall* MazeConcreteFactory1::AddWall(Transform pos) const
{
    return new BaseWall(pos);
}

BaseDoor* MazeConcreteFactory1::AddDoor(Transform pos) const
{
    return new BaseDoor(pos);
}
