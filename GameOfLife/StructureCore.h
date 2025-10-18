#pragma once
#include <unordered_map>
#include <utility>
#include <cmath>
#include "Cell.h"

class StructureCore
{
private:
    std::unordered_map<int, Cell> objectMap;

public:
    StructureCore() = default;
    ~StructureCore() = default;

    void Add(const Cell& obj);
    Cell* Find(Coordinate coor);
    Cell* Find(int id);
    bool IsIt(Coordinate coor);
    bool IsIt(int id);
    void Remove(Coordinate coor);
    void Remove(int id);
};

