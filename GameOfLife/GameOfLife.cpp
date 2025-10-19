#include <iostream>
#include "Cell.h"
#include <chrono>
#include <thread>
#include <windows.h>
#include <windowsx.h>
#include <conio.h>
#include <winuser.h>
#include <cmath>
#include "ButtonStart.h"
#include "Data.h"
#include "GraphicCore.h"
#include "Structure.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    int k;
    Structure structure;
    Cell cell(0.5, 0.5);
    Cell cell2(0.525, 0.475);
    Cell cell3(0.55, 0.475);
    Cell cell4(0.55, 0.5);
    Cell cell5(0.55, 0.525);
    structure.Add(cell);
    structure.Add(cell2);
    structure.Add(cell3);
    structure.Add(cell4);
    structure.Add(cell5);
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

        for (auto& [id, cell] : structure.GetAll())
        {
            GraphicCore::Draw(cell);
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
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        structure.UpdateMap();

        GraphicCore::RefreshFrame();
    }
    return 0;
}
