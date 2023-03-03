#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//一行，输出平均身高，保留两位小数。
//int main()
//{
//	double a, b, c, d, e;
//	scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
//	printf("%.2lf", (a * 100 + b * 100 + c * 100 + d * 100 + e * 100) / 500.00);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		switch (n)
//		{
//		case 200:
//			printf("OK\n");
//			break;
//		case 202:
//			printf("Accepted\n");
//			break;
//		case 400:
//			printf("Bad Request\n");
//			break;
//		case 403:
//			printf("Forbidden\n");
//			break;
//		case 404:
//			printf("Not Found\n");
//			break;
//		case 500:
//			printf("Internal Server Error\n");
//			break;
//		case 502:
//			printf("Bad Gateway\n");
//			break;
//		default:
//			break;
//
//		}
//	}
//	return 0;
//}

//int main() {
//
//    int arr[7];
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    while (scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]) != EOF)
//    {
//        int i = 0;
//        int sum = 0;
//        for (i = 0; i < sz; i++) {
//            sum += arr[i];
//        }
//        int min;
//        int max;
//        min = arr[0];
//        for (i = 0; i < sz; i++) {
//
//            if (arr[i] < min) {
//                int temp = arr[i];
//                arr[i] = min;
//                min = temp;
//            }
//        }
//        max = arr[0];
//        for (i = 0; i < sz; i++) {
//
//            if (arr[i] > max) {
//                int temp = arr[i];
//                arr[i] = max;
//                max = temp;
//            }
//        }
//
//        printf("%.2lf\n", (sum - min - max) / 5.00);
//    }
//    return 0;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[51];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	scanf("%d", &m);
		arr[n] = m;
		for (i = 0; i <= n; i++)
		{
			int j = 0;
			for (j = 0; j < n - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
	}
		for (i = 0; i <= n; i++)
		{

			printf("%d ", arr[i]);
	}
	
	return 0;
}