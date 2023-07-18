#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"


void TestInsertSort()
{
	int a[] = { 4,7,9,2,1,6,32,5,8,10,15 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 4,7,9,2,1,6,32,5,8,10,15 };
	PrintArray(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 4,7,9,2,1,6,32,5,8,10,15 };
	PrintArray(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	printf("BubbleSort:");
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 35,4,7,9,2,1,6,32,5,8,10,15 };
	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	printf("SelectSort:");
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 35,4,7,9,2,1,6,32,5,8,10,15 };
	PrintArray(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	printf("HeapSort:");
	PrintArray(a, sizeof(a) / sizeof(int));
}


//void TestOP()
//{
//	srand(time(0));
//	const int N = 1000000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	int* a7 = (int*)malloc(sizeof(int) * N);
//	int* a8 = (int*)malloc(sizeof(int) * N);
//
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//		a7[i] = a1[i];
//		a8[i] = a1[i];
//
//	}
//
//	int begin1 = clock();
//	//InsertSort(a1, N);
//	int end1 = clock();
//
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//
//	int begin3 = clock();
//	//BubbleSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	//SelectSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	HeapSort(a5, N);
//	int end5 = clock();
//
//	int begin6 = clock();
//	QuickSort(a6, 0, N - 1);
//	int end6 = clock();
//
//	int begin7 = clock();
//	MergeSort(a7, N);
//	int end7 = clock();
//
//	int begin8 = clock();
//	CountSort(a8, N);
//	int end8 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("BubbleSort:%d\n", end3 - begin3);
//	printf("SelcetSort:%d\n", end4 - begin4);
//	printf("HeapSort:%d\n", end5 - begin5);
//	printf("QuickSort:%d\n", end6 - begin6);
//	printf("MergeSort:%d\n", end7 - begin7);
//	printf("CountSort:%d\n", end8 - begin8);
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//	free(a7);
//	free(a8);
//
//}


int main()
{
	TestInsertSort();
	TestShellSort();
	TestHeapSort();
	return 0;
}

