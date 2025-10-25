#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <windowsx.h>
#include <conio.h>
#include <winuser.h>
#include <cmath>
#include <list>
#include "Cell.h"
#include "Data.h"
#include "GraphicCore.h"
#include "Structure.h"
#include "InputCore.h"
#include "GameInfo.h"
#include "Button.h"
#include "SystemData.h"
#include <random>


Structure structure;

static void Start()
{
    GameInfo::Continue();
}
static void Stop()
{
    GameInfo::Pause();
}
static void SpeedUp()
{
    GameInfo::SpeedUp();
}
static void SpeedDown()
{
    GameInfo::SpeedDown();
}
static void ClearAll()
{
    structure.RemoveAll();
}


static void GenerateRandomPairs()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distN(500, 3000);
    int n = distN(gen);
    std::uniform_real_distribution<float> distFloat(-1.0f, 1.0f);
    std::vector<Cell> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        float x = distFloat(gen);
        float y = distFloat(gen);
        Coordinate coor(ObjectWithId::RoundX(x), ObjectWithId::RoundY(y));
        result.push_back(Cell(coor));
    }
    structure.AddMany(result);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    
    Button StartStopButton("Button_Start_Stop", Coordinate(-0.98, -0.98, 0.15, 0.055), Constants::ButtonDefColor,
        Constants::ButtonDefSelectColor, Start, Stop);
    Button SpeedUpButton("Button_Speed_Up", Coordinate(-0.98, -0.915, 0.07, 0.04), Constants::ButtonDefColor,
        Constants::ButtonDefSelectColor, SpeedUp, Constants::SpeedTimeOut);
    Button SpeedDownButton("Button_Speed_Down", Coordinate(-0.90, -0.915, 0.07, 0.04), Constants::ButtonDefColor,
        Constants::ButtonDefSelectColor, SpeedDown, Constants::SpeedTimeOut);
    Button RandomButton("Button_Random", Coordinate(-0.98, -0.82, 0.15, 0.055), Constants::ButtonDefColor,
        Constants::ButtonDefSelectColor, GenerateRandomPairs, Constants::RandomTimeOut);
    Button ClearButton("Button_Clear", Coordinate(0.83, -0.98, 0.15, 0.055), Constants::ButtonClearColor,
        Constants::ButtonSelectClearColor, ClearAll, Constants::DefaultTimeOut);

    std::list<Button> Buttons;

    Buttons.push_back(StartStopButton);
    Buttons.push_back(SpeedUpButton);
    Buttons.push_back(SpeedDownButton);
    Buttons.push_back(RandomButton);
    Buttons.push_back(ClearButton);

    InputCore::Start();

    while (GraphicCore::WindowIsAlive())
    {     

        for (float i = -1; i < 1; i += 0.025)
        {
            for (float j = -1; j < 1; j += 0.025)
            {
                GraphicCore::Draw(GraphicClass(Coordinate(i, j, Constants::lenXField, Constants::lenXField),
                    Constants::FieldColor, Constants::FieldOutline));
            }
        }

        // TODO : сделать лучше

        while (InputCore::HasEvents())
        {
            InputEvent event = InputCore::GetNextEvent();

            switch (event.Key())
            {
            case InputKey::Space:
            {
                GameInfo::ReversePause();
                break;
            }
            case InputKey::MouseLeft:
            {
                bool buttonClick = false;
                Coordinate coor = InputCore::GetCursorCoordinates();
                for (auto& button : Buttons)
                {
                    if (coor == button.coor())
                    {
                        button.Do();
                        buttonClick = true;
                        break;
                    }
                }
                if (buttonClick || structure.IsIt(coor))
                    break;
                structure.Add(Cell(coor));
                break;
            }
            case InputKey::MouseRight:
            {
                Coordinate coor = InputCore::GetCursorCoordinates();
                structure.Remove(coor);
                break;
            }
            case InputKey::Delete:
            {
                ClearAll();
                break;
            }
            case InputKey::Key1:
            {
                structure.AddMany(SystemData::Glider);
                break;
            }
            case InputKey::Key2:
            {
                structure.AddMany(SystemData::GliderCannon);
                break;
            }
            case InputKey::Key3:
            {
                structure.AddMany(SystemData::Pulsar);
                break;
            }
            case InputKey::Key4:
            {
                structure.AddMany(SystemData::Prison);
                break;
            }
            case InputKey::Key5:
            {
                structure.AddMany(SystemData::Horse);
                break;
            }
            default:
                break;
            }
        }

        Coordinate coor = InputCore::GetCursorCoordinates();
        for (auto& button : Buttons)
        {
            if (coor == button.coor())
                button.Select();
            else
                button.NotSelect();
        }


        // TODO : продумать, чтобы те, что уходят далеко, не существовали 

        for (auto& [id, cell] : structure.GetAll())
        {

            GraphicCore::Draw(cell);
            if (!GameInfo::IsPause())
            {
                cell.GrowOld();
                std::array<Coordinate, 8> arr = Coordinate::GetAdjCoors(cell.coor());
                for (auto& coor : arr)
                {
                    Cell newCell(coor);
                    if (structure.IsIt(coor))
                    {
                        cell.UpEnvir();
                    }
                    std::array<Coordinate, 8> newArr = Coordinate::GetAdjCoors(newCell.coor());
                    for (auto& newCoor : newArr)
                    {
                        if (structure.IsIt(newCoor))
                        {
                            newCell.UpEnvir();
                        }
                    }
                    if (newCell.GoodForBirth())
                    {
                        newCell.ResetEnvir();
                        structure.AddLater(newCell);
                    }
                }
                if (!cell.GoodForLife())
                    structure.RemoveLater(cell.coor());
                cell.ResetEnvir();
                GameInfo::NewGeneration();
            }
        }

        std::this_thread::sleep_for((GameInfo::Speed()));

        structure.UpdateMap();

        for (auto& button : Buttons)
            GraphicCore::Draw(button);

        GraphicCore::RefreshFrame();
    }
    InputCore::Stop();
    return 0;
}
