#define _CRT_SECURE_NO_WARNINGS 1


////The 3n+1 problem
//#include <stdio.h>
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int CycleLength(int x)
//{
//	int count = 1;
//	while (x != 1)
//	{
//		if (x % 2 == 1)
//		{
//			x = x * 3 + 1;
//			count++;
//		}
//		else
//		{
//			x /= 2;
//			count++;
//		}
//
//	}
//
//	return count;
//}
//
//
//int main()
//{
//	int m = 0, n = 0;
//	while (~scanf("%d %d", &m, &n))
//	{
//		printf("%d %d", m, n);
//		if (m > n)
//		{
//			int temp = m;
//			m = n;
//			n = temp;
//		}
//		int i = m;
//		int MaxCycleLength = 0;
//		for (; i <= n; i++)
//		{
//			MaxCycleLength=Max(MaxCycleLength, CycleLength(i));
//		}
//		printf(" %d\n", MaxCycleLength);
//	}
//	return 0;
//}


//ÉßÐÎ¾ØÕó

#include <stdio.h>

int main()
{
	int n = 0;
	while (~scanf("%d", &n))
	{
		int end = n * (n + 1) / 2;
		int count1 = 1;
		for (int i = 1; i <= n; i++)
		{
			count1 += i-1;
			int count2 = count1;
			for (int j = 1; j <= n-i+1; j++)
			{
				
				printf("%d ",count2);
				count2 += i + j;
			}
			printf("\n");

		}
	}
	return 0;
}