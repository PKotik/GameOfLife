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

//Cell Living_Cells[6400];
//Cell Future_Cells[6400];
//int size = sizeof(Living_Cells) / sizeof(Cell);
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


struct Tree
{
    Cell* cell;
    Tree* right;
    Tree* left;
};


struct List
{
    Cell* cell;
    List* next;
};

List* CreateList(Cell* cell)
{
    List* tmp = (List*)malloc(sizeof(List));
    tmp->cell = cell;
    tmp->next = NULL;
    return tmp;
}

List* AddL(Cell* cell, List* list)
{
    if (list==NULL) return CreateList(cell);
    if (list->cell->coor_x == cell->coor_x && list->cell->coor_y == cell->coor_y) return list;
    List* tmp = CreateList(cell);
    tmp->next = list;
    return tmp;
    //while (list != NULL)
    //{
    //    if (list->cell->coor_x == cell->coor_x && list->cell->coor_y == cell->coor_y) return save;
    //    else list = list->next;
    //}
    //List* tmp = CreateList(cell);
    //list = tmp;
    //return save;
}

//List* DeleteAllList(List* list)
//{
//    if (list == NULL)
//    {
//        return NULL;
//    }
//    while (list->next != NULL)
//    {
//        List* save = list->next;
//        free(list);
//        list = list->next;
//    }
//    free(list);
//    list = NULL;
//    return list;
//}

int Averaga(int x, int y)
{
    return ((200+x) * 1000) + 200+y;
}

Tree* CreateNode(Cell* cell)
{
    Tree* tmp = (Tree*)malloc(sizeof(Tree));
    tmp->cell = cell;
    tmp->right = NULL;
    tmp->left = NULL;
   
    return tmp;
}

Tree* LiveTree = NULL;
List* Doomed_to_die = NULL;


Tree* Add(Cell* cell, Tree* tree)
{
    if (tree == NULL)
    {
        tree = CreateNode(cell);
        return tree;
    }
    //if (cell->Aver == tree->cell->Aver) return tree;
    else if (cell->Aver > tree->cell->Aver)
    {
        tree->right = Add(cell, tree->right);
        return tree;
    }
    else if (cell->Aver < tree->cell->Aver)
    {
        tree->left = Add(cell, tree->left);
        return tree;
    }
    return tree;
}



Tree* SpecDelete(Cell* cell, Tree* tree)
{
    if (tree == NULL) return NULL;

    if (cell->Aver == tree->cell->Aver)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            tree = NULL;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            Tree* t = tree;
            tree = tree->left;
            t = NULL;
        }

    }
    //else if (cell->Aver < tree->cell->Aver)
    //{
    //    if (tree->left != NULL)
    //    {
    //        tree->left = Delete(cell, tree->left);
    //    }
    //}
    //else if (cell->Aver > tree->cell->Aver)
    //{
    //    if (tree->right != NULL)
    //    {
    //        tree->right = Delete(cell, tree->right);
    //    }
    //}
    else
    {
        tree->right = SpecDelete(cell, tree->right);
    }
    return tree;
}


Tree* Delete(Cell* cell, Tree* tree)
{
    if (tree == NULL) return NULL;

    if (cell->Aver == tree->cell->Aver)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree->cell);
            free(tree);
            tree = NULL;
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            Tree* t = tree;
            tree = tree->right;
            free(t->cell);
            free(t);
            t = NULL;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            Tree* t = tree;
            tree = tree->left;
            free(t->cell);
            free(t);
            t = NULL;
        }
        else if (tree->left != NULL && tree->right != NULL)
        {
            Tree* t = tree;
            Tree* tmp = tree->left;
            Tree* save = tree;
            while (tmp->right != NULL)
            {
                tmp = tmp->right;
            }
            
            if (tmp != tree->left)
            {
                //Tree* s = tmp->left;
                //if (s != NULL)
                //{
                //    puts("123");
                //}

                tree->left = SpecDelete(tmp->cell, tree->left);
                tmp->left = tree->left;
            }
            tmp->right = tree->right;
            tree = tmp;
            free(t->cell);
            free(t);
            t = NULL;
        }


    }
    else if (cell->Aver < tree->cell->Aver)
    {
        if (tree->left != NULL)
        {
            tree->left = Delete(cell,tree->left);
        }
    }
    else if (cell->Aver > tree->cell->Aver)
    {
        if (tree->right != NULL)
        {
            tree->right = Delete(cell, tree->right);
        }
    }
    return tree;
}


