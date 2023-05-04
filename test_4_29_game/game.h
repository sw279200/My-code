#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 30               
#define COL 30
#define Player1 1
#define Player2 2
#define CONTINUE 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DROW   3

enum dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_UP,
	RIGHT_UP,
	LEFT_DOWN,
	RIGHT_DOWN
};


void menu();

void game();

void ShowChessBoard(int chessboard[ROW][COL]);

int IsOver(int chessboard[ROW][COL]);

void PlayerMove(int chessboard[ROW][COL], int who);

int ChessCount(int chessboard[ROW][COL], enum dir d);


