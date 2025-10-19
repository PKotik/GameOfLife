#pragma once
#include <unordered_map>
#include <utility>
#include <cmath>
#include "Cell.h"
#include <queue>
#include <memory>

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
    void AddLater(const Cell& obj);
    Cell* Find(Coordinate coor); // TODO: подумать, а надо ли вообще *?
    Cell* Find(int id); // TODO: подумать, а надо ли вообще *?
    bool IsIt(Coordinate coor);
    bool IsIt(int id);
    void Remove(Coordinate coor);
    void Remove(int id);
    void RemoveLater(Coordinate coor);
    void RemoveLater(int id);
    void UpdateMap();
    std::unordered_map<int, Cell>& GetAll();
};

