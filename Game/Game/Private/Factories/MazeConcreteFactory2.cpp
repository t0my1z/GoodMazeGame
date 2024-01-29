#include "../../Public/Factories/MazeConcreteFactory2.h"
#include <random>

int MazeConcreteFactory2::GetRandomNumber(int min, int max) const
{
    // Use std::random_device for a true random seed (may be slow)
     std::random_device rd;
     std::mt19937 rng(rd());

    // Use a constant seed for reproducibility (change if you want different sequences)
    //std::mt19937 rng(42);

    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

BaseRoom* MazeConcreteFactory2::AddRoom(Transform pos) const
{
    int min = 0;
    int max = 3;
    int ran = GetRandomNumber(min, max);
    if (ran >= 2)
    {
        return new BaseRoom(pos);
    }
    else
    {
        //return new BombRoom(, pos);
    }
}

BaseWall* MazeConcreteFactory2::AddWall(Transform pos) const
{
    //return new BreakableWall(pos);
}

BaseDoor* MazeConcreteFactory2::AddDoor(Transform pos) const
{
    return new BaseDoor(pos);
}


