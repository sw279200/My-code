#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。
//数据范围：
//1≤n≤100  ， 成绩使用百分制且不可能出现负数
//double sum(double arr[], int len)
//{
//	int i = 0;
//	double sum = 0.0;
//	for (i = 0; i < len; i++)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}
//double arr_max(double arr[], int n)
//{
//	double max = arr[0];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//double arr_min(double arr[], int n)
//{
//	double min = arr[0];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	return min;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	double arr[110];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lf", &arr[i]);
//	}
//	printf("%.2lf %.2lf %.2lf\n", arr_max(arr, n), arr_min(arr, n), sum(arr, n) / n);
//	return 0;
//}

//#include<string.h>
////用户登录网站，通常需要注册，一般需要输入两遍密码。
////请编程判断输入的两次密码是否一致，
////一致输出“same”，不一致输出“different”
//int main()
//{
//	char arr1[120];
//	char arr2[120];
//	scanf("%s %s", arr1, arr2);
//	if (strcmp(arr1, arr2) == 0)
//	{
//		printf("same\n");
//	}
//	else
//	{
//		printf("different\n");
//	}
//	return 0;
//}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int arr[20][20];
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			if (arr[i][j] > 0)
//				sum += arr[i][j];
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int arr[15];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int arr[100];
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//	printf("%d\n", sum);
//	return 0;
//}

////判断是否升序
//int s_sort(int arr[], int n)
//{
//	int i = 0;
//	int flag = 1;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				flag = 0;
//		}
//	}
//	return flag;
//}
//
////判断是否降序
//int j_sort(int arr[], int n)
//{
//	int i = 0;
//	int flag = 1;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] < arr[j + 1])
//				flag = 0;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	int n = 0;
//	int arr[100];
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//	if (s_sort(arr,n) || j_sort(arr,n))
//		printf("sorted\n");
//	else
//		printf("unsorted\n");
//	return 0;
//}

int main()
{
	int n = 0;
	int arr1[1010]={0};
	int arr2[1010] = { 0 };
	int len = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	arr2[0] = arr1[0];
	for (i = 0; i<n; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j <= len; j++)
		{
			if (arr1[i] == arr2[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			arr2[len + 1] = arr1[i];
			len++;
		}

	}
	for (i = 0; i <= len; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}
