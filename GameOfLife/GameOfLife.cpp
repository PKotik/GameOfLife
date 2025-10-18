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
#include "StructureCore.h"


float radius = 0.0170/2;
float radius_field = 0.0190/2;

int resolution_x = 1920;
int resolution_y = 1080;

int scale_x = 40; 
int scale_y = 40;

//struct Tree
//{
//    Cell* cell;
//    Tree* right;
//    Tree* left;
//};
//
//
//struct List
//{
//    Cell* cell;
//    List* next;
//};
//
//List* CreateList(Cell* cell)
//{
//    List* tmp = (List*)malloc(sizeof(List));
//    tmp->cell = cell;
//    tmp->next = NULL;
//    return tmp;
//}
//
//List* AddL(Cell* cell, List* list)
//{
//    if (list==NULL) return CreateList(cell);
//    if (list->cell->coor_x == cell->coor_x && list->cell->coor_y == cell->coor_y) return list; // addig cell to list
//    List* tmp = CreateList(cell);
//    tmp->next = list;
//    return tmp;
//}
//
//
//int Averaga(int x, int y)
//{
//    return ((200+x) * 1000) + 200+y; // unique number for every cell, it works like "hash" function
//}
//
//Tree* CreateNode(Cell* cell)
//{
//    Tree* tmp = (Tree*)malloc(sizeof(Tree));
//    tmp->cell = cell;
//    tmp->right = NULL;
//    tmp->left = NULL;
//   
//    return tmp;
//}
//
//
//Tree* LiveTree = NULL;
//List* Doomed_to_die = NULL;
//
//
//Tree* Add(Cell* cell, Tree* tree) // adding cell in tree
//{
//    if (tree == NULL)
//    {
//        tree = CreateNode(cell);
//        return tree;
//    }
//    else if (cell->Aver > tree->cell->Aver)
//    {
//        tree->right = Add(cell, tree->right);
//        return tree;
//    }
//    else if (cell->Aver < tree->cell->Aver)
//    {
//        tree->left = Add(cell, tree->left);
//        return tree;
//    }
//    return tree;
//}
//
//
//
//Tree* SpecDelete(Cell* cell, Tree* tree)
//{
//    if (tree == NULL) return NULL;
//
//    if (cell->Aver == tree->cell->Aver)
//    {
//        if (tree->left == NULL && tree->right == NULL)
//        {
//            tree = NULL;
//        }
//        else if (tree->left != NULL && tree->right == NULL)
//        {
//            Tree* t = tree;
//            tree = tree->left;
//            t = NULL;
//        }
//
//    }
//    else
//    {
//        tree->right = SpecDelete(cell, tree->right);
//    }
//    return tree;
//}
//
//
//Tree* Delete(Cell* cell, Tree* tree)
//{
//    if (tree == NULL) return NULL;
//
//    if (cell->Aver == tree->cell->Aver)
//    {
//        if (tree->left == NULL && tree->right == NULL)
//        {
//            free(tree->cell);
//            free(tree);
//            tree = NULL;
//        }
//        else if (tree->left == NULL && tree->right != NULL)
//        {
//            Tree* t = tree;
//            tree = tree->right;
//            free(t->cell);
//            free(t);
//            t = NULL;
//        }
//        else if (tree->left != NULL && tree->right == NULL)
//        {
//            Tree* t = tree;
//            tree = tree->left;
//            free(t->cell);
//            free(t);
//            t = NULL;
//        }
//        else if (tree->left != NULL && tree->right != NULL)
//        {
//            Tree* t = tree;
//            Tree* tmp = tree->left;
//            Tree* save = tree;
//            while (tmp->right != NULL)
//            {
//                tmp = tmp->right;
//            }
//            
//            if (tmp != tree->left)
//            {
//                tree->left = SpecDelete(tmp->cell, tree->left);
//                tmp->left = tree->left;
//            }
//            tmp->right = tree->right;
//            tree = tmp;
//            free(t->cell);
//            free(t);
//            t = NULL;
//        }
//    }
//    else if (cell->Aver < tree->cell->Aver)
//    {
//        if (tree->left != NULL)
//        {
//            tree->left = Delete(cell,tree->left);
//        }
//    }
//    else if (cell->Aver > tree->cell->Aver)
//    {
//        if (tree->right != NULL)
//        {
//            tree->right = Delete(cell, tree->right);
//        }
//    }
//    return tree;
//}
//
//
//Tree* DeleteAll(Tree* tree)
//{
//    if (tree == NULL) return NULL;
//    tree = DeleteAll(tree->left);
//    if (tree!=NULL) tree = Delete(tree->cell, tree);
//    if (tree != NULL) tree = DeleteAll(tree->right);
//    return NULL;
//}
//
//
//Cell* Search(int x, int y, Tree* tree) // searching for the cell in tree using it's unique number and return pointer for this cell
//{
//    if (tree == NULL) return NULL;
//    int a = Averaga(x, y);
//
//    if (a == tree->cell->Aver)
//    {
//        return tree->cell;
//    }
//    else if (a < tree->cell->Aver)
//    {
//        if (tree->left == NULL)
//        {
//            return NULL;
//        }
//
//        else
//        {
//            return Search(x, y, tree->left);
//        }
//    }
//    else if (a > tree->cell->Aver)
//    {
//        if (tree->right == NULL)
//        {
//            return NULL;
//        }
//        else
//        {
//            return Search(x, y, tree->right);
//        }
//    }
//
//}
//
//
//void PaintCellOne(GLFWwindow* window, Tree* tree)
//{
//    if (tree == NULL)
//    {
//        return;
//    }
//    else
//    {
//        float fl_x;
//        float fl_y;
//
//        int k;
//
//        fl_x = tree->cell->coor_x;
//        fl_y = tree->cell->coor_y;
//        glBegin(GL_QUADS);
//        glColor3f(0.5f, 1.0f, 1.0f);
//        glVertex2f(fl_x / scale_x - radius, fl_y / scale_y - radius);
//        glVertex2f(fl_x / scale_x - radius, fl_y / scale_y + radius);
//        glColor3f(0.0f + tree->cell->time_live, 0.0f + tree->cell->time_live, 1.0f + tree->cell->time_live);
//        glVertex2f(fl_x / scale_x + radius, fl_y / scale_y + radius);
//        glVertex2f(fl_x / scale_x + radius, fl_y / scale_y - radius);
//
//    }
//}
//
//void PaintCell(GLFWwindow* window, Tree* tree)
//{
//    if (tree == NULL)
//    {
//        return;
//    }
//    PaintCell(window, tree->left);
//    PaintCellOne(window, tree);
//    
//    PaintCell(window, tree->right);
//
//}
//
//int Count_Envir(Cell *cell, Tree *tree)
//{
//    char x = cell->coor_x;
//    char y = cell->coor_y;
//    char count = 0;
//
//    if (Search(x - 1, y + 1, tree)!=NULL) count++;
//    if (Search(x - 1, y, tree) != NULL) count++;
//    if (Search(x - 1, y - 1, tree) != NULL) count++;
//    if (Search(x, y + 1, tree) != NULL) count++;
//    if (Search(x, y - 1, tree) != NULL) count++;
//    if (Search(x + 1, y + 1, tree) != NULL) count++;
//    if (Search(x + 1, y, tree) != NULL) count++;
//    if (Search(x + 1, y - 1, tree) != NULL) count++;
//
//    return count;
//}
//
//void Random_Generation(Tree** tree )
//{
//    int x; int y; int z;
//    z = rand() % 3000;
//    for (int i=0; i < z; i++)
//    {
//        Cell* cell = (Cell*)malloc(sizeof(Cell));
//        cell->coor_x = (rand() % 80) - 40;
//        cell->coor_y = (rand() % 80) - 40;
//        cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//        cell->time_live = 0;
//        *tree = Add(cell, *tree);
//    }
//}
//
//void Create_Shape(int speedxPos0, int speedyPos0, int num_shape, Shapes Shape)
//{
//    int dop_x = 0;
//    int dop_y = 0;
//    if (num_shape == 1)
//    {
//        for (int i = 0; i < 40; i++)
//        {
//            Cell* cell = (Cell*)malloc(sizeof(Cell));
//            cell->coor_x = speedxPos0 + dop_x;
//            cell->coor_y = speedyPos0 + dop_y;
//            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//            cell->time_live = 0;
//            LiveTree = Add(cell, LiveTree);
//            dop_x = Shape.Glider[i][0];
//            dop_y = Shape.Glider[i][1];
//            if (dop_x == 111) break;
//        }
//
//    }
//    if (num_shape == 2)
//    {
//        for (int i = 0; i < 40; i++)
//        {
//            Cell* cell = (Cell*)malloc(sizeof(Cell));
//            cell->coor_x = speedxPos0 + dop_x;
//            cell->coor_y = speedyPos0 + dop_y;
//            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//            cell->time_live = 0;
//            LiveTree = Add(cell, LiveTree);
//            dop_x = Shape.GliderCannon[i][0];
//            dop_y = Shape.GliderCannon[i][1];
//            if (dop_x == 111) break;
//        }
//
//    }
//    if (num_shape == 3)
//    {
//        for (int i = 0; i < 40; i++)
//        {
//            Cell* cell = (Cell*)malloc(sizeof(Cell));
//            cell->coor_x = speedxPos0 + dop_x;
//            cell->coor_y = speedyPos0 + dop_y;
//            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//            cell->time_live = 0;
//            LiveTree = Add(cell, LiveTree);
//            dop_x = Shape.Pulsar[i][0];
//            dop_y = Shape.Pulsar[i][1];
//            if (dop_x == 111) break;
//        }
//
//    }
//    if (num_shape == 4)
//    {
//        for (int i = 0; i < 40; i++)
//        {
//            Cell* cell = (Cell*)malloc(sizeof(Cell));
//            cell->coor_x = speedxPos0 + dop_x;
//            cell->coor_y = speedyPos0 + dop_y;
//            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//            cell->time_live = 0;
//            LiveTree = Add(cell, LiveTree);
//            dop_x = Shape.Prison[i][0];
//            dop_y = Shape.Prison[i][1];
//            if (dop_x == 111) break;
//        }
//
//    }
//    if (num_shape == 5)
//    {
//        for (int i = 0; i < 40; i++)
//        {
//            Cell* cell = (Cell*)malloc(sizeof(Cell));
//            cell->coor_x = speedxPos0 + dop_x;
//            cell->coor_y = speedyPos0 + dop_y;
//            cell->Aver = Averaga(cell->coor_x, cell->coor_y);
//            cell->time_live = 0;
//            LiveTree = Add(cell, LiveTree);
//            dop_x = Shape.Horse[i][0];
//            dop_y = Shape.Horse[i][1];
//            if (dop_x == 111) break;
//        }
//
//    }
//}
//
//List* Children = NULL;


