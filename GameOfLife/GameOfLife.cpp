#include <GLFW/glfw3.h>
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

Cell Living_Cells[10000];
Cell Future_Cells[10000];
int size = sizeof(Living_Cells) / sizeof(Cell);
float radius = 0.0170/2;
float radius_field = 0.0190/2;

int resolution_x = 1920;
int resolution_y = 1080;

int scale_x = 40;
int scale_y = 40;

void PaintField()
{
    for (float x = -scale_x; x <= scale_x; x++)
    {
        for (float y = -scale_y; y <= scale_y; y++)
        {
            glBegin(GL_QUADS);
            glColor3f(0.1f, 0.1f, 0.1f);
            glVertex2f(x / scale_x - radius_field, y / scale_y - radius_field);
            glVertex2f(x / scale_x - radius_field, y / scale_y + radius_field);
            glVertex2f(x / scale_x+ radius_field, y / scale_y + radius_field);
            glVertex2f(x / scale_x+ radius_field, y / scale_y- radius_field);

        }
    }
}

void PaintCell(GLFWwindow* window, Cell(&mas)[10000])
{
    float fl_x;
    float fl_y;
    int k;
    for (int j = 0; j < sizeof(mas) / sizeof(Cell); j++)
    {
        if (mas[j].condition == true)
        {
            fl_x = mas[j].coor_x;
            fl_y = mas[j].coor_y;
            glBegin(GL_QUADS);
            glColor3f(0.5f  , 1.0f  , 1.0f  );
            glVertex2f(fl_x / scale_x - radius, fl_y / scale_y - radius);
            glVertex2f(fl_x / scale_x - radius, fl_y / scale_y + radius);
            glColor3f(0.0f+mas[j].time_live, 0.0f + mas[j].time_live, 1.0f + mas[j].time_live);
            glVertex2f(fl_x / scale_x + radius, fl_y / scale_y + radius);
            glVertex2f(fl_x / scale_x + radius, fl_y / scale_y - radius);

        }
        
    }

}

bool Indentification(int x, int y, Cell(&mas)[10000])
{
    for (int i = 0; i < sizeof(mas) / sizeof(Cell); i++)
    {
        if (mas[i].coor_x == x && mas[i].coor_y == y && mas[i].condition == true) return true;
    }
    return false;
}

int Count_Envir(Cell cell, Cell(&mas)[10000])
{
    int count = 0;
    for (int j = 0; j < sizeof(mas) / sizeof(Cell); j++)
    {
        if ((mas[j].condition == true) && (abs(mas[j].coor_x - cell.coor_x) < 2) &&
            (abs(mas[j].coor_y - cell.coor_y) < 2))
        {
            count++;
        }
    }
    return count;
}

void Random_Generation()
{
    
    int x; int y; int z;
    z = rand() % ((sizeof(Living_Cells) / sizeof(Cell)));
    while (z < ((sizeof(Living_Cells) / sizeof(Cell)))/1.4 ) z *= 1.4;
    for (int j = (sizeof(Living_Cells) / sizeof(Cell))-1; j >=z; j--)
    {
        x = (rand() % (scale_x * 2)) - scale_x;
        y = (rand() % (scale_y * 2)) - scale_y;
        if (Indentification(x, y, Living_Cells) == false)
        {
            Living_Cells[j].coor_x = x;
            Living_Cells[j].coor_y = y;
            Living_Cells[j].condition = true;
        }
    }
}

