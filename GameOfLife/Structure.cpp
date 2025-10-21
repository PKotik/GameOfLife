#include "Structure.h"
#include "Cell.h"
#include "ObjectWithId.h"

void Structure::Add(const Cell& cell)
{
    objectMap.insert({cell.Id(), cell});
}

void Structure::AddLater(const Cell& obj)
{
    if (!IsIt(obj.coor())) newLifeQueue.push(obj);
}

Cell* Structure::Find(Coordinate coor)
{
    return Find(ObjectWithId::MakeId(coor));
}
Cell* Structure::Find(int id)
{
    auto it = objectMap.find(id);
    if (it != objectMap.end())
        return &it->second;
    return nullptr;
}

bool Structure::IsIt(Coordinate coor)
{
    return IsIt(ObjectWithId::MakeId(coor));
}
bool Structure::IsIt(int id)
{
    return objectMap.find(id) != objectMap.end();
}

void Structure::Remove(Coordinate coor)
{
    Remove(ObjectWithId::MakeId(coor));
}

void Structure::Remove(int id)
{
    auto it = objectMap.find(id);
    if (it != objectMap.end())
    {
        objectMap.erase(it);
    }
}

void Structure::RemoveLater(Coordinate coor)
{
    RemoveLater(ObjectWithId::MakeId(coor));
}

void Structure::RemoveLater(int id)
{
    dyingQueue.push(id);
}

void Structure::UpdateMap()
{
    while (!newLifeQueue.empty())
    {
        Add(newLifeQueue.front());
        newLifeQueue.pop();
    }
    while (!dyingQueue.empty())
    {
        Remove(dyingQueue.front());
        dyingQueue.pop();
    }
}

std::unordered_map<int, Cell>& Structure::GetAll()
{
    return objectMap;
}
