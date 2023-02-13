#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("******* 排雷 *******\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}

}

//统计雷的个数
int MineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] +
		mine[x + 1][y + 1] + mine[x][y + 1] - 8 * '0');
}
void RemoveMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int safe = 0;
	while (safe<row*col-EASY_COUNT)
	{
		printf("请输入你要排查的坐标：>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//如果该坐标不是雷，就要统计该坐标周围有几个雷
					int count = MineCount(mine, x, y);
					show[x][y] = count + '0';
					PrintBoard(show, ROW, COL);
					safe++;
				}

			}
			else
			{
				printf("该坐标已经排查，请重新输入!\n");
			}
		}
		else
		{
			printf("你输入的坐标非法，请重新输入!\n");
		}
	}


}