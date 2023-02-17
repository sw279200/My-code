#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//求最大公因数
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int ret1 = num1;
	int ret2 = num2;
	while (num1%num2!=0)
	{
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	printf("%d", (ret1 * ret2) / num2);
	return 0;
}
