#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Visual.h"

class GraphicClass
{
protected:
    bool _isEnable;
    Coordinate _coor;
    Color _color;
    Outline _outline;
public:
    GraphicClass(Coordinate coor, Color color)
        : _coor(coor), _color(color), _outline(Outline()), _isEnable(1){
    }
    GraphicClass(Coordinate coor, Color color, Outline outline)
        : _coor(coor), _color(color), _outline(Outline(outline)), _isEnable(1) {}
    virtual ~GraphicClass() = default;
    Coordinate coor() const { return _coor; }
    Color color() const { return _color; }
    void color(Color color) { _color = Color(color); }
    Outline outline() const { return _outline; }
    bool isEnable() const { return _isEnable; }
    void Enable() { _isEnable = true; }
    void Disable() { _isEnable = false; }

};