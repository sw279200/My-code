#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
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

//希尔排序
void ShellSort(int* a, int n)
{
	int group = n;
	while (group > 1)
	{
		group = group / 3 + 1;
		//对组并排
		for (int i = 0; i < n - group; i++)
		{
			int end = i;
			int temp = a[i + group];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + group] = a[end];
					end -= group;
				}
				else
				{
					break;
				}
			}

			a[end + group] = temp;
		}
	}


}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				flag = true;
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}

		if (flag == false)
			break;
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int maxi = end;
		int mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}


//向下调整算法
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

//快排
//方法一：霍尔排序法
int  PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}

		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		

		Swap(&a[left], &a[right]);
	}

	Swap(&a[key], &a[left]);

	return left;

}

//快排
//方法二：挖坑法
int  PartSort2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= a[hole])
		{
			right--;
		}

		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= a[hole])
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;

	}
	a[hole] = key;

	return hole;

}

//前后指针法
int  PartSort3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;

	while (cur <= right)
	{

		if (a[cur] <a[keyi]&& ++prev!=cur)
		{
			
			Swap(&a[cur], &a[prev]);
		}
		
		++cur;
		
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	//hoare法
	//int keyi = PartSort1(a, left, right);

	//挖坑法
	//int keyi = PartSort2(a, left, right);

	//前后指针法
	int keyi = PartSort3(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi+ 1, right);
}


int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[left]<a[right])
		{
			return right;
		}
		else
		{
			return left;
		}

	}
	else
	{
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}

//非递归快排

void QuickSortNonR(int *a, int start,int end)
{
	stack st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, start);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);

		if (right > keyi + 1)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}

	}
	StackDestroy(&st);
}