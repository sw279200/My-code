#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define Row 3
#define Col 3

//��ʼ������
void initBoard(char board[Row][Col], int row, int col);
//��ӡ����
void DisplayBoard(char board[Row][Col], int row, int col);

void PlayerMove(char board[Row][Col], int row, int col);

void ComputerMove(char board[Row][Col], int row, int col);

char IsWin(char board[Row][Col], int row, int col);
