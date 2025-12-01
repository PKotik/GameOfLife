#pragma once
#include "Cell.h"
#include <map>

namespace SystemData
{
    const std::vector<Cell> Glider = {
    Cell(Coordinate(0.0f, 0.0f)),
    Cell(Coordinate(1 * Constants::Step, 1 * Constants::Step)),
    Cell(Coordinate(2 * Constants::Step, 1 * Constants::Step)),
    Cell(Coordinate(1 * Constants::Step, 2 * Constants::Step)),
    Cell(Coordinate(2 * Constants::Step, 0 * Constants::Step))
    };

    const std::vector<Cell> GliderCannon = {
        Cell(Coordinate(0.0f, 0.0f)),
        Cell(Coordinate(1 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step, -2 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step, -1 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step,  0 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step,  0 * Constants::Step)),
        Cell(Coordinate(-1 * Constants::Step, 3 * Constants::Step)),
        Cell(Coordinate(-1 * Constants::Step,-3 * Constants::Step)),
        Cell(Coordinate(-2 * Constants::Step, 3 * Constants::Step)),
        Cell(Coordinate(-2 * Constants::Step,-3 * Constants::Step)),
        Cell(Coordinate(-3 * Constants::Step, 2 * Constants::Step)),
        Cell(Coordinate(-3 * Constants::Step,-2 * Constants::Step)),
        Cell(Coordinate(-4 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-4 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(-4 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(-13 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-14 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-13 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(-14 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(8 * Constants::Step,  0 * Constants::Step)),
        Cell(Coordinate(10 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(10 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,  3 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,  3 * Constants::Step)),
        Cell(Coordinate(8 * Constants::Step,  4 * Constants::Step)),
        Cell(Coordinate(10 * Constants::Step, 4 * Constants::Step)),
        Cell(Coordinate(10 * Constants::Step, 5 * Constants::Step)),
        Cell(Coordinate(20 * Constants::Step, 2 * Constants::Step)),
        Cell(Coordinate(20 * Constants::Step, 3 * Constants::Step)),
        Cell(Coordinate(21 * Constants::Step, 2 * Constants::Step)),
        Cell(Coordinate(21 * Constants::Step, 3 * Constants::Step))
    };

    const std::vector<Cell> Pulsar = {
        Cell(Coordinate(0.0f, 0.0f)),
        Cell(Coordinate(-1 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(0 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,  0 * Constants::Step)),
        Cell(Coordinate(5 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,  1 * Constants::Step))
    };

    const std::vector<Cell> Prison = {
        Cell(Coordinate(0.0f, 0.0f)),
        Cell(Coordinate(-1 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-1 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(-1 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(-1 * Constants::Step,-2 * Constants::Step)),
        Cell(Coordinate(0 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step,  2 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step,  1 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step,  0 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step, -1 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step, -2 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step, -3 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step, -3 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step, -3 * Constants::Step)),
        Cell(Coordinate(0 * Constants::Step, -3 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step, -1 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step, -2 * Constants::Step)),
        Cell(Coordinate(-3 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-4 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(-3 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(-4 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step, 4 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step, 4 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step, 5 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step, 5 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(6 * Constants::Step,-2 * Constants::Step)),
        Cell(Coordinate(7 * Constants::Step,-2 * Constants::Step)),
        Cell(Coordinate(0 * Constants::Step,-5 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step,-5 * Constants::Step)),
        Cell(Coordinate(0 * Constants::Step,-6 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step,-6 * Constants::Step))
    };

    const std::vector<Cell> Horse = {
        Cell(Coordinate(0.0f, 0.0f)),
        Cell(Coordinate(0 * Constants::Step, 2 * Constants::Step)),
        Cell(Coordinate(1 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(2 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step,-1 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step, 0 * Constants::Step)),
        Cell(Coordinate(4 * Constants::Step, 1 * Constants::Step)),
        Cell(Coordinate(3 * Constants::Step, 2 * Constants::Step))
    };

    float pause_x = -0.910;
    float pause_y = -0.9510;
    float speed_up_x = -0.950;
    float speed_down_x = -0.870;
    float speed_y = -0.890;
    float random_y = -0.7915;
    float clear_x = 0.895;

    std::map<std::string, std::vector<GraphicClass>> Symbols() {
        std::map<std::string, std::vector<GraphicClass>> dict;

        // Ключ: pause - два вертикальных прямоугольника (как в плеере для паузы)
        dict["pause"] = {
            // Левый прямоугольник (3x5 пикселей)
            GraphicClass(Coordinate(pause_x, pause_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, pause_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, pause_y - 4 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Правый прямоугольник (с отступом 2 пикселя)
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y - 4 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        // Ключ: play - треугольник (стрелка вправо)
        dict["play"] = {
            GraphicClass(Coordinate(pause_x + 0 * Constants::Pixel, pause_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 0 * Constants::Pixel, pause_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 1 * Constants::Pixel, pause_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 0 * Constants::Pixel, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 1 * Constants::Pixel, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 0 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 1 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 0 * Constants::Pixel, pause_y - 4 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        // Ключ: speed_up - плюсик
        dict["speed_up"] = {
            // Вертикальная линия
            GraphicClass(Coordinate(speed_up_x + Constants::Pixel, speed_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_up_x + Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_up_x + Constants::Pixel, speed_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Горизонтальная линия
            GraphicClass(Coordinate(speed_up_x, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_up_x + 2 * Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_up_x + Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        // Ключ: speed_down - минус
        dict["speed_down"] = {
            GraphicClass(Coordinate(speed_down_x, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_down_x + Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_down_x + 2 * Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(speed_down_x + 3 * Constants::Pixel, speed_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        // Ключ: random - буква R (3x5 пикселей)
        dict["random"] = {
            // Вертикальная линия
            GraphicClass(Coordinate(pause_x, random_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, random_y - Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, random_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, random_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x, random_y - 4 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Верхняя горизонтальная линия
            GraphicClass(Coordinate(pause_x + Constants::Pixel, random_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, random_y - 1 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Средняя горизонтальная линия
            GraphicClass(Coordinate(pause_x + Constants::Pixel, random_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, random_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Диагональ
            GraphicClass(Coordinate(pause_x + Constants::Pixel, random_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(pause_x + 2 * Constants::Pixel, random_y - 4 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        // Ключ: clear - буквы "Cl" (каждая 3x5 пикселей)
        dict["clear"] = {
            // Буква C
            GraphicClass(Coordinate(clear_x, pause_y + Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + Constants::Pixel, pause_y + Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 2 * Constants::Pixel, pause_y + Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x, pause_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x, pause_y - 1 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 2 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),

            // Буква l (с отступом 4 пикселя от C)
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel, pause_y + Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel, pause_y, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel, pause_y - 1 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel, pause_y - 2 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel + Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black),
            GraphicClass(Coordinate(clear_x + 4 * Constants::Pixel + 2 * Constants::Pixel, pause_y - 3 * Constants::Pixel, Constants::Pixel, Constants::Pixel), Constants::Black)
        };

        return dict;
    }

}
