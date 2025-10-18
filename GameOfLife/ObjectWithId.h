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
        return static_cast<int>(std::ceil((value - Constants::EPS) / Constants::Step)) - 1;
    }
    static int hashCoords(float x, float y)
    {
        int ix = cellIndexX(x);
        int iy = cellIndexY(y);
        return (ix * 73856093) ^ (iy * 19349663);
    }

public:
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

