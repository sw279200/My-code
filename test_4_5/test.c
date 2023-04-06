#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////数字的处理和判断
//int main()
//{
//	int arr[6];
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	while (n&&count<=5)
//	{
//		arr[count++] = n % 10;
//		n /= 10;
//	}
//	printf("%d\n", count);
//	int m = count;
//	while (m--)
//	{
//		printf("%d ", arr[m]);
//	}
//	printf("\n");
//	int i = 0;
//	while (i<=count-1)
//	{
//		printf("%d", arr[i++]);
//	}
//
//	return 0;
//}

////求一个数的最大公因数和最小公倍数
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int i = m < n ? m : n;
//	while (i >= 1)
//	{
//		if (m % i == 0 && n % i == 0)
//		{
//			break;
//		}
//		i--;
//	}
//	printf("%d %d", i, (m * n / i));
//	return 0;
//}

//#include<stdio.h>
////阶乘求和
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 1;
//	long long sum = 0;
//	
//	for (i = 1; i <= n; i++)
//	{
//		long long num = 1;
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			num *= j;
//		}
//		sum += num;
//	}
//	printf("%lld", sum);
//}


////完数的判断
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 6;
//	for (; i <= n; i++)
//	{
//		int sum = 0;
//		int arr[100] = { 0 };
//		int count = 0;
//		for (int j = 1; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				arr[count++] = j;
//				sum += j;
//			}
//		}
//		if (sum == i)
//		{
//			printf("%d its factors are ",i);
//			int x = 0;
//			for (x = 0; x < count; x++)
//			{
//				printf("%d ", arr[x]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////迭代法求平方根
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double n, x=1.0, x1;
//	scanf("%lf", &n);
//	do
//	{
//		x1 = x;
//		x = (x1 + n /x1) / 2;
//	} while (fabs(x - x1) > 0.00001);
//	printf("%.3lf", x);
//	
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int cmp(void* p1, void* p2)
//{
//	return *((int*)p1) - *((int*)p2);
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, 10, sizeof(int), cmp);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}


////自定义函数处理最大公约数与最小公倍数
//#include<stdio.h>
////求最大公约数
//int MaxCommonlDivisor(int n, int m)
//{
//	int i = n < m ? n : m;
//	for (; i >= 1; i--)
//	{
//		if (n % i == 0 && m % i == 0)
//		{
//			return i;
//		}
//	}
//}
////求最小公倍数
//int MinCommonMultipu(int n, int m)
//{
//	int count = n > m ? n : m;
//	while (1)
//	{
//		if (count % n == 0 && count % m == 0)
//		{
//			return count;
//		}
//		count++;
//	}
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	printf("%d %d", MaxCommonlDivisor(n,m), MinCommonMultipu(n, m));
//	return 0;
//}



//三个字符串的排序

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct S
{
	char str[100];
}S;

int cmp(void* p1, void* p2)
{
	return strcmp(((S*)p1)->str, ((S*)p2)->str);
}
int main()
{
	S s[3] = { 0 };
	gets(s[0].str);
	gets(s[1].str);
	gets(s[2].str);
	qsort(s, 3, sizeof(S), cmp);
	printf("%s\n%s\n%s\n", s[0].str, s[1].str, s[2].str);
	return 0;
    
}

