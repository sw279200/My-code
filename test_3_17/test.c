#define _CRT_SECURE_NO_WARNINGS 1

////牛客小白月赛66重现赛
//#include<stdio.h>
//int main()
//{
//	int T = 0;
//	int n = 0;
//	
//	int arr[1100] = { 0 };
//	scanf("%d", &T);
//	while (T--)
//	{
//		int i = 0;
//		int flag = -1;
//		int count = 0;
//		scanf("%d", &n);
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i + 1]);
//			if (arr[1] % 2 == 1)
//			{
//				flag = 0;
//			}
//			else if(arr[i + 1] % 2 == 1&&arr[i+1]<arr[1]&&i>0)
//			{
//				flag = 1;
//			}
//
//		}
//		printf("%d\n", flag);
//	}
//	return 0;
//}



#include<stdio.h>
long long arr1[100010] = { 0 };
long long arr2[100010] = { 0 };
//把一个n位数的各个位数上的数存在数组中
void eval(long long arr[], int n,long long num)
{
	while (n--)
	{
		*(arr + n) = num % 10;
		num /= 10;
	}
	*(arr + n) = num;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	
	while (T--)
	{
		int n = 0;
		scanf("%d", &n);
		long long A = 0;
		long long B = 0;
		scanf("%lld", &A);
		scanf("%lld", &B);
		int ret;
		eval(arr1, n, A);
		eval(arr2, n, B);
		if (A >B)
		{
			int m = 0;
			for (m = 0; m < n; m++)
			{
				if (arr1[m] > arr2[m])
				{
					printf("%d %d\n", m, m);
					break;
				}
			}
			
		}
		else if (A < B)
		{
			int i = 0;
			for (i = 0; i < n; i++)
			{
				int j = 0;
				for (j = 0; j < n; j++)
				{
					if (*(arr1 + j) > *(arr2 + i))
					{

					}
				}
		}
	}
	return 0;
}

