#include "StructureCore.h"
#include "Cell.h"
#include "ObjectWithId.h"

void StructureCore::Add(const Cell& cell)
{
    objectMap.insert({cell.Id(), cell});
}

void StructureCore::AddLater(const Cell& obj)
{
    newLifeQueue.push(obj);
}

Cell* StructureCore::Find(Coordinate coor)
{
    return Find(ObjectWithId::MakeId(coor));
}
Cell* StructureCore::Find(int id)
{
    auto it = objectMap.find(id);
    if (it != objectMap.end())
        return &it->second;
    return nullptr;
}

bool StructureCore::IsIt(Coordinate coor)
{
    return IsIt(ObjectWithId::MakeId(coor));
}
bool StructureCore::IsIt(int id)
{
    return objectMap.find(id) != objectMap.end();
}

void StructureCore::Remove(Coordinate coor)
{
    Remove(ObjectWithId::MakeId(coor));
}

void StructureCore::Remove(int id)
{
    auto it = objectMap.find(id);
    if (it != objectMap.end())
    {
        objectMap.erase(it);
    }
}

void StructureCore::RemoveLater(Coordinate coor)
{
    RemoveLater(ObjectWithId::MakeId(coor));
}

void StructureCore::RemoveLater(int id)
{
    dyingQueue.push(id);
}

void StructureCore::UpdateMap()
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