Tree* DeleteAll(Tree* tree)
{
    if (tree == NULL) return NULL;
    tree = DeleteAll(tree->left);
    if (tree!=NULL) tree = Delete(tree->cell, tree);
    if (tree != NULL) tree = DeleteAll(tree->right);

    return NULL; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ЭТО ВРЕМЕННННООООООО!!!!!
}

//void DeleteAll(Tree* tree)
//{
//    if (tree == NULL) return;
//    DeleteAll(tree->left);
//    DeleteAll(tree->right);
//    free(tree);
//    tree = NULL;
//}

Cell* Search(int x, int y, Tree* tree)
{
    if (tree == NULL) return NULL;
    int a = Averaga(x, y);

    if (a == tree->cell->Aver)
    {
        return tree->cell;
    }
    else if (a < tree->cell->Aver)
    {
        if (tree->left == NULL)
        {
            return NULL;
        }

        else
        {
            return Search(x, y, tree->left);
        }
    }
    else if (a > tree->cell->Aver)
    {
        if (tree->right == NULL)
        {
            return NULL;
        }
        else
        {
            return Search(x, y, tree->right);
        }
    }

}





void PaintCellOne(GLFWwindow* window, Tree* tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        float fl_x;
        float fl_y;

        int k;

        fl_x = tree->cell->coor_x;
        fl_y = tree->cell->coor_y;
        glBegin(GL_QUADS);
        glColor3f(0.5f, 1.0f, 1.0f);
        glVertex2f(fl_x / scale_x - radius, fl_y / scale_y - radius);
        glVertex2f(fl_x / scale_x - radius, fl_y / scale_y + radius);
        glColor3f(0.0f + tree->cell->time_live, 0.0f + tree->cell->time_live, 1.0f + tree->cell->time_live);
        glVertex2f(fl_x / scale_x + radius, fl_y / scale_y + radius);
        glVertex2f(fl_x / scale_x + radius, fl_y / scale_y - radius);

    }
}

void PaintCell(GLFWwindow* window, Tree* tree)
{
    if (tree == NULL)
    {
        return;
    }
    PaintCell(window, tree->left);
    PaintCellOne(window, tree);
    
    PaintCell(window, tree->right);

}


//
//bool Indentification(int x, int y, Cell(&mas)[6400])
//{
//    for (int i = 0; i < sizeof(mas) / sizeof(Cell); i++)
//    {
//        if (mas[i].coor_x == x && mas[i].coor_y == y && mas[i].condition == true) return true;
//    }
//    return false;
//}



int Count_Envir(Cell *cell, Tree *tree)
{
    char x = cell->coor_x;
    char y = cell->coor_y;
    char count = 0;

    if (Search(x - 1, y + 1, tree)!=NULL) count++;
    if (Search(x - 1, y, tree) != NULL) count++;
    if (Search(x - 1, y - 1, tree) != NULL) count++;
    if (Search(x, y + 1, tree) != NULL) count++;
    if (Search(x, y - 1, tree) != NULL) count++;
    if (Search(x + 1, y + 1, tree) != NULL) count++;
    if (Search(x + 1, y, tree) != NULL) count++;
    if (Search(x + 1, y - 1, tree) != NULL) count++;

    return count;
    
    /*int count = 0;
    for (int j = 0; j < sizeof(mas) / sizeof(Cell); j++)
    {
        if ((mas[j].condition == true) && (abs(mas[j].coor_x - cell.coor_x) < 2) &&
            (abs(mas[j].coor_y - cell.coor_y) < 2))
        {
            count++;
        }
    }
    return count;*/
}


