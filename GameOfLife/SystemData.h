#pragma once
#include "Cell.h"

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

}