//void MainCountEnvir(Tree* tree, List** dielist, List** bornlist, Tree* root)
//{
//    if (tree == NULL) return;
//    
//    char envir = Count_Envir(tree->cell, root);
//    tree->cell->time_live += 0.005;
//    tree->cell->envir = envir;
//    if (envir != 2 && envir != 3)
//    {
//        *dielist = AddL(tree->cell, *dielist);
//    }
//    if (envir < 8)
//    {
//        for (int i = -1; i <= 1; i++)
//        {
//            for (int j = -1; j <= 1; j++)
//            {
//                if (i != 0 || j != 0)
//                {
//                    if (Search(tree->cell->coor_x + i, tree->cell->coor_y + j, root) == NULL)
//                    {
//                        Cell* Dopcell = (Cell*)malloc(sizeof(Cell));
//                        Dopcell->coor_x = tree->cell->coor_x + i;
//                        Dopcell->coor_y = tree->cell->coor_y + j;
//                        Dopcell->Aver = Averaga(Dopcell->coor_x, Dopcell->coor_y);
//                        Dopcell->time_live = 0;
//                        char dopenvir = Count_Envir(Dopcell, root);
//                        if (dopenvir == 3)
//                        {
//                            *bornlist = AddL(Dopcell, *bornlist);
//                        }
//                        else
//                        {
//                            free(Dopcell);
//                            Dopcell = NULL;
//                        }
//                    }
//                }
//            }
//        }
//
//    }
//    MainCountEnvir(tree->left, dielist, bornlist, root);
//    MainCountEnvir(tree->right, dielist, bornlist, root);
//}
//
//
//Tree* MainKiller(Tree* tree,  List* list)
//{
//    List* save = list;
//    while (list != NULL)
//    {
//        tree = Delete(list->cell, tree); // delete cell from the tree
//        list = list->next;
//    }
//    list = save;
//    return tree;
//}
//
//List* ClearList(List* list)
//{
//    while (list != NULL)
//    {
//        List* tmp = list->next;
//        free(list); // clearing list
//        list = tmp;
//    }
//    return list;
//}
//
//Tree* MainBorner(Tree* tree, List* list)
//{
//    List* save = list;
//    while (list != NULL)
//    {
//        tree = Add(list->cell, tree); // add cell to the tree
//        list = list->next;
//    }
//    list = save;
//    return tree;
//
//}

using namespace std::chrono;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    int k;
    StructureCore structureCore;
    Cell cell(0.5, 0.5);
    Cell cell2(0.525, 0.5);
    Cell cell3(0.5, 0.525);
    Cell cell4(0.550, 0.550);
    structureCore.Add(cell);
    structureCore.Add(cell2);
    structureCore.Add(cell3);
    structureCore.Add(cell4);
    while (GraphicCore::WindowIsAlive())
    {   
        
        for (float i = -1; i < 1; i += 0.025)
        {
            for (float j = -1; j < 1; j += 0.025)
            {
                GraphicCore::Draw(GraphicClass(Coordinate(i, j, Constants::lenXField, Constants::lenXField),
                    Constants::FieldColor, Constants::FieldOutline));
                Cell* now_cell = structureCore.Find(Coordinate(i,j));
                if (now_cell != nullptr)
                {
                    GraphicCore::Draw(*now_cell);
                }
            }
        }

        GraphicCore::RefreshFrame();
    }
    return 0;
}
