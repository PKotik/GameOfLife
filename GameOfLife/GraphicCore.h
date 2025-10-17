#pragma once
#include "Coordinate.h"
#include "GraphicClass.h"
#include "Visual.h"
#include <GLFW/glfw3.h>
#include <queue>
#include <memory>

class GraphicCore
{
private:
	inline static std::queue<GraphicClass> drawQueue;
	inline static GLFWwindow* window;
	inline static int isGlFWInit = 0;

public:
	static void Draw(const GraphicClass& obj);
	static void RefreshFrame();
	static void GLFWDeInit();
	static bool WindowIsAlive();
	

private:
	static void GLWindowInit();
	static void DrawObj(const GraphicClass& obj);
	static void SetColor(const Color color);
};

