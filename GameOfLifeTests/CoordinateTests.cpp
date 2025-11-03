#include "pch.h"
#include "gtest/gtest.h"
#include "../GameOfLife/Coordinate.h"

TEST(CoordinateTests, GetAdjCoorsTest)
{
	float s = Constants::Step;

    for (float x = 0, y = 0; x <= 3 * s && y <= 3 * s; x += s, y += s)
    {
        Coordinate coor1(x, y);

        auto coorArr = Coordinate::GetAdjCoors(coor1);

        EXPECT_TRUE(coorArr.size() == 8);

        int index = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = 1; j >= -1; j--)
            {
                if (i == 0 && j == 0) continue;
                auto coor = coorArr[index++];
                EXPECT_TRUE(coor.X() == x + s * i && coor.Y() == y + s * j);
            }
        }
    }

}
