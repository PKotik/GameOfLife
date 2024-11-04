#pragma once
#include <GLFW/glfw3.h>
#include <GL/glut.h>

class Button
{
public:
	float coor_x; float coor_y; float radius_x; float radius_y;
	GLFWwindow* window;



	void BuildButton()
	{
		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(coor_x - (radius_x + 0.003), coor_y - (radius_y + 0.003));
		glVertex2f(coor_x - (radius_x + 0.003), coor_y + (radius_y + 0.003));
		glVertex2f(coor_x + (radius_x + 0.003), coor_y + (radius_y + 0.003));
		glVertex2f(coor_x + (radius_x + 0.003), coor_y - (radius_y + 0.003));
		glBegin(GL_QUADS);
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex2f(coor_x - radius_x, coor_y - radius_y);
		glVertex2f(coor_x - radius_x, coor_y + radius_y);
		glVertex2f(coor_x + radius_x, coor_y + radius_y);
		glVertex2f(coor_x + radius_x, coor_y - radius_y);

	}

	void Backlight()
	{
		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(coor_x - (radius_x + 0.003), coor_y - (radius_y + 0.003));
		glVertex2f(coor_x - (radius_x + 0.003), coor_y + (radius_y + 0.003));
		glVertex2f(coor_x + (radius_x + 0.003), coor_y + (radius_y + 0.003));
		glVertex2f(coor_x + (radius_x + 0.003), coor_y - (radius_y + 0.003));
		glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(coor_x - radius_x, coor_y - radius_y);
		glVertex2f(coor_x - radius_x, coor_y + radius_y);
		glVertex2f(coor_x + radius_x, coor_y + radius_y);
		glVertex2f(coor_x + radius_x, coor_y - radius_y);
	}

	void PrintText_Start()
	{
		glColor3f(0,0,0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10, coor_y + radius_y / 3);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y + radius_y / 3);

		glBegin(GL_QUADS);
		glVertex2f(coor_x + (radius_x / 10) - 0.005, coor_y- radius_y / 3);
		glVertex2f(coor_x + (radius_x / 10), coor_y - radius_y / 3);
		glVertex2f(coor_x + (radius_x / 10), coor_y + radius_y / 3);
		glVertex2f(coor_x + (radius_x / 10) - 0.005, coor_y + radius_y / 3);
	}
	void PrintText_Stop()
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y- radius_y / 3);
		glVertex2f(coor_x - radius_x / 10, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10, coor_y + radius_y / 3);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y + radius_y / 3);

		glBegin(GL_QUADS);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10, coor_y - radius_y / 3);
		glVertex2f(coor_x + radius_x / 10, coor_y);
		glVertex2f(coor_x + (radius_x / 10) - 0.005, coor_y);

		glBegin(GL_QUADS);
		glVertex2f(coor_x - radius_x / 10, coor_y + radius_y / 3);
		glVertex2f(coor_x - (radius_x / 10) - 0.005, coor_y + radius_y / 3);
		glVertex2f(coor_x + radius_x / 10, coor_y);
		glVertex2f(coor_x + (radius_x / 10) - 0.005, coor_y);
	}
	void PrintText_SpeedUp()
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - 0.002, coor_y - radius_y / 2);
		glVertex2f(coor_x + 0.002, coor_y - radius_y / 2);
		glVertex2f(coor_x + 0.002, coor_y + radius_y / 2);
		glVertex2f(coor_x - 0.002, coor_y + radius_y / 2);

		glBegin(GL_QUADS);
		glVertex2f(coor_x- radius_y / 2, coor_y - 0.002);
		glVertex2f(coor_x- radius_y / 2, coor_y + 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y + 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y - 0.002);
	}
	void PrintText_SpeedDown()
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - radius_y / 2, coor_y - 0.002);
		glVertex2f(coor_x - radius_y / 2, coor_y + 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y + 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y - 0.002);
	}
	void PrintText_Rand()
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - (radius_x / 10) + 0.002, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10- 0.002, coor_y - radius_y / 3);
		glVertex2f(coor_x - radius_x / 10- 0.002, coor_y + radius_y / 3);
		glVertex2f(coor_x - (radius_x / 10) + 0.002, coor_y + radius_y / 3);

		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(coor_x + 0.002, coor_y - radius_y / 3);
		glVertex2f(coor_x- 0.002, coor_y - radius_y / 3);
		glVertex2f(coor_x- 0.002, coor_y + radius_y / 3);
		glVertex2f(coor_x + 0.002, coor_y + radius_y / 3);

		//glBegin(GL_QUADS);
		//glVertex2f(coor_x + (radius_x / 10) - 0.002, coor_y - radius_y / 3);
		//glVertex2f(coor_x + (radius_x / 10)+ 0.002, coor_y - radius_y / 3);
		//glVertex2f(coor_x + (radius_x / 10)+ 0.002, coor_y + radius_y / 3);
		//glVertex2f(coor_x + (radius_x / 10) - 0.002, coor_y + radius_y / 3);

		glColor3f(0.7f, 0.7f, 0.7f);
		glBegin(GL_QUADS);
		glVertex2f(coor_x - radius_y / 2, coor_y + 0.002);
		glVertex2f(coor_x - radius_y / 2, coor_y - 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y - 0.002);
		glVertex2f(coor_x + radius_y / 2, coor_y + 0.002);
	}
};
