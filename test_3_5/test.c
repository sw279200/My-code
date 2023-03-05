#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int count = 1;
//	for (i = 0; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= n - i - 1; j++)
//		{
//			printf("%02d",count);
//			count++;
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[1000];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sum = 0;
//	int max = arr[0];
//	int min =arr[0];
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//		sum += arr[i];
//	}
//	printf("%.2lf", 1.00 * (sum - max - min) / (n - 2));
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	int k = 0;
	scanf("%d", &k);
	int n = 1;
	long long sum = 0;

	int a[10005];
	int i = 1;
	while (i <= 10002)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i++] = n;
		}
		n++;
	}


	for (int i = 1; i <= k; i++)sum += a[i];
	printf("%lld", sum);
	return 0;	
}