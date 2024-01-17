#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Test()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 50,40,95,20,15,70,60,45,80 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
		int top = HeapTop(&hp);
		printf("%d ", top);
		HeapPop(&hp);
	}

}

////弊端，1.得先有一个堆  2.空间复杂度+拷贝
//void HeapSort(int *a,int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		a[i++] = top;
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}

void HeapSort(int* a, int n)
{
	//升序，建大堆
	//降序，建小堆

	////向上调整建堆
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//在调整，选出次小的数
		AdjustDown(a, end, 0);

		end--;
	}
}

void CreatData()
{
	//造数据
	int n = 1000;
	srand((unsigned int)time(NULL));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		printf("fopen fail");
		return;
	}

	for (size_t i = 0; i < n; i++)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}
PrintTop(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("fopen fail");
		return;
	}

	int* hipple = (int*)malloc(sizeof(int) * k);
	if (hipple == NULL)
	{
		printf("malloc fail");
		return;
	}

	for (size_t i = 0; i < k; i++)
	{
		fscanf(fout, "%d",&hipple[i]);
	}

	//建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hipple, k, i);
	}

	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (hipple[0] < val)
		{
			hipple[0] = val;
			AdjustDown(hipple, k, 0);
		}

	}

	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", hipple[i]);
	}
	printf("\n");
}

int main()
{
	//Test();
	/*int a[] = { 1,4,5,7,8,3,5,9,2 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}*/

	//CreatData();
	//PrintTop(5);

	HP hp;
	HeapInit(&hp);
	int a[] = { 50,40,95,20,15,70,60,45,80 };
	int size = sizeof(a) / sizeof(a[0]);
	
	HeapSort(a, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	//Test();

	return 0;
}
