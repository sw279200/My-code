#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ӡ�žų˷��ھ���
//int main()
//{
//	int i;
//	int j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{   
//	         printf("%d*%d=%d ", i, j, i * j);
//		}
//		     printf("\n");
//	}
//	return 0;
//}

//��ʮ�������е����ֵ
//int Max(int arr[],int sz)
//{
//	int max_num = arr[0];//����arr��һ��Ԫ��Ϊ���ֵ
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		if (arr[j] > max_num)//����бȵ�ǰ������Ҫ���ֵ
//		{ 
//			int temp = arr[j];
//			arr[j] = max_num;  //�ͰѸ�ֵ��max_num��ֵ����
//			max_num = temp;   //�������������max_num���µľ������ֵ
//		}
//	}
//	return max_num;//���ظ���������ֵ
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	while (i < 10)
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//	printf("%d\n", Max(arr, 10));
//	return 0;
//}

//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
//#include<math.h>
//int main()
//{ 
//	int i = 1;
//	double sum = 0.00;
//	double ret = 0.00;
//	for (i = 1; i <= 100; i++)
//	{
//		ret = pow(-1.0,i+1) * (1.00 / i);
//		sum += ret;
//	}
//	printf("%.6lf", sum);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//		 if (i % 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//	return 0;
//}
//��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("**1.��ʼ��Ϸ 0.�˳���Ϸ**\n");
//	printf("*************************\n");
//	printf("��ѡ��->");
//}
//void game()
//{   
//	int num = 0;
//	int ret = rand() % 100 + 1;//�õ�һ��1-100������� 
//	while (1)
//	{
//		printf("��¸����֣�>");
//		scanf("%d",&num);
//		if (num > ret)
//		{
//			printf("�´���!\n");
//		}
//		else if (num < ret)
//		{
//			printf("��С��!\n");
//		}
//		else
//		{
//			printf("��ϲ�㣡�¶��ˣ�\n");
//			break;
//		}
//	}
//
//}
//int main()
//{
//	//����0~32676֮���һ�������
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do 
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("�˳���Ϸ��\n");        //�˳���Ϸ
//			break;
//		case 1:
//			game();         //��������Ϸ
//			break;
//		default:
//			printf("ѡ�����");         //ѡ�����
//			break;
//		}
//
//	} while (input);
//	return 0;
//}
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;//����Ԫ���±�
//	int right = sz - 1;
//	
//	while (left <=right)
//	{
//		int mid =(left+right)/2;
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±���%d\n", mid);
//			break;
//		}
//	
//	}
//	if (left<right)
//	{
//		printf("û�ҵ���");
//	}
//	return 0;
//
//}
//
//int main()
//{
//
//	return 0;
//}
//void Change(int* x, int* y)
//{
//	int m = *x;
//	*x = *y;
//	*y = m;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* pa = &a;
//	int* pb = &b;
//	Change(pa, pb);
//	printf("a = %d\nb = %d\n", a, b);
//	return 0;
//}

//int Is_leap_year(int year)
//{
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (Is_leap_year(year))
//	{
//		printf("�����������\n");
//	}
//	else
//	{
//		printf("����ݲ�������");
//	}
//
//}
#include<stdio.h>
#include<stdio.h>
#include<math.h>
int main()
{
    
    int i = 0;
    int count = 0;
    for (i = 100; i <= 200; i++)
    {
        int flag = 1;//����i������
                      //�ж�i�Ƿ�������
                      //��2������i��ֵȥ�Գ�i
        int j = 0;
        for (j = 2; j < sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;//��������
                break;
            }

        }
        if (flag == 1)
        {
            printf("%d ", i);
            count++;
        }
        
    }
    printf("\ncount = %d\n", count);
    return 0;
}

