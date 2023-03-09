#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int m = 0;
//	long long arr1[10][10];
//	long long arr2[10][10];
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			scanf("%lld", &arr1[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			scanf("%lld", &arr2[i][j]);
//		}
//	}
//	int flag = 1;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			if (arr1[i][j] != arr2[i][j])
//			{
//				flag = 0;
//				break;
//			}
//			    
//		}
//	}
//	if (flag == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}
//#include<stdio.h>
//void delete_count(int arr[],int n, int m)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != m)
//			printf("%d ", arr[i]);
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[60];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int m = 0;
//	scanf("%d", &m);
//	delete_count(arr, n,m);
//
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int year = 0;
//	int month = 0;
//	
//	while (scanf("%d %d", &year, &month)!=EOF)
//	{
//		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			arr[1] = 29;
//		printf("%d\n", arr[month - 1]);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	double s_price;
	int month;
	int day;
	int is_have = 0;
	scanf("%lf %d %d %d", &s_price, &month, &day, &is_have);
	double l_price=0.0;
	if (month == 11 && day == 11)
	{
		if (is_have == 1 && s_price * 0.7 >= 50)
		{
			l_price = s_price * 0.7 - 50;
		}
		else if (is_have == 1 && s_price * 0.7 <= 50)
			l_price = 0.00;
		else
			l_price = s_price * 0.7;
	}
	else if (month == 12 && day == 12)
	{
		if (is_have == 1 && s_price * 0.8 >= 50)
		{
			l_price = s_price * 0.8 - 50;
		}else if (is_have == 1 && s_price * 0.8 <= 50)
			l_price = 0.00;
		else
			l_price = s_price * 0.8;
	}
	printf("%.2lf", l_price);
	return 0;
}