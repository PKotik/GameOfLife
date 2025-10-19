#pragma once
#include "Coordinate.h"
#include "GraphicClass.h"
#include "Visual.h"
#include <queue>
#include <memory>
#include "MainCore.h"

class GraphicCore : public MainCore
{
private:
	inline static std::queue<GraphicClass> drawQueue;

public:
	static void Draw(const GraphicClass& obj);
	static void RefreshFrame();
	static bool WindowIsAlive();
	static GLFWwindow* GetWindow();
	
private:
	static void DrawObj(const GraphicClass& obj);
	static void SetColor(const Color color);
};

