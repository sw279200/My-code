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
//		//��ӡ�ո�
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
//�������룬һ��������2~20������ʾ��ת�������ߵĳ��ȣ�����*����������Ҳ��ʾ���������
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
		//��ӡ���ε��ϰ벿��
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
		//��ӡ���ε��°벿��
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