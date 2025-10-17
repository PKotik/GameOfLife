#pragma once
#include "Coordinate.h"
#include "GraphicClass.h"
#include "Constants.h"

class Cell : public GraphicClass
{
private:
	double _lifetime;
	int _envir;
	bool _isDead;
public:
	Cell(float x, float y) : GraphicClass(Coordinate(x, y, Constants::lenXCell, Constants::lenYCell),
		Constants::CellColor, Constants::CellOutline),
		_lifetime(0), _envir(0), _isDead(0) {}

	// lifetime
	double Lifetime() const { return _lifetime; }
	void GrowOld() { _lifetime += Constants::MomentForCell; }

	// isDead
	bool IsDead() const { return _isDead; }
	void Kill() { _isDead = true; }

	// envir
	int Envir() const { return _envir; }
	void Envir(int count)
	{
#ifdef _DEBUG
		if (count < 0 || count > 8)
			throw std::invalid_argument("value must be from 0 to 8");
#else
		if (count < 0 || count > 8)
			count = 0;
#endif
		_envir = count;
	}
};