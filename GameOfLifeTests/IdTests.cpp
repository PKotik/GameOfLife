#include "pch.h"
#include "gtest/gtest.h"
#include "../GameOfLife/ObjectWithId.h"

TEST(ObjectWithIdTests, CreateIdsTest)
{
    ObjectWithId obj1(0.625f, 0.125f);
    ObjectWithId obj2(0.637f, 0.119f);
    ObjectWithId obj3(0.653f, 0.119f);
    ObjectWithId obj4(0.637f, 0.93f);

    EXPECT_TRUE(obj1.Id() == obj2.Id());
    EXPECT_TRUE(obj1.Id() != obj3.Id());
    EXPECT_TRUE(obj1.Id() != obj4.Id());
}

TEST(ObjectWithIdTests, RoundXYTest)
{
    float x1 = 0.625f;
    float y1 = 0.125f;
    float x2 = 0.637f;
    float y2 = 0.136f;
    Coordinate coor1(x1, y1, Constants::lenXCell, Constants::lenYCell);
    Coordinate coor2(x2, y2);

    EXPECT_TRUE(coor2 == coor1);
    EXPECT_TRUE(x1 == ObjectWithId::RoundX(x2));
    EXPECT_TRUE(y1 == ObjectWithId::RoundY(y2));

    EXPECT_TRUE(coor1.X() == ObjectWithId::RoundCoor(coor2).X());
    EXPECT_TRUE(coor1.Y() == ObjectWithId::RoundCoor(coor2).Y());
}