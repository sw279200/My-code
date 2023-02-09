#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//int Max(int a, int b)
//{
//	if (a > b)
//	{
//		return a;
//	}
//	return b;
//}
//int main()
//{
//	int a;
//	int b;
//	scanf("%d %d", &a, &b);
//	int max = Max(a, b);
//	printf("%d\n", max);
// return 0;
//}
//int main()
//{
//	int a;
//	int b;
//	scanf("%d %d", &a, &b);
//	int mod = a % b;
//	int trade = a / b;
//	printf("%d %d", trade, mod);
//	return 0;
//}
//int main() {
//    float height[5];
//    float sum = 0.00;
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        scanf("%f", &height[i]);
//        sum += height[i];
//    }
//    float aver_height = sum / 5.00;
//    printf("%.2f", aver_height);
//    return 0;
//}
int main()
{
	int x, y;
	scanf("%d", &x);
	if (x < 0)
	{
		y = 1;
	}
	else if (x ==0)
	{
		y = 0;
	}
	else
	{
		y = -1;
	}
	printf("%d", y);
	return 0;
}