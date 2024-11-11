#pragma once
struct Cell
{
public:
	char coor_x; char coor_y;
	char envir; bool condition;
	float time_live;
};
