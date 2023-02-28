#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char ch;
//	scanf("%c", &ch);
//	int count = 5;
//	int i = 0;
//	for (i = 0; i < count; i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0; j < count - i-1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < i + 1; j++)
//		{
//			printf("%c ", ch);
//		}
//
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n))!=EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n - i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n - i - 1; j++)
//			{
//				printf("  ");
//			}
//			for (j = 0; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//		
//	}
//	return 0;
//}
//多组输入，一个整数（2~20），表示翻转金字塔边的长度，即“*”的数量，也表示输出行数。
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < i; j++)
//			{
//				printf(" ");
//			}
//			for (j = 0; j < n - i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		//打印菱形的上半部分
		int i = 0;
		for (i = 0; i <= n; i++)
		{
			int j = 0;
			for (j = 0; j < n - i; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= i; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
		//打印菱形的下半部分
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j <= i; j++)
			{
				printf(" ");
			}
			for (j = 0; j < n - i; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
		
	}
	return 0;
}