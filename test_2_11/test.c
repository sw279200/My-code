#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//打印九九乘法口诀表
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

//求十个整数中的最大值
//int Max(int arr[],int sz)
//{
//	int max_num = arr[0];//假设arr第一个元素为最大值
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		if (arr[j] > max_num)//如果有比当前最大的数要大的值
//		{ 
//			int temp = arr[j];
//			arr[j] = max_num;  //就把该值跟max_num的值交换
//			max_num = temp;   //最后等数组遍历完max_num留下的就是最大值
//		}
//	}
//	return max_num;//返回该数组的最大值
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

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
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
//猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("**1.开始游戏 0.退出游戏**\n");
//	printf("*************************\n");
//	printf("请选择：->");
//}
//void game()
//{   
//	int num = 0;
//	int ret = rand() % 100 + 1;//得到一个1-100的随机数 
//	while (1)
//	{
//		printf("请猜该数字：>");
//		scanf("%d",&num);
//		if (num > ret)
//		{
//			printf("猜大了!\n");
//		}
//		else if (num < ret)
//		{
//			printf("猜小了!\n");
//		}
//		else
//		{
//			printf("恭喜你！猜对了！\n");
//			break;
//		}
//	}
//
//}
//int main()
//{
//	//生成0~32676之间的一个随机数
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do 
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("退出游戏！\n");        //退出游戏
//			break;
//		case 1:
//			game();         //猜数字游戏
//			break;
//		default:
//			printf("选择错误！");         //选择错误
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
//	int left = 0;//数组元素下标
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
//			printf("找到了，下标是%d\n", mid);
//			break;
//		}
//	
//	}
//	if (left<right)
//	{
//		printf("没找到！");
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
//		printf("该年份是闰年\n");
//	}
//	else
//	{
//		printf("该年份不是闰年");
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
        int flag = 1;//假设i是素数
                      //判断i是否是素数
                      //用2到根号i的值去试除i
        int j = 0;
        for (j = 2; j < sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;//不是素数
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

