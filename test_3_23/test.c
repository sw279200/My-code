#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//С������63ħ��ʦ��ӵ
int main()
{
	int n = 0;
	int m = 0;
	int arr[101] = { 0 };
	scanf("%d %d", &n, &m);
	int i = 0;
	int sum = 0;//�ܹ���
	int hurt = 2;//�˺�
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int j = 0;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i] == hurt)
			{
				hurt++;
				arr[i] -= hurt;
			}
			else
			{
				arr[i] -= hurt;
			}
			
		}
		sum += hurt;
		
	}
	
	printf("%d\n", sum);
}