void Create_Shape(int speedxPos0, int speedyPos0, int num_shape, Shapes Shape)
{
    int quality_count = 0;
    int dop_x = 0;
    int dop_y = 0;
    for (int quality = 0; quality < size; quality++)
    {
        if (Living_Cells[quality].condition == false)
        {
            if (num_shape == 1)
            {
                Living_Cells[quality].coor_x = speedxPos0 + dop_x;
                Living_Cells[quality].coor_y = speedyPos0 + dop_y;
                Living_Cells[quality].condition = true;
                dop_x = Shape.Glider[quality_count][0];
                dop_y = Shape.Glider[quality_count][1];
                quality_count++;
                if (dop_x == 111) break;
            }
            if (num_shape == 2)
            {
                Living_Cells[quality].coor_x = speedxPos0 + dop_x;
                Living_Cells[quality].coor_y = speedyPos0 + dop_y;
                Living_Cells[quality].condition = true;
                dop_x = Shape.GliderCannon[quality_count][0];
                dop_y = Shape.GliderCannon[quality_count][1];
                quality_count++;
                if (dop_x == 111) break;
            }
            if (num_shape == 3)
            {
                Living_Cells[quality].coor_x = speedxPos0 + dop_x;
                Living_Cells[quality].coor_y = speedyPos0 + dop_y;
                Living_Cells[quality].condition = true;
                dop_x = Shape.Pulsar[quality_count][0];
                dop_y = Shape.Pulsar[quality_count][1];
                quality_count++;
                if (dop_x == 111) break;
            }
            if (num_shape == 4)
            {
                Living_Cells[quality].coor_x = speedxPos0 + dop_x;
                Living_Cells[quality].coor_y = speedyPos0 + dop_y;
                Living_Cells[quality].condition = true;
                dop_x = Shape.Prison[quality_count][0];
                dop_y = Shape.Prison[quality_count][1];
                quality_count++;
                if (dop_x == 111) break;
            }
            if (num_shape == 5)
            {
                Living_Cells[quality].coor_x = speedxPos0 + dop_x;
                Living_Cells[quality].coor_y = speedyPos0 + dop_y;
                Living_Cells[quality].condition = true;
                dop_x = Shape.Horse[quality_count][0];
                dop_y = Shape.Horse[quality_count][1];
                quality_count++;
                if (dop_x == 111) break;
            }

        }
    }
}



