#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

void InsertSort(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		int end = i - 1;
		int temp = a[i];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end+1] = a[end];
				end--;
			}
			else
			{
				break;
			}

		}
		a[end+1] = temp;
	}
}

int main()
{
	int arr[] = { 1,52,2,4,67,12,23,34 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}