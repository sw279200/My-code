#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	//需要一个3*3的二维数组存放数据
	char board[3][3] = { 0 };
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
			//玩家下棋
			PlayerMove(board, ROW, COL);
			// 打印棋盘
			DisplayBoard(board, ROW, COL);
			// 判断输赢
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			//电脑下棋
			ComputerMove(board, ROW, COL);
			//打印棋盘
			DisplayBoard(board, ROW, COL);
			//判断输赢
			IsWin(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
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
void menu()
{
	printf("**************************\n");
	printf("********* 1.play *********\n");
	printf("********* 0.exit *********\n");
	printf("**************************\n");
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!");
			break;
		default:
			printf("选择错误，请重新输入!");
			break;
		}
	} while (input);
	return 0;
    
}