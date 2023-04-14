#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n = 0;
//	while (~scanf("%d", &n))
//	{
//		int i = 1;
//		int sum = 0;
//		for (; i <= n; i++)
//		{
//			int nums;
//			scanf("%d", &nums);
//			sum += (int)fabs(nums);
//		}
//		printf("%d\n",sum);
//	}
//	return 0;
//}

#include <stdio.h>

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int start = left;
	int end = right;
	int key = arr[start];
	int pivot = start;
	while (start < end)
	{
		while (start < end&&key > arr[end])
		{
			end--;
		}

		arr[pivot] = arr[end];
		pivot = end;
		while (start < end && key<arr[start])
		{
			start++;
		}
		arr[pivot] = arr[start];
		pivot = start;
	}
	pivot = start;
	arr[pivot] = key;
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}
void PrintArr(int* arr, int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int n = 0;
	int arr[101] = { 0 };
	while (~scanf("%d", &n))
	{
		int i = 0;
		for (; i < n; i++)
		{
			scanf("%d", &arr[i]);

		}
		//¿ìËÙÅÅÐò
		QuickSort(arr, 0, n-1);
		PrintArr(arr, n);
	}
	return 0;
}
