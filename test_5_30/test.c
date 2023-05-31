#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[i + gap];
			while (end > 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end+gap] = temp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void SelectSort(int* a, int n)
{
	int start = 0;
	int end = n - 1;
	while (start <  end)
	{
		int mini = start;
		int maxi = start;
		for (int i = start; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[mini], &a[start]);
		if (maxi == start)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);

		start++;
		end--;
	}

}
int main()
{
	int arr[] = { 2,34,54,2,34,4,5,10,23,45 };
	int size = sizeof(arr) / sizeof(int);
	/*ShellSort(arr, size);
	PrintArr(arr, size);*/
	SelectSort(arr, size);
	PrintArr(arr, size);
	return 0;
}