#pragma once

class Color
{
public:
	const float R;
	const float G;
	const float B;

	Color() : R(1), G(1), B(1) {}
	Color(float r, float g, float b): R(r/255), G(g/255), B(b/255) {}
};

class Outline
{
public:
	const bool isEnable;
	const float Thick;
	const Color RGB;

	Outline(): Thick(0), RGB(Color()), isEnable(0) {}
	Outline(float th, Color color): Thick(th), RGB(color), isEnable(1) {}
};