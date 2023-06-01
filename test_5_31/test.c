#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; // 默认是左孩子
	while (child < n)
	{
		// 1、选出左右孩子中大的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child += 1;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 升序，建小堆？还是大堆？  -> 大堆
// 整体时间复杂度O(N*logN)
void HeapSort(int* a, int n)
{
	// 建堆  时间复杂度：O(N) 
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	// 排升序，建大堆还是小堆？建大堆
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeapSort();
	return 0;
}