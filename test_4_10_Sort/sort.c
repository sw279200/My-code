#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
// ����ʵ�ֵĽӿ�

//��ӡ
void ArrayPrint(int * a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* a, int n)
{
	//ǰ��[0,end]���Ѿ����򣬽�end+1λ�õ�������ʹ��[0,end+1]��������
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;

	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}

// ѡ������
void SelectSort(int* a, int n)
{

}

//// ������
//void AdjustDwon(int* a, int n, int root);
//void HeapSort(int* a, int n);
//
//
//// ð������
//void BubbleSort(int* a, int n);
//
//// ��������ݹ�ʵ��
//// ��������hoare�汾
//int PartSort1(int* a, int left, int right);
//
//
//// ���������ڿӷ�
//int PartSort2(int* a, int left, int right);
//
//
//// ��������ǰ��ָ�뷨
//int PartSort3(int* a, int left, int right);
//
//
//void QuickSort(int* a, int left, int right);
//// �������� �ǵݹ�ʵ��
//void QuickSortNonR(int* a, int left, int right);
//// �鲢����ݹ�ʵ��
//void MergeSort(int* a, int n);
//// �鲢����ǵݹ�ʵ��
//void MergeSortNonR(int* a, int n);
//// ��������
//void CountSort(int* a, int n);
//// ������������ܶԱ�
//void TestOP()
//{
//	srand(time(0));
//	const int N = 100000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//
//	}
//	int begin1 = clock();
//	InsertSort(a1, N);
//	int end1 = clock();
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//}
//ֱ�Ӳ����������
void TestInsertSort()
{
	int a[] = { 2,4,1,6,8,3,9,0,-1,9 };
	InsertSort(&a, sizeof(a) / sizeof(int));
	printf("InsertSort: ");
	ArrayPrint(&a, sizeof(a) / sizeof(int));
}


//ϣ���������
void TestShellSort()
{
	int a[] = { 2,4,1,6,8,3,9,0,-1,9 };
	ShellSort(&a, sizeof(a) / sizeof(int));
	printf("ShellSort: ");
	ArrayPrint(&a, sizeof(a) / sizeof(int));
}
int main()
{
	TestInsertSort();
	TestShellSort();
	//TestOP()
	return 0;
}