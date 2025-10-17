#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Colors.h"

class GraphicClass
{
protected:
    Coordinate _coor;
    Colors _color;
public:
    GraphicClass() : _coor(), _color(Colors::Empty) {}

    GraphicClass(Coordinate coor, Colors color)
        : _coor(coor), _color(color){
    }
    virtual ~GraphicClass() = default;
    Coordinate coor() const { return _coor; }
    Colors color() const { return _color; }
};