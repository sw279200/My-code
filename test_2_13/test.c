#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	//不允许创建临时变量，交换两个整数的内容
//	int a = 3;
//	int b = 5;
//	printf("交换前：a = %d b = %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后：a = %d b = %d\n",a,b);
//	return 0;
//}

//int GetCount(int m)
//{
//	if (m >= 0)
//	{
//		if (m >= 2)
//		{
//			return m - 2 * (m / 2) + GetCount(m / 2);
//		}
//		return m;
//	}
//	else
//	{
//
//	}
//	
//}
//int main()
//{
//	/*写一个函数返回参数二进制中 1 的个数。
//		比如： 15    0000 1111    4 个 1*/
//	
//	int n;
//	scanf("%d", &n);
//	int count = GetCount(n);
//	printf("%d", count);
//	return 0;
//}

#include<stdio.h>

//int main()
//{
//	int n, count;
//	int k = 1;            //1的二进制为0001 
//	printf("请输入一个十进制数:\n");
//	scanf("%d", &n);
//	count = 0;
//	while (k)            //直到k按位左移到0，停止 即0000 
//	{
//		if (n & k)            //按位与运算，当n的二进制每一位与k中的1相等，即成立 
//			count++;         //统计1的数量 
//		k <<= 1;	            //将k按位左移，控制0001中1的位置 
//	}
//	printf("%d", count);
//	return 0;
//}
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int q = 0;
//	int i = 0;
//	int count = 0;
//	printf("请输入两个数字：");
//	scanf("%d%d", &m, &n);
//	q = m ^ n;  // 两个数按位异或，对应不同的位将会置1
//	while (q)
//	{
//		q = q & (q - 1);  //按位与方法计算一个整数中比特位为1的个数
//		count++;
//	}
//	printf("count=%d", count);
//	system("pause");
//	return 0;
//}
#include <stdio.h>

void print(int m) {
	int i = 0;
	printf("奇数位：\n");
	for (i = 30; i >= 0; i -= 2) {

		printf("%d", (m >> i) & 1);
	}
	printf("\n");
	printf("偶数位：\n");
	for (i = 31; i >= 0; i -= 2) {
		printf("%d", (m >> i) & 1);
	}
	printf("\n");
}
int main() {
	int a = 0;
	scanf("%d", &a);
	print(a);
	return 0;

}
