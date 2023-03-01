#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		//k图案的上半部分
//		int i = 0;
//		for (i = 0; i <n ; i++)
//		{
//			int j = 0;
//			for (j = 0; j <= n - i; j++)
//			{
//				printf("* ");
//			}
//			
//			printf("\n");
//		}
//		//k图案的下半部分
//		for (i = 0; i <=n; i++)
//		{
//			int j = 0;
//			for (j = 0; j <= i; j++)
//			{
//				printf("* ");
//			}
//
//			printf("\n");
//		}
//		
//	}
//	return 0;
//}
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        //打印箭头的上半部分
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            int j = 0;
//            for (j = 0; j < n-i; j++)
//            {
//                printf("  ");
//            }
//            for (j = 0; j <= i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//        //打印箭头的下半部分
//        
//        for (i = 0; i <= n; i++)
//        {
//            int j = 0;
//            for (j = 0; j <i; j++)
//            {
//                printf("  ");
//            }
//            for (j = 0; j <=n- i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//
//    }
//
//    return 0;
//}
//int main()
//{
//	char n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if(i==j)
//				printf("*");
//				printf(" ");
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
//			for (j = 0; j < n; j++)
//			{
//				if (i + j == n-1)
//				{
//					printf("*");
//				}
//				printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
   //针对每行输入，输出用“*”组成的X形图案

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (j == i)
//					printf("*");
//				else if (j + i == n - 1)
//					printf("*");
//				else
//				printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“*”的数量。
//int main()
//{
//
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (i == 0 || i == n - 1)
//					printf("* ");
//				else if (j == 0 || j == n - 1)
//					printf("* ");
//				else
//					printf("  ");
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
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				if (i == n-1 || i == j || j == 0)
				{
					printf("* ");
				}
				else
					printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}



