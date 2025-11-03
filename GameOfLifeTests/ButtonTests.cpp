#include "pch.h"
#include "gtest/gtest.h"
#include "../GameOfLife/Button.h"
#include <thread>

int TestParam = 0;

static void TestFunction()
{
    TestParam = 777;
}

static void TestDopFunction()
{
    TestParam = 666;
}

TEST(ButtonTests, DoButtonTest)
{
    const std::chrono::milliseconds TestTimeOut(20);
    TestParam = 0;
    Button TestButton("Button_Test", Coordinate(0, 0, 1, 1), Color(0,0,0),
        Color(1,1,1), TestFunction, TestDopFunction, TestTimeOut);

    EXPECT_TRUE(TestParam == 0);
    EXPECT_TRUE(!TestButton.State());

    TestButton.Do();

    EXPECT_TRUE(TestParam == 0);
    EXPECT_TRUE(!TestButton.State());

    std::this_thread::sleep_for(TestTimeOut);
    TestButton.Do();

    EXPECT_TRUE(TestParam == 777);
    EXPECT_TRUE(TestButton.State());

    TestButton.Do();

    EXPECT_TRUE(TestParam == 777);
    EXPECT_TRUE(TestButton.State());

    std::this_thread::sleep_for(TestTimeOut);
    TestButton.Do();

    EXPECT_TRUE(TestParam == 666);
    EXPECT_TRUE(!TestButton.State());
}

TEST(ButtonTests, SelectAndBotSelectButtonTest)
{
    Color color1(0, 1, 2);
    Color color2(1, 2, 3);
    Button TestButton("Button_Test", Coordinate(0, 0, 1, 1), color1,
        color2, TestFunction);

    EXPECT_TRUE(!TestButton.Selected());
    EXPECT_TRUE(TestButton.color().R == color1.R && TestButton.color().G == color1.G && TestButton.color().B == color1.B);
    TestButton.NotSelect();
    EXPECT_TRUE(TestButton.color().R == color1.R && TestButton.color().G == color1.G && TestButton.color().B == color1.B);
    TestButton.Select();
    EXPECT_TRUE(TestButton.Selected());
    EXPECT_TRUE(TestButton.color().R == color2.R && TestButton.color().G == color2.G && TestButton.color().B == color2.B);
    TestButton.Select();
    EXPECT_TRUE(TestButton.color().R == color2.R && TestButton.color().G == color2.G && TestButton.color().B == color2.B);
    TestButton.NotSelect();
    EXPECT_TRUE(!TestButton.Selected());
    EXPECT_TRUE(TestButton.color().R == color1.R && TestButton.color().G == color1.G && TestButton.color().B == color1.B);
}