#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
////打印菱形图案
//int main()
//{
//	int n = 0;
//	char ch;
//	scanf("%c", &ch);
//	scanf("%d", &n);
//	int line = n / 2 + 1;
//	//打印上半部分
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			//打印字符
//			if (j == 0 || j == 2 * i)
//				printf("%c", ch + i);
//			else
//				printf(" ");
//
//		}
//		printf("\n");
//	}
//	//打印下半部分
//	for (i = 0; i < line - 1; i++)
//	{
//		int j = 0;
//		//打印空格
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			//打印字符
//			if (j == 0 || j==2*(line-i-2))
//				printf("%c", ch + line - i - 2);
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	return 0;
//}
// 
// 
// 
// 
// 
//#include<stdio.h>
//int main()
//{
//
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 0;
//	for (i = 10; i < 100; i++)
//	{
//		if ((i / 10 + i % 10) == n)
//		{
//			sum += i;
//
//		}
//	}
//	printf("%d\n", sum);
//	return 0;
//}

#include<stdio.h>
#define num 1000000000
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Min(int a, int b)
{
	return a < b ? a : b;
}
void test()
{
	int min = num;
	int n = 0, a = 0, b = 0;
	scanf("%d %d %d", &n, &a, &b);
	while (n--)
	{ 

		int k = 0, x = 0, y = 0;
		scanf("%d %d %d", &k, &x, &y);
		while (k--)
		{
			int price = 0;
			scanf("%d", &price);
			if (price >= a && price >= x)
			{
				price = Max(0, price - b - y);
			}
			else if (price >= a)
			{
				price = Max(0, price - b);
			}
			else if (price >= x)
			{
				price = Max(0, price - y);
			}
			min = Min(min, price);
		}
	}
	printf("%d\n", min);
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		test();
	}
	return 0;
}

