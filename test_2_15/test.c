#define _CRT_SECURE_NO_WARNINGS 1
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次
//#include<stdio.h>
//int main()
//{
//	int A, B, C, D, E;
//	for (A = 1; A <= 5; A++)
//	{
//		for (B = 1; B <= 5; B++)
//		{
//			for (C = 1; C <= 5; C++)
//			{
//				for (D = 1; D <= 5; D++)
//				{
//					for (E = 1; E <= 5; E++)
//					{
//						if ((B == 2 && A != 3) || (B != 2 && A == 3)==1)
//						{
//							if ((B == 2 && E != 4) || (B != 2 && E == 4)==1)
//							{
//								if ((C == 1 && D != 2) || (C != 1 && D == 2)==1)
//								{
//									if ((C == 5 && D != 3) || (C != 5 && D == 3) == 1)
//									{
//										if ((E == 4 && A != 1) || (E != 4 && A == 1))
//										{
//											if (A * B * C * D * E == 120)
//											{
//												printf("A=%d B=%d C=%d D=%d E=%d", A, B, C, D, E);
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	char killer = 'A';
//	for (killer = 'A'; killer <= 'D'; ++killer) {
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3) {
//			printf("killer is  %c\n", killer);
//		}
//
//	}
//	return 0;
//}
#include<stdio.h>
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
//int main()
//{
//	int n = 0;
//	int arr[20][20]={0};
//	//输入一个1-20的数
//	printf("请输入一个1到20的整数：>");
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//
//	for (i = 2; i < n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i - 1; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%-2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include<math.h>
//void printNumbers(int n)
//{
//	int i = 0;
//	for (i = 1; i < (int)pow(10, n); i++)
//	{
//		if (i == 1)
//		{
//			printf("[%d,", i);
//		}
//		else if (i == pow(10, n) - 1)
//		{
//			printf("%d]", i);
//		}
//		else
//		printf("%d,",i);
//
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printNumbers(n);
//	return 0;
//}
// 
// 
// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//1. 用返回一个整数列表来代替打印
//2. n 为正整数，0 < n <= 5
	//
//static int Arr[100001];
//int* printNumbers(int n, int* returnSize)
//{
//	int m = 1;
//	int k = 0;
//	for (k = 1; k <= n; k++)
//	{
//		 m*= 10;
//	}
//	int i = 0;
//	for (i = 1; i < m; i++)
//	{
//		Arr[i - 1] = i;
//	}
//	*returnSize = i;
//	return Arr;
//}
//输出是这一年的第几天
int main()
{
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);
	int sum = day;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		arr[1] = 29;
		int i = 0;
		
		for (i = 0; i < month-1; i++)
		{
			sum += arr[i];
		}
		printf("这是 %d 年的第 %d 天", year, sum);
	}
	else
	{
		int i = 0;
		for (i = 0; i < month -1 ; i++)
		{
			sum += arr[i];
		}
		printf("这是 %d 年的第 %d 天", year, sum);
	}
	return 0;
}
