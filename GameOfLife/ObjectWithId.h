#pragma once
#include "Constants.h"
#include <cmath>
#include <cstdint>
#include "Coordinate.h"

class ObjectWithId
{
protected:
	int _id;

    static int cellIndexX(float value)
    {
        return static_cast<int>(std::floor((value + Constants::EPS) / Constants::Step));
    }

    static int cellIndexY(float value)
    {
        return static_cast<int>(std::floor((value - Constants::EPS) / Constants::Step));
    }
    static int hashCoords(float x, float y)
    {
        int ix = cellIndexX(x);
        int iy = cellIndexY(y);
        return ((100 + ix) * 100) + (100 + iy);
    }

public:
    static float RoundX(float x)
    {
        return std::floor((x + Constants::EPS) / Constants::Step) * Constants::Step;
    }
    static float RoundY(float y)
    {
        return std::floor((y - Constants::EPS) / Constants::Step) * Constants::Step;
    }

    static Coordinate RoundCoor(Coordinate coor)
    {
        coor.X(std::floor((coor.X() + Constants::EPS) / Constants::Step) * Constants::Step);
        coor.Y(std::floor((coor.Y() - Constants::EPS) / Constants::Step) * Constants::Step);
        return coor;
    }

    ObjectWithId(float x, float y)
        : _id(hashCoords(x, y)){}
    virtual ~ObjectWithId() = default;

    int Id() const { return _id; }

    static int MakeId(float x, float y)
    {
        return hashCoords(x, y);
    }

    static int MakeId(Coordinate coor)
    {
        return hashCoords(coor.X(), coor.Y());
    }
};

