#pragma once
#include "Coordinate.h"
#include "GraphicClass.h"
#include "ObjectWithId.h"
#include "Constants.h"

class Cell : public GraphicClass, public ObjectWithId
{
private:
	double _lifetime;
	int _envir;
	bool _isDead;
public:
	Cell(float x, float y) : GraphicClass(Coordinate(x, y, Constants::lenXCell, Constants::lenYCell),
		Constants::CellColor, Constants::CellOutline),
		_lifetime(0), _envir(0), _isDead(0), ObjectWithId(x, y) { }
	Cell(Coordinate coor) : GraphicClass(coor,
		Constants::CellColor, Constants::CellOutline),
		_lifetime(0), _envir(0), _isDead(0), ObjectWithId(coor.X(), coor.Y()) {
		_coor.lenX(Constants::lenXCell);
		_coor.lenY(Constants::lenYCell);
	}

	// lifetime
	double Lifetime() const { return _lifetime; }
	void GrowOld() 
	{ 
		_lifetime += Constants::MomentForCell; 
		_color.Dark();
	}

	// isDead
	bool IsDead() const { return _isDead; }
	void Kill() { _isDead = true; }

	// envir
	bool GoodForBirth() const { return _envir == Constants::NeedForBirth; }
	bool GoodForLife() const { return _envir == Constants::GoodForLife1 || _envir == Constants::GoodForLife2; }
	void UpEnvir() { ++_envir; }
	void ResetEnvir() { _envir = 0; }

	Cell operator=(const Cell& cell) { return Cell(cell); }

};