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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Structure structure;
    Button StartStopButton("Button_Start_Stop", Coordinate(-0.98, -0.98, 0.15, 0.055), Constants::ButtonDefColor, Start, Stop);
    Button SpeedUpButton("Button_Speed_Up", Coordinate(-0.98, -0.915, 0.07, 0.04), Constants::ButtonDefColor, SpeedUp, Constants::SpeedTimeOut);
    Button SpeedDownButton("Button_Speed_Down", Coordinate(-0.90, -0.915, 0.07, 0.04), Constants::ButtonDefColor, SpeedDown, Constants::SpeedTimeOut);

    std::list<Button> Buttons;

    Buttons.push_back(StartStopButton);
    Buttons.push_back(SpeedUpButton);
    Buttons.push_back(SpeedDownButton);

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
            default:
                break;
            }
        }

        Coordinate coor = InputCore::GetCursorCoordinates();
        for (auto& button : Buttons)
        {
            if (coor == button.coor())
                button.Select(Constants::ButtonDefSelectColor);
            else
                button.NotSelect(Constants::ButtonDefColor);
        }


        // TODO : продумать, чтобы те, что уходят далеко, не существовали 

        for (auto& [id, cell] : structure.GetAll())
        {
            GraphicCore::Draw(cell);

            if (!GameInfo::IsPause())
            {
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
