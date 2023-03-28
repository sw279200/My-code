#define _CRT_SECURE_NO_WARNINGS 1

//小白月赛62 数组划分 
#include<stdio.h>
#include<math.h>
int n = 0;
int flag[1000005] = { 0 };
int judge = 0;

void solve()
{
	scanf("%d", &n);
	int i = 0;
	int num = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		
		for (int j = 2; j <= sqrt(num); j++)
		{
			if (num % j == 0)
			{
				while (num % j == 0)
				{
					num /= j;
					flag[j] = 1;//记录小于sqrt(num)的质因数
				}
				
			}
		}
		if(num>1)
			flag[num] = 1;//记录大于sqrt(num)的质因数
	}
	int count = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &count);
		for (int j = 2; j <= sqrt(count); j++)
		{
			if (count % j == 0)
			{
				if (flag[j] == 1)judge = 1;
				while (count % j == 0)
				{
					count /= j;
					
				}
			}
		}
		if (count > 1 && flag[count]==1)judge = 1;
	}
	if (judge)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
}
int main()
{
	solve();
	return 0;
}