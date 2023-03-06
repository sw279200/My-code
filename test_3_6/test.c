#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	long long n = 0;
//	while (scanf("%lld", &n) != EOF)
//	{
//		int count = 0;
//
//		while (n % 10 == 0)
//		{
//			n /= 10;
//		}
//		int num = n;
//		while (num)
//		{
//			num /= 10;
//			if (num != 0)
//				count++;
//
//		}
//		int m = 0;
//		while (count + 1)
//		{
//			m += (n % 10) * pow(10, count--);
//			n /= 10;
//		}
//		printf("%d\n", m);
//	}
//
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int cmp(void* p1, void* p2)
//{
//	return ((int*)p1) - ((int*)p2);
//}
//int main()
//{
//	int n = 0;
//	while (scanf("%d\n", &n) != EOF)
//	{
//		int arr[200020];
//		int i = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		int count = 0;
//		for (i = 1; i <= n - 1; i++)
//		{
//			if (arr[i] > arr[i + 1])
//				count++;
//
//		}
//		if ((count == 1 && arr[n] <= arr[1]) || count == 0)
//		{
//			for (i = 0; i < n; i++)
//			{
//				int j = 1;
//				for (j = 0; j < n - i - 1; j++)
//				{
//					if (arr[j + 1] > arr[j + 2])
//					{
//						int temp = arr[j + 1];
//						arr[j + 1] = arr[j + 2];
//						arr[j + 2] = temp;
//					}
//				}
//			}
//			for (i = 1; i <= n; i++)
//			{
//				printf("%d ", arr[i]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("-1\n");
//		}
//
//	}
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[101];
	int i = 0;
	int n = 0;
	do
	{
		n++;
		i++;
		scanf("%d", &arr[i]);
	} while (arr[i] != 0);
	for (i = n - 1; i >= 1; i--)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