void Random_Generation(Tree** tree )
{
    int x; int y; int z;
    z = rand() % 3000;
    for (int i=0; i < z; i++)
    {
        Cell* cell = (Cell*)malloc(sizeof(Cell));
        cell->coor_x = (rand() % 80) - 40;
        cell->coor_y = (rand() % 80) - 40;
        cell->Aver = Averaga(cell->coor_x, cell->coor_y);
        cell->time_live = 0;
        *tree = Add(cell, *tree);
    }
}

void Create_Shape(int speedxPos0, int speedyPos0, int num_shape, Shapes Shape)
{
    int dop_x = 0;
    int dop_y = 0;
    if (num_shape == 1)
    {
        for (int i = 0; i < 40; i++)
        {
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            cell->coor_x = speedxPos0 + dop_x;
            cell->coor_y = speedyPos0 + dop_y;
            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
            cell->time_live = 0;
            LiveTree = Add(cell, LiveTree);
            dop_x = Shape.Glider[i][0];
            dop_y = Shape.Glider[i][1];
            if (dop_x == 111) break;
        }

    }
    if (num_shape == 2)
    {
        for (int i = 0; i < 40; i++)
        {
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            cell->coor_x = speedxPos0 + dop_x;
            cell->coor_y = speedyPos0 + dop_y;
            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
            cell->time_live = 0;
            LiveTree = Add(cell, LiveTree);
            dop_x = Shape.GliderCannon[i][0];
            dop_y = Shape.GliderCannon[i][1];
            if (dop_x == 111) break;
        }

    }
    if (num_shape == 3)
    {
        for (int i = 0; i < 40; i++)
        {
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            cell->coor_x = speedxPos0 + dop_x;
            cell->coor_y = speedyPos0 + dop_y;
            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
            cell->time_live = 0;
            LiveTree = Add(cell, LiveTree);
            dop_x = Shape.Pulsar[i][0];
            dop_y = Shape.Pulsar[i][1];
            if (dop_x == 111) break;
        }

    }
    if (num_shape == 4)
    {
        for (int i = 0; i < 40; i++)
        {
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            cell->coor_x = speedxPos0 + dop_x;
            cell->coor_y = speedyPos0 + dop_y;
            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
            cell->time_live = 0;
            LiveTree = Add(cell, LiveTree);
            dop_x = Shape.Prison[i][0];
            dop_y = Shape.Prison[i][1];
            if (dop_x == 111) break;
        }

    }
    if (num_shape == 5)
    {
        for (int i = 0; i < 40; i++)
        {
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            cell->coor_x = speedxPos0 + dop_x;
            cell->coor_y = speedyPos0 + dop_y;
            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
            cell->time_live = 0;
            LiveTree = Add(cell, LiveTree);
            dop_x = Shape.Horse[i][0];
            dop_y = Shape.Horse[i][1];
            if (dop_x == 111) break;
        }

    }
}

List* Children = NULL;


void MainCountEnvir(Tree* tree, List** dielist, List** bornlist, Tree* root)
{
    if (tree == NULL) return;
    
    char envir = Count_Envir(tree->cell, root);
    tree->cell->time_live += 0.005;
    tree->cell->envir = envir;
    if (envir != 2 && envir != 3)
    {
        *dielist = AddL(tree->cell, *dielist);
    }
    if (envir < 8)
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i != 0 || j != 0)
                {
                    if (Search(tree->cell->coor_x + i, tree->cell->coor_y + j, root) == NULL)
                    {
                        Cell* Dopcell = (Cell*)malloc(sizeof(Cell));
                        Dopcell->coor_x = tree->cell->coor_x + i;
                        Dopcell->coor_y = tree->cell->coor_y + j;
                        Dopcell->Aver = Averaga(Dopcell->coor_x, Dopcell->coor_y);
                        Dopcell->time_live = 0;
                        char dopenvir = Count_Envir(Dopcell, root);
                        if (dopenvir == 3)
                        {
                            *bornlist = AddL(Dopcell, *bornlist);
                        }
                        else
                        {
                            free(Dopcell);
                            Dopcell = NULL;
                        }
                    }
                }
            }
        }

    }
    MainCountEnvir(tree->left, dielist, bornlist, root);
    MainCountEnvir(tree->right, dielist, bornlist, root);
}



