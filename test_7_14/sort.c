#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

//时间复杂度（最坏）：O(N^2) 逆序
//时间复杂度（最好）：O(N) 有序
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		//[0,end]之间有序，插入tmp后依然有序
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;

	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//对组并排
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}

	
}