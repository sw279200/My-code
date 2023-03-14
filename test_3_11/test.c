#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Count(long long n)
{
	int count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return count;
}
void get_num(long long x,long long y, int  a1[], int a2[],int n)
{
	int count = 0;
	while (n - count)
	{
		*(a1+count) = x % 10;
		x /= 10;
		*(a2 + count) = y % 10;
		y /= 10;
		count++;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	long long arr[120][2]={0};
	int a1[20] = { 0 };
	int a2[20] = { 0 };

	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &arr[i][0], &arr[i][1]);
	}
	for (i = 0; i < n; i++)
	{
		if (Count(arr[i][0]) == Count(arr[i][1]))
		{
			get_num(arr[i][0],arr[i][1],a1,a2, Count(arr[i][0]));
			int j = 0;
			for (j = Count(arr[i][0])-1; j >= 0; j--)
			{
				printf("%d", a1[j] * a2[j]);
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}
