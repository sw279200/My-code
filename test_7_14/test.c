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

int main()
{
	//TestInsertSort();
	TestShellSort();
	return 0;
}

