#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game2.h"
#include"game3.h"
void menu()
{
	printf("**************************\n");
	printf("******* 0.退出游戏 *******\n");
	printf("******* 1.猜数字   *******\n");
	printf("******* 2.三子棋   *******\n");
	printf("******* 3.扫雷     *******\n");
	printf("**************************\n");
}

void game1()
{
	int num = 0;
	int ret = rand() % 100 + 1;//得到一个1-100的随机数 
	while (1)
	{
		printf("请猜该数字：>");
		scanf("%d", &num);
		if (num > ret)
		{
			printf("猜大了!\n");
		}
		else if (num < ret)
		{
			printf("猜小了!\n");
		}
		else
		{
			printf("恭喜你！猜对了！\n");
			break;
		}
	}

}
void game2()
{
	//需要一个3*3的二维数组存放数据
	char board[3][3] = { 0 };
	//初始化棋盘
	initBoard(board,Row,Col);
	//打印棋盘
	DisplayBoard(board, Row, Col);
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, Row, Col);
		// 打印棋盘
		DisplayBoard(board, Row, Col);
		// 判断输赢
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, Row, Col);
		//打印棋盘
		DisplayBoard(board, Row, Col);
		//判断输赢
		IsWin(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("恭喜你获胜啦！\n");

	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}

}
void game3()
{
	//建立两个数组分别存放数据
	char mine[ROWS][COLS] = { 0 };//用来存放布置雷的信息的数组
	char show[ROWS][COLS] = { 0 };//用来存放排查雷的信息的数组
	//初始化排查雷的棋盘
	InitBoard(mine, ROWS, COLS, '0');
	//初始化布置雷的棋盘
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	PrintBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//排雷
	RemoveMine(mine, show, ROW, COL);

}
int main()
{

	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏!\n");
			break;
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 3:
			game3();
		default:
			printf("选择错误，请重新输入!\n");
		}
	} while (input);
	return 0;
}