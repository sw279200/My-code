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

//ʱ�临�Ӷȣ������O(N^2) ����
//ʱ�临�Ӷȣ���ã���O(N) ����
//��������
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		//[0,end]֮�����򣬲���tmp����Ȼ����
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

//ϣ������
void ShellSort(int* a, int n)
{
	int group = n;
	while (group > 1)
	{
		group = group / 3 + 1;
		//���鲢��
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
		for (int j = 1; j < n-i; j++)
		{
			if (a[j-1] > a[j])
			{
				flag = true;
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}

		if (flag == false)
			break;
	}
}

//ѡ������
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