using namespace std::chrono;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(resolution_x, resolution_y, "Life", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
    {
        Living_Cells[i].condition = false;
        Living_Cells[i].time_live = 0.0;
    }


    int speed_time=100;
    int dop_time = 20;

    std::chrono::milliseconds time2 = std::chrono::milliseconds(10);
    std::chrono::milliseconds time1 = std::chrono::milliseconds(speed_time);
    std::chrono::milliseconds timedop = std::chrono::milliseconds(dop_time);
    double xPos;
    double yPos;
    double speedxPos;
    double speedyPos;
    double speedxPos0;
    double speedyPos0;
    float xPos0;
    float yPos0;
    int xPos1;
    int yPos1;
    bool sch = true;
    MSG msg;
    MSG msg1;
    bool left_click= (GetKeyState(VK_LBUTTON) && 0x01);
    bool start_click = (GetKeyState(VK_SPACE) && 0x20);
    bool num_click1 = (GetKeyState('1') && 0x31);
    bool num_click2 = (GetKeyState('2') && 0x32);
    bool num_click3 = (GetKeyState('3') && 0x33);
    bool  num_click4 = (GetKeyState('4') && 0x34);
    bool  num_click5 = (GetKeyState('5') && 0x35);
    bool tab_click0 = (GetKeyState(VK_DELETE) && 0x2E);
    bool flag_input = true;
    bool flag_start = false;
    bool backlightUp = false;
    bool backlightDown = false;
    bool backlightStart = false;
    int quality = 0;
    float up_color = 0;
    Shapes Shape;
    Button Button_Start;
    Button_Start.radius_x = radius_field * 6;
    Button_Start.radius_y = radius_field * 6;
    Button_Start.coor_x = -0.93;
    Button_Start.coor_y = -0.90;
    Button_Start.window = window;
    Button Button_SpeedUp;
    Button_SpeedUp.radius_x = radius_field * 3;
    Button_SpeedUp.radius_y = radius_field * 2;
    Button_SpeedUp.coor_x = -0.93 - (radius_field * 6)/2;
    Button_SpeedUp.coor_y = -0.80;
    Button_SpeedUp.window = window;
    Button Button_SpeedDown;
    Button_SpeedDown.radius_x = radius_field * 3;
    Button_SpeedDown.radius_y = radius_field * 2;
    Button_SpeedDown.coor_x = -0.93 + (radius_field * 6) / 2;
    Button_SpeedDown.coor_y = -0.80;
    Button_SpeedDown.window = window;
    Button Button_Random;
    Button_Random.radius_x = radius_field * 6;
    Button_Random.radius_y = radius_field * 6;
    Button_Random.coor_x = -0.93;
    Button_Random.coor_y = -0.70;
    Button_Random.window = window;
    
    //INTEX();
    /* Loop until the user closes the window */

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        char string = 's';
        srand(time(0));

        //GetMessage(&msg, NULL, 0, 0);
        //DispatchMessage(&msg);
        glfwGetCursorPos(window, &speedxPos, &speedyPos);
        speedxPos0 = (((speedxPos - resolution_x / 2) / (resolution_x / 2)));
        speedyPos0 = (((-speedyPos + resolution_y / 2) / (resolution_y / 2)));
        if ((Button_SpeedUp.coor_x - Button_SpeedUp.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedUp.coor_x + Button_SpeedUp.radius_x) &&
            ((Button_SpeedUp.coor_y - Button_SpeedUp.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedUp.coor_y + Button_SpeedUp.radius_y))
        {
            backlightUp = true;
        }
        else backlightUp = false;
        if ((Button_SpeedDown.coor_x - Button_SpeedDown.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedDown.coor_x + Button_SpeedDown.radius_x) &&
            ((Button_SpeedDown.coor_y - Button_SpeedDown.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedDown.coor_y + Button_SpeedDown.radius_y))
        {
            backlightDown = true;
        }
        else backlightDown = false;
        if ((Button_Start.coor_x - Button_Start.radius_x <= speedxPos0 && speedxPos0 <= Button_Start.coor_x + Button_Start.radius_x) &&
            ((Button_Start.coor_y - Button_Start.radius_y) <= speedyPos0 && speedyPos0 <= Button_Start.coor_y + Button_Start.radius_y))
        {
            backlightStart = true;
        }
        else backlightStart = false;
        if ((GetKeyState(VK_LBUTTON) & 0x01) != left_click)
        {
            left_click = (GetKeyState(VK_LBUTTON) & 0x01);
            speedxPos0 = (((speedxPos - resolution_x / 2) / (resolution_x / 2)));
            speedyPos0 = (((-speedyPos + resolution_y / 2) / (resolution_y / 2)));
            glfwGetCursorPos(window, &speedxPos, &speedyPos);
            if ((Button_SpeedUp.coor_x - Button_SpeedUp.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedUp.coor_x + Button_SpeedUp.radius_x) &&
                ((Button_SpeedUp.coor_y - Button_SpeedUp.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedUp.coor_y + Button_SpeedUp.radius_y))
            {
                time1 -= timedop;
            }
            if ((Button_SpeedDown.coor_x - Button_SpeedDown.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedDown.coor_x + Button_SpeedDown.radius_x) &&
                ((Button_SpeedDown.coor_y - Button_SpeedDown.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedDown.coor_y + Button_SpeedDown.radius_y))
            {
                time1 += timedop;
            }
            if ((Button_Start.coor_x - Button_Start.radius_x <= speedxPos0 && speedxPos0 <= Button_Start.coor_x + Button_Start.radius_x) &&
                ((Button_Start.coor_y - Button_Start.radius_y) <= speedyPos0 && speedyPos0 <= Button_Start.coor_y + Button_Start.radius_y))
            {
                flag_start = false;
                flag_input = true;
            }
        }
        
        //Paint_Text();
        PaintField();
        PaintCell(window, Living_Cells);
        Button_Random.BuildButton();
        Button_Random.PrintText_Rand();
        //Paint_Text();
        if (backlightStart == false)
        {
            Button_Start.BuildButton();
            if (flag_input == true) Button_Start.PrintText_Stop();
            
            if (flag_start == true) Button_Start.PrintText_Start();
        }
        else
        {
            Button_Start.Backlight();
            if (flag_input == true) Button_Start.PrintText_Stop();

            if (flag_start == true) Button_Start.PrintText_Start();
        }
        if (backlightDown == false)
        {
            Button_SpeedDown.BuildButton();
            Button_SpeedDown.PrintText_SpeedDown();
        }
        else
        {
            Button_SpeedDown.Backlight();
            Button_SpeedDown.PrintText_SpeedDown();
        }
        if (backlightUp == false)
        {
            Button_SpeedUp.BuildButton();
            Button_SpeedUp.PrintText_SpeedUp();
        }
        else
        {
            Button_SpeedUp.Backlight();
            Button_SpeedUp.PrintText_SpeedUp();
        }


        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();


        for (int i = 0; i < sizeof(Future_Cells) / sizeof(Cell); i++)
        {
            Future_Cells[i].condition = false;
            Future_Cells[i].time_live = 0.0;
        }
        std::this_thread::sleep_for(time1);
        if (flag_input == true)
        {          
            sch = true;
            while (true) 
            {
                GetMessage(&msg, NULL, 0, 0);
                DispatchMessage(&msg);
                if ((GetKeyState('1') && 0x31) != num_click1)
                {
                    num_click1 = (GetKeyState('1') && 0x31);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = round(((speedxPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    speedyPos0 = round(((-speedyPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    Create_Shape(speedxPos0, speedyPos0,1,Shape);
                    sch = false;
                    break;
                }
                if ((GetKeyState('2') && 0x32) != num_click2)
                {
                    num_click2 = (GetKeyState('2') && 0x32);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = round(((speedxPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    speedyPos0 = round(((-speedyPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    Create_Shape(speedxPos0, speedyPos0, 2, Shape);
                    sch = false;
                    break;
                }

                if ((GetKeyState('3') && 0x33) != num_click3)
                {
                    num_click3 = (GetKeyState('3') && 0x33);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = round(((speedxPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    speedyPos0 = round(((-speedyPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    Create_Shape(speedxPos0, speedyPos0, 3, Shape);
                    sch = false;
                    break;
                }
                if ((GetKeyState('4') && 0x34) != num_click4)
                {
                    num_click4 = (GetKeyState('4') && 0x34);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = round(((speedxPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    speedyPos0 = round(((-speedyPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    Create_Shape(speedxPos0, speedyPos0, 4, Shape);
                    sch = false;
                    break;
                }
                if ((GetKeyState('5') && 0x35) != num_click5)
                {
                    num_click5 = (GetKeyState('5') && 0x35);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = round(((speedxPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    speedyPos0 = round(((-speedyPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    Create_Shape(speedxPos0, speedyPos0, 5, Shape);
                    sch = false;
                    break;
                }

                if ((GetKeyState(VK_DELETE) && 0x2E) != tab_click0)
                {
                    tab_click0 = (GetKeyState(VK_DELETE) && 0x2E);
                    for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
                    {
                        Living_Cells[i].condition = false;
                        Living_Cells[i].time_live = 0;
                        Living_Cells[i].coor_x = 0;
                        Living_Cells[i].coor_y = 0;
                    }
                    sch = false;
                    break;
                }

                if ((GetKeyState(VK_SPACE) && 0x20) != start_click)
                {
                    start_click = (GetKeyState(VK_SPACE) && 0x20);
                    flag_start = true;
                    flag_input = false;
                    break;
                }
               
                if ((GetKeyState(VK_LBUTTON) && 0x01) != left_click) 
                {                   
                    left_click = (GetKeyState(VK_LBUTTON) && 0x01);
                    glfwGetCursorPos(window, &speedxPos, &speedyPos);
                    speedxPos0 = (((speedxPos - resolution_x / 2) / (resolution_x / 2)));
                    speedyPos0 = (((-speedyPos + resolution_y / 2) / (resolution_y / 2)));

                    if ((Button_SpeedUp.coor_x - Button_SpeedUp.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedUp.coor_x + Button_SpeedUp.radius_x) &&
                        ((Button_SpeedUp.coor_y - Button_SpeedUp.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedUp.coor_y + Button_SpeedUp.radius_y))
                    {
                        time1 -= timedop;
                        sch = false;
                        break;
                    }
                    if ((Button_SpeedDown.coor_x - Button_SpeedDown.radius_x <= speedxPos0 && speedxPos0 <= Button_SpeedDown.coor_x + Button_SpeedDown.radius_x) &&
                        ((Button_SpeedDown.coor_y - Button_SpeedDown.radius_y) <= speedyPos0 && speedyPos0 <= Button_SpeedDown.coor_y + Button_SpeedDown.radius_y))
                    {
                        time1 += timedop;
                        sch = false;
                        break;
                    }
                    if ((Button_Random.coor_x - Button_Random.radius_x <= speedxPos0 && speedxPos0 <= Button_Random.coor_x + Button_Random.radius_x) &&
                        ((Button_Random.coor_y - Button_Random.radius_y) <= speedyPos0 && speedyPos0 <= Button_Random.coor_y + Button_Random.radius_y))
                    {

                        Random_Generation();
                        sch = false;
                        flag_start = false;
                        flag_input = true;
                        break;
                    }

                    sch = true;
                    break;
                }
            }
            if (sch == true)
            {
                glfwGetCursorPos(window, &xPos, &yPos);
                xPos0 = (((xPos - resolution_x / 2) / (resolution_x / 2)));
                yPos0 = (((-yPos + resolution_y / 2) / (resolution_y / 2)));
                if ((Button_Start.coor_x - Button_Start.radius_x <= xPos0 && xPos0 <= Button_Start.coor_x + Button_Start.radius_x) &&
                    ((Button_Start.coor_y - Button_Start.radius_y) <= yPos0 && yPos0 <= Button_Start.coor_y + Button_Start.radius_y))
                {
                    flag_start = true;
                    flag_input = false;
                }
                if (flag_input == true)
                {
                    xPos1 = round(((xPos - resolution_x / 2) / (resolution_x / 2)) * scale_x);
                    yPos1 = round(((-yPos + resolution_y / 2) / (resolution_y / 2)) * scale_y);
                    if (Indentification(xPos1, yPos1, Living_Cells) == false)
                    {
                        for (quality = 0; quality < size; quality++)
                        {
                            if (Living_Cells[quality].condition == false)
                            {
                                Living_Cells[quality].coor_x = xPos1;
                                Living_Cells[quality].coor_y = yPos1;
                                Living_Cells[quality].condition = true;
                                break;
                            }
                        }

                    }
                    else
                    {
                        for (int k = 0; k < size; k++)
                        {
                            if (Living_Cells[k].coor_x == xPos1 && Living_Cells[k].coor_y == yPos1)
                            {
                                Living_Cells[k].condition = false;
                                break;
                            }
                        }
                    }
                }
            }

        }

        if (flag_start == true)
        {
            
            if ((GetKeyState(VK_SPACE) && 0x20) != start_click)
            {
                start_click = (GetKeyState(VK_SPACE) && 0x20);
                flag_start = false;
                flag_input = true;
            }

            Cell Dop_cell;
            Dop_cell.condition = true;
            Dop_cell.time_live = 0.0f;
            int fi = 0;
            for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
            {
                if (Living_Cells[i].condition == true)
                {
                    Living_Cells[i].envir = Count_Envir(Living_Cells[i], Living_Cells) - 1;
                    for (int sx = -1; sx < 2; sx++)
                    {
                        for (int sy = -1; sy < 2; sy++)
                        {
                            if ((sx != 0 || sy != 0) && (Indentification(Living_Cells[i].coor_x + sx, Living_Cells[i].coor_y + sy, Living_Cells) == false) &&
                                (Indentification(Living_Cells[i].coor_x + sx, Living_Cells[i].coor_y + sy, Future_Cells) == false))
                            {
                                Dop_cell.coor_x = Living_Cells[i].coor_x + sx;
                                Dop_cell.coor_y = Living_Cells[i].coor_y + sy;
                                if (Count_Envir(Dop_cell, Living_Cells) == 3) Future_Cells[fi++] = Dop_cell;
                            }
                        }
                    }
                }
            }

            fi = 0;
            for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
            {
                if (Living_Cells[i].envir != 2 && Living_Cells[i].envir != 3)
                {
                    Living_Cells[i].condition = false;
                    Living_Cells[i].time_live = 0.0;
                }
                else
                {
                    Living_Cells[i].time_live += 0.01;
                }
                   
                if (Living_Cells[i].condition == false) Living_Cells[i] = Future_Cells[fi++]; 
                
            }                                                                  
        }

    }

    glfwTerminate();
    return 0;
}
