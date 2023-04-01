#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
////小白月赛69 A蛋挞
//int main()
//{
//	long long a, b, c ;
//	scanf("%lld %lld", &a, &b);
//	c = a % b;
//	if (c > a / b)
//	{
//		printf("niuniu eats more than others\n");
//	}
//	else if(c<a/b)
//	{
//		printf("niuniu eats less than others\n");
//	}
//	else
//	{
//		printf("same\n");
//	}
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
//小白月赛69 B玩具
int cmp(const void* p1,const void* p2)
{
	return (*((long long*)p1) - (*(long long*)p2));
}
long long arr[1000010];
int main()
{
	long long n = 0;
	long long ans = 0;
	scanf("%lld", &n);
	long long i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	qsort(arr, n, sizeof(long long), cmp);
	for (i = n-1; i >= 0; i--)
	{
		ans += arr[i];
		i--;
	}
	printf("%lld\n", ans);
	return 0;
}
