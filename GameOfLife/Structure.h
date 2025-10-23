#pragma once
#include <unordered_map>
#include <utility>
#include <cmath>
#include "Cell.h"
#include <queue>
#include <memory>
#include <vector>

class Structure
{
private:
    std::unordered_map<int, Cell> objectMap;
    inline static std::queue<Cell> newLifeQueue;
    inline static std::queue<int> dyingQueue;
    
public:
    Structure() = default;
    ~Structure() = default;

    void Add(const Cell& obj);
    void AddMany(const std::vector<Cell> cells);
    void AddLater(const Cell& obj);
    Cell* Find(Coordinate coor);
    Cell* Find(int id);
    bool IsIt(Coordinate coor);
    bool IsIt(int id);
    void Remove(Coordinate coor);
    void Remove(int id);
    void RemoveLater(Coordinate coor);
    void RemoveLater(int id);
    void RemoveAll();
    void UpdateMap();
    std::unordered_map<int, Cell>& GetAll();
};

