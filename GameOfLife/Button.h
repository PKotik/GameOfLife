#pragma once
#include "GraphicClass.h"
#include <functional>
#include <iostream>
#include "Coordinate.h"
#include <chrono>

class Button : public GraphicClass
{
private:
	std::string _code;
	bool _state;
	bool _selected;
	std::function<void()> _action;
	std::function<void()> _secondAction = nullptr;
	Color _selectColor;

	std::chrono::steady_clock::time_point _lastPressTime;
	std::chrono::milliseconds _timeout;

	bool CanPressNow()
	{
		auto now = std::chrono::steady_clock::now();
		if (now - _lastPressTime >= _timeout)
		{
			_lastPressTime = now;
			return true;
		}
		return false;
	}

public:
	Button(const std::string code, Coordinate coor, Color color, Color selectColor,
					std::function<void()> func,
					std::chrono::milliseconds timeout = std::chrono::milliseconds(Constants::DefaultTimeOut))
		: _action(func), _secondAction(func), GraphicClass(coor, color, Constants::ButtonOutline),
		_code(code), _state(0), _selected(0), _selectColor(selectColor),
		_lastPressTime(std::chrono::steady_clock::now()), _timeout(timeout) {}

	Button(const std::string code, Coordinate coor, Color color, Color selectColor,
				std::function<void()> func1, std::function<void()> func2,
				std::chrono::milliseconds timeout = std::chrono::milliseconds(Constants::DefaultTimeOut))
		: _action(func1), _secondAction(func2), GraphicClass(coor, color, Constants::ButtonOutline),
		_code(code), _state(0), _selected(0), _selectColor(selectColor),
		_lastPressTime(std::chrono::steady_clock::now()), _timeout(timeout) {}

	bool State() const { return _state; }
	bool Selected() const { return _selected; }

	void Select()
	{
		if (!_selected)
		{
			_selected = true;
			ReverseColors();
		}
	}
	void NotSelect()
	{ 
		if (_selected)
		{
			_selected = false;
			ReverseColors();
		}
	}
	void ReverseColors()
	{
		Color saveColor = _color;
		_color = _selectColor;
		_selectColor = saveColor;
	}
	void ON() { _state = true; }
	void OFF() { _state = false; }

	void Do()
	{
		if (!CanPressNow()) return;
		if (_action && !_state)
		{
			_action();
			ON();
			return;
		}
		else if (_secondAction && _state)
		{
			_secondAction();
			OFF();
			return;
		}
			
	}
};


