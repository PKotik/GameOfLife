#pragma once
#include <GLFW/glfw3.h>
#include "Constants.h"

class MainCore
{
protected:
    inline static GLFWwindow* window;
    inline static int isGlFWInit = 0;

    static void GLFWDeInit()
    {
        glfwTerminate();
    }

    static void GLWindowInit()
    {
        isGlFWInit = glfwInit();
        if (isGlFWInit != 1)
            return;
        window = glfwCreateWindow(Constants::resolutionX, Constants::resolutionY, "Life", NULL, NULL);
        if (!window)
        {
            GLFWDeInit();
            return;
        }
        glfwMakeContextCurrent(window);
    };

};