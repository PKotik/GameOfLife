#include "GraphicCore.h"
#include "Coordinate.h"
#include "GraphicClass.h"
#include "Visual.h"
#include <queue>
#include <memory>
#include <vector>

bool GraphicCore::WindowIsAlive()
{
    bool isAlive = !glfwWindowShouldClose(window);

    if (!isAlive)
        GLFWDeInit();

    return isAlive;
}

GLFWwindow* GraphicCore::GetWindow()
{
    return window;
}

void GraphicCore::Draw(const GraphicClass& obj)
{
    if (obj.isEnable())
        drawQueue.push(obj);
}

void GraphicCore::RefreshFrame()
{
    if (!window || isGlFWInit == 0)
        GLWindowInit();

    glClear(GL_COLOR_BUFFER_BIT);

    while (!drawQueue.empty()) 
    {
        DrawObj(drawQueue.front());
        drawQueue.pop();
    }

    glEnd();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GraphicCore::DrawObj(const GraphicClass& obj)
{
    glBegin(GL_QUADS);
    if (obj.outline().isEnable)
    {
        Outline outline = obj.outline();
        SetColor(outline.ColorRGB);
        glVertex2f(obj.coor().X() - outline.Thick, obj.coor().Y() - outline.Thick);
        glVertex2f(obj.coor().X() - outline.Thick, obj.coor().farY() + outline.Thick);
        glVertex2f(obj.coor().farX() + outline.Thick, obj.coor().farY() + outline.Thick);
        glVertex2f(obj.coor().farX() + outline.Thick, obj.coor().Y() - outline.Thick);
    }

    SetColor(obj.color());
    glVertex2f(obj.coor().X(), obj.coor().Y());
    glVertex2f(obj.coor().X(), obj.coor().farY());
    glVertex2f(obj.coor().farX(), obj.coor().farY());
    glVertex2f(obj.coor().farX(), obj.coor().Y());
}

void GraphicCore::SetColor(const Color color)
{
    glColor3f(color.R, color.G, color.B);
}

