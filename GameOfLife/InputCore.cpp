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
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::MouseLeft));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::CreateCellClickTimeOut));
        }
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::MouseRight));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::CreateCellClickTimeOut));
        }
        if (GetAsyncKeyState(VK_DELETE) & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Delete));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState('1') & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Key1));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState('2') & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Key2));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState('3') & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Key3));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState('4') & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Key4));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
        if (GetAsyncKeyState('5') & 0x8000)
        {
            PushEvent(InputEvent(InputKey::Key5));
            std::this_thread::sleep_for(std::chrono::milliseconds(Constants::DefaultTimeOut));
        }
    }
}