#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<math.h>
//int Is_prime(int m)
//{
//	int flag = 1;
//	int i = 2;
//	for (i = 2; i <= sqrt(m); i++)
//	{
//		if (m % i == 0)
//		{
//			flag = 0;
//		}
//	}
//	if (flag == 1)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int n = 0;
//	int arr[100];
//	scanf("%d", &n);
//	int count = 0;
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (Is_prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", n - count - 1);
//	return 0;
//}
//int main()
//{
//	int arr1[100][100];
//	int arr2[100][100];
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr2[i][j]);
//		}
//	}
//	int count = 0;
//	if (m == n)
//	{
//		for (i = 0; i < m; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (arr1[i][j] == arr2[i][j])
//				{
//					count++;
//				}
//			}
//		}
//	}
//	else
//	{
//		for (i = 0; i < m; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (arr1[i][j] == arr2[j][i])
//				{
//					count++;
//				}
//			}
//		}
//	}
//	printf("%.2lf", ((1.00 * count) / (m * n))*100.00);
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char arr1[20];
//	char arr2[20];
//	scanf("%s %s", arr1, arr2);
//	if (strcmp(arr1, "admin") == 0 && strcmp(arr2, "admin") == 0)
//	{
//		printf("Login Success!");
//	}
//	else
//		printf("Login Fail!");
//
//	return 0;
//}
//int main()
//{
//	int i = 10;
//	int count = 1;
//	while (i <= 2019)
//	{
//		int j = i;
//		while (j)
//		{
//			if (j % 10 == 9)
//			{
//				count++;
//				break;
//			}
//			j /= 10;
//		}
//		i++;
//	}
//	printf("%d", count);
//	return 0;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 1;
	int count = 0;
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			count++;
		}
	}
	printf("%d %d", n - count, count);
	return 0;
}