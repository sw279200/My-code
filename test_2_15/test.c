#define _CRT_SECURE_NO_WARNINGS 1
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������
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

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

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
//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//����
//int main()
//{
//	int n = 0;
//	int arr[20][20]={0};
//	//����һ��1-20����
//	printf("������һ��1��20��������>");
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
// �������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
//1. �÷���һ�������б��������ӡ
//2. n Ϊ��������0 < n <= 5
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
//�������һ��ĵڼ���
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
		printf("���� %d ��ĵ� %d ��", year, sum);
	}
	else
	{
		int i = 0;
		for (i = 0; i < month -1 ; i++)
		{
			sum += arr[i];
		}
		printf("���� %d ��ĵ� %d ��", year, sum);
	}
	return 0;
}
