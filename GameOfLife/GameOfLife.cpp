#include <iostream>
#include "Cell.h"
#include <chrono>
#include <thread>
#include <windows.h>
#include <windowsx.h>
#include <conio.h>
#include <winuser.h>
#include <cmath>
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


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Structure structure;
    Button StartStopButton("Button_Start_Stop", Coordinate(-0.95, -0.95, 0.3, 0.2), Constants::ButtonStartColor, Start, Stop);
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
                Coordinate coor = InputCore::GetCursorCoordinates();
                if (coor == StartStopButton.coor())
                {
                    StartStopButton.Do();
                    break;
                }
                if (structure.IsIt(coor))
                {
                    break;
                }
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

        GraphicCore::Draw(StartStopButton);

        GraphicCore::RefreshFrame();
    }
    InputCore::Stop();
    return 0;
}
