#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		//kͼ�����ϰ벿��
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
//		//kͼ�����°벿��
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
//        //��ӡ��ͷ���ϰ벿��
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
//        //��ӡ��ͷ���°벿��
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
   //���ÿ�����룬����á�*����ɵ�X��ͼ��

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
//�������룬һ��������3~20������ʾ�����������Ҳ��ʾ��������αߵġ�*����������
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



