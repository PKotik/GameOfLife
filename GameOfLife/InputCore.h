#pragma once
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>
#include <iostream>
#include "Coordinate.h"
#include "MainCore.h"

enum class InputKey 
{ 
    MouseLeft,
    MouseRight,
    Space,
    Delete
};

struct InputEvent 
{
private:
    InputKey _key;
    Coordinate _coor;
public:
    InputEvent(InputKey k, Coordinate c): _key(k), _coor(c) {}
    InputEvent(InputKey k) : _key(k), _coor() {}
    InputKey Key() const { return _key; }
    Coordinate Coor() const { return _coor; }
};

class InputCore : public MainCore
{
private:
    inline static std::queue<InputEvent> eventQueue;
    inline static std::mutex queueMutex;
    inline static std::atomic<bool> running;
    inline static std::thread inputThread;

public:
    static void Start();
    static void Stop();
    static bool HasEvents();
    static InputEvent GetNextEvent();
    static Coordinate GetCursorCoordinates();


private:
    static void ProcessInput();
    static void PushEvent(const InputEvent& e);
};
