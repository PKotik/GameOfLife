#pragma once
#include "Coordinate.h"
#include "GraphicClass.h"
#include "Colors.h"

class Cell : public GraphicClass
{
private:
	float _time_live;
	int _envir; 
	bool _isDead;
	int _id;
public:
	Cell() : GraphicClass(),
		_time_live(0), _envir(0), _isDead(0), _id(0) { }
	Cell(float x, float y) : GraphicClass(Coordinate(x, y), Colors::Cell),
		_time_live(0), _envir(0), _isDead(0), _id(0) {
	}
	// Гетеры сетеры реализовать, убивание клетки и т.д.
};