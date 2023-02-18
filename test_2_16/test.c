#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	//求最大公因数
//	int num1, num2;
//	scanf("%d %d", &num1, &num2);
//	int ret1 = num1;
//	int ret2 = num2;
//	while (num1%num2!=0)
//	{
//		int temp = num1 % num2;
//		num1 = num2;
//		num2 = temp;
//	}
//	printf("%d", (ret1 * ret2) / num2);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[5051] = {0};
//	int i = 0;
//	int m = 0;
//	scanf("%d", &m);
//	for (i = 0; i < 5051; i++)
//	{
//		arr[i] = 2 * (i+1) - 1;
//	}
//	int sum = 0;
//	int j = 0;
//	for (j = 1; j <= m; j++)
//	{
//		sum += j;
//	}
//	for (i = sum - m; i < sum - 1; i++)
//	{
//			printf("%d+", arr[i]);
//	}
//	printf("%d", arr[sum - 1]);
//	return 0;
//}
//求等差数列的前n项和
//#include<stdio.h>
//int main() {
//    int n = 0;
//    while ((scanf("%d", &n)) != EOF) {
//        if (n <= 0)
//            return -1;
//        else
//            printf("%d", 2 * n + (n * (n - 1) * 3) / 2);
//    }
//
//    return 0;
//}
#include<stdio.h>

int main()
{
	int n = 0;
	int arr[2000] = { 0 };
	scanf("%d", &n);
	int i = 0;
	int count = 0;
	int ret = 0;
	int sum =0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			count++;
		}
		else if(arr[i]>0)
		{
			sum += arr[i];
			ret++;
		}
	}
	if (sum == 0)
		printf("%d %.1f",count,1.0*sum);
	else
	printf("%d %.1f", count, sum*(1.0) / ret);
	return 0;
}