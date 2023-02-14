#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW  9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
//初始化排雷界面
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void PrintBoard(char arr[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char arr[ROWS][COLS], int row, int col);
//排查雷
void RemoveMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
