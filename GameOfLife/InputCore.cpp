#include "InputCore.h"
#include <iostream>
#include <windows.h>
#include "ObjectWithId.h"

void InputCore::Start() 
{
    if (!window || isGlFWInit == 0)
        GLWindowInit();
    running = true;
    inputThread = std::thread(&InputCore::ProcessInput);
}

void InputCore::Stop() {
    running = false;
    if (inputThread.joinable())
        inputThread.join();
}

bool InputCore::HasEvents() {
    std::lock_guard<std::mutex> lock(queueMutex);
    return !eventQueue.empty();
}

InputEvent InputCore::GetNextEvent() {
    std::lock_guard<std::mutex> lock(queueMutex);
    InputEvent e = eventQueue.front();
    eventQueue.pop();
    return e;
}

void InputCore::PushEvent(const InputEvent& e) {
    std::lock_guard<std::mutex> lock(queueMutex);
    eventQueue.push(e);
}

Coordinate InputCore::GetCursorCoordinates()
{
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);
    return Coordinate(ObjectWithId::RoundX((xPos / (Constants::resolutionX / 2)) - 1),
        ObjectWithId::RoundY(-(yPos / (Constants::resolutionY / 2)) + 1));
}

void InputCore::ProcessInput()
{
    while (running)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Space));
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::MouseLeft));
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::MouseRight));
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}