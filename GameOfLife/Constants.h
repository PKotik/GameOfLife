#pragma once
#include "Visual.h"
#include <chrono>

namespace Constants
{
	const Color DefaultColor(255, 255, 255);
	const Color CellColor(74, 147, 255);
	const Color OutlineCellColor(72, 93, 125);

	const Color FieldColor(210, 230, 255);
	const Color OutlineFieldColor(175, 191, 213);

	const Color OutlineButtonColor(67, 67, 67);
	const Color ButtonDefColor(187, 218, 219);
	const Color ButtonDefSelectColor(240, 240, 240);
	const Color ButtonClearColor(187, 218, 219);
	const Color ButtonSelectClearColor(240, 240, 240);

	const Outline CellOutline(0.001, OutlineCellColor);
	const Outline FieldOutline(0.00225, OutlineFieldColor);
	const Outline ButtonOutline(0.004, OutlineButtonColor);

	const float EPS = 0.00005;
	const double MomentForCell = 0.005;
	const float lenXCell = 0.020;
	const float lenYCell = 0.020;
	const float lenXField = 0.0225;
	const float lenYField = 0.0225;
	const float Step = 0.025;
	const int NeedForBirth = 3;
	const int GoodForLife1 = 2;
	const int GoodForLife2 = 3;
	const int resolutionX = 1200;
	const int resolutionY = 1200;

	const std::chrono::milliseconds DefaultTimeOut(200);
	const std::chrono::milliseconds CreateCellClickTimeOut(1);
	const std::chrono::milliseconds SpeedTimeOut(20);
	const std::chrono::milliseconds RandomTimeOut(1000);

	const std::chrono::milliseconds SpeedStep(10);
}