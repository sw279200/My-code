#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"



void menu()
{
	printf("**************************\n");
	printf("******* 0.退出游戏 *******\n");
	printf("******* 1.扫雷游戏 *******\n");
	printf("**************************\n");
}

void game()
{
	//建立两个数组分别存放数据
	char mine[ROWS][COLS] = { 0 };//用来存放布置雷的信息的数组
	char show[ROWS][COLS] = { 0 };//用来存放排查雷的信息的数组
	//初始化排查雷的棋盘
	InitBoard(mine, ROWS, COLS,'0');
	//初始化布置雷的棋盘
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	PrintBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//排雷
	RemoveMine(mine,show,ROW,COL);

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
			game();
			break;
		default:
			printf("选择错误，请重新输入!\n");
		}
	}while (input);
	return 0;
}