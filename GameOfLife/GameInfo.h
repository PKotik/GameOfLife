#pragma once
#include <chrono>
#include <iostream>

class GameInfo
{
private:
	inline static bool _pause = false;
	inline static long long _generation = 0;
	inline static std::chrono::milliseconds _speed = std::chrono::milliseconds(10);

public:
	static bool IsPause() { return _pause; }
	static bool Pause() { _pause = true; }
	static bool Continue() { _pause = false; }
	static bool ReversePause() { _pause = !_pause; }

	static std::chrono::milliseconds Speed() { return _speed; }

	static void NewGeneration() { ++_generation; }
};