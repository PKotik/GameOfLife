#pragma once

class Color
{
public:
	float R;
	float G;
	float B;

	Color() : R(1), G(1), B(1) {}
	Color(const float r, const float g,const float b): R(r/255), G(g/255), B(b/255) {}

	//Color operator=(const Color& color) { return Color(color); }
	void Dark()
	{
		R -= static_cast<float>(1) / 255;
		G -= static_cast<float>(1) / 255;
		//B -= static_cast<float>(1) / 255;
	}
};

class Outline
{
public:
	const bool isEnable;
	const float Thick;
	const Color ColorRGB;

	Outline(): Thick(0), ColorRGB(Color()), isEnable(0) {}
	Outline(float th, Color color): Thick(th), ColorRGB(color), isEnable(1) {}

	Outline operator=(const Outline& outline) { return Outline(outline); }
};