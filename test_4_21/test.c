#define _CRT_SECURE_NO_WARNINGS 1


#if 0

#include <stdio.h>
//阿宁的柠檬
int main()
{
	long long a, b, n;
	scanf("%lld %lld %lld",&a,&b,&n);
	long long min = n * 1;
	long long max = a * n + b * n;
	printf("%lld %lld\n", min, max);
	return 0;
}
#endif


#if 0

#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int max1 = a > b ? a : b;
	int min1 = a < b ? a : b;
	int max2 = c > d ? c : d;
	int min2 = c < d ? c : d;
	if (c * d >= a * b)
	{
		if (max1 <= max2 && min2 >= min1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
#endif

#if 0
#include <string.h>
#include <stdio.h>
int main()
{
	char arr[10001] = { 0 };
	scanf("%s", arr);
	if (strstr(arr, "lve") != NULL || strstr(arr, "loe") != NULL || strstr(arr, "lov") != NULL || strstr(arr, "ove") != NULL)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
#endif


#if 1
#include <stdio.h>
#include <math.h>
//猫猫与数列
int main()
{
	double M =1E18;
	double p, q;
	scanf("%lf %lf", &p, &q);
	double num = 0.0;
	int n = 1;
	while (num <= M)
	{
		num =pow((double)p, (double)q);
		n++;
		p = q;
		q = num;
	}
	printf("%d\n", n);
	return 0;
}

#endif