Tree* MainKiller(Tree* tree,  List* list)
{
    //if (list == NULL)
    //{
    //    return NULL;
    //}
    List* save = list;
    while (list != NULL)
    {
        tree = Delete(list->cell, tree);
        list = list->next;
    }
    list = save;
    return tree;
}

List* ClearList(List* list)
{
    while (list != NULL)
    {
        List* tmp = list->next;
        //free(list->cell);
        free(list);
        list = tmp;
    }
    return list;
}

Tree* MainBorner(Tree* tree, List* list)
{
    List* save = list;
    while (list != NULL)
    {
        tree = Add(list->cell, tree);
        list = list->next;
    }
    list = save;
    return tree;

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


    //for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
    //{
    //    Living_Cells[i].condition = false;
    //    Living_Cells[i].time_live = 0.0;
    //}


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
    char xPos1;
    char yPos1;
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
        if (LiveTree != NULL)
        {
            PaintCellOne(window, LiveTree);
            if (LiveTree->left != NULL)
            {
                PaintCellOne(window, LiveTree->left);
                PaintCell(window, LiveTree->left->left);
                PaintCell(window, LiveTree->left->right);
            }
            if (LiveTree->right != NULL)
            {
                PaintCellOne(window, LiveTree->right);
                PaintCell(window, LiveTree->right->left);
                PaintCell(window, LiveTree->right->right);
            }
        }
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


        //for (int i = 0; i < sizeof(Future_Cells) / sizeof(Cell); i++)
        //{
        //    Future_Cells[i].condition = false;
        //    Future_Cells[i].time_live = 0.0;
        //}
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
                    LiveTree = DeleteAll(LiveTree);
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

                        Random_Generation(&LiveTree);
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
                    Cell* cell = Search(xPos1, yPos1, LiveTree);
                    if (cell==NULL)
                    {
                        Cell* cell = (Cell*)malloc(sizeof(Cell));
                        cell->coor_x = xPos1;
                        cell->coor_y = yPos1;
                        cell->Aver = Averaga(xPos1, yPos1);
                        cell->time_live = 0;
                        LiveTree = Add(cell, LiveTree);
                    }
                    else
                    {
                        LiveTree = Delete(cell, LiveTree);
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


            MainCountEnvir(LiveTree, &Doomed_to_die, &Children, LiveTree);
            
            LiveTree = MainBorner(LiveTree, Children);
            LiveTree = MainKiller(LiveTree, Doomed_to_die);
            Doomed_to_die = ClearList(Doomed_to_die);
            Children = ClearList(Children);




/*            DeleteAll(LiveTree);

            for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
            {
                if (Living_Cells[i].condition == true)
                {
                    LiveTree = Add(&Living_Cells[i], LiveTree);
                }
            }


            Cell Dop_cell;
            Dop_cell.condition = true;
            Dop_cell.time_live = 0.0f;
            int fi = 0;
            for (int i = 0; i < sizeof(Living_Cells) / sizeof(Cell); i++)
            {
                if (Living_Cells[i].condition == true)
                {
                    Living_Cells[i].envir = Count_Envir(&Living_Cells[i], LiveTree);
                    for (int sx = -1; sx < 2; sx++)
                    {
                        for (int sy = -1; sy < 2; sy++)
                        {
                            if ((sx != 0 || sy != 0) && (Indentification(Living_Cells[i].coor_x + sx, Living_Cells[i].coor_y + sy, Living_Cells) == false) &&
                                (Indentification(Living_Cells[i].coor_x + sx, Living_Cells[i].coor_y + sy, Future_Cells) == false))
                            {
                                Dop_cell.coor_x = Living_Cells[i].coor_x + sx;
                                Dop_cell.coor_y = Living_Cells[i].coor_y + sy;
                                if (Count_Envir(&Dop_cell, LiveTree) == 3) Future_Cells[fi++] = Dop_cell;
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
                
            }   */                                                               
        }

    }

    glfwTerminate();
    return 0;
}
