#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//用递归和非递归实现求第n个斐波那契数
// 用递归方法
//int Fab(int m)
//{
//	if (m <= 2)
//		return 1;
//	else
//		return Fab(m - 1) + Fab(m - 2);
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fab(n);
//	printf("%d\n", ret);
//	return 0;
//}
//非递归方法
//int fab(int n)
//{
//	int count = 2;
//	int a = 1;
//	int b = 1;
//	int c = 2;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		while (count != n)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//			count++;
//		}
//		return c;
//	}
//}
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	int ret = fab(num);
//	printf("%d\n", ret);
//	return 0;
//}
//用递归实现求n的k次方
//int my_pow(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*my_pow(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int ret = my_pow(n, k);
//	printf("%d\n", ret);
//	return 0;
//}
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//输入：1729，输出：19
//int DigitSum(int n)
//{   
//	
//	if (n > 9)
//	{
//		int ret = DigitSum(n / 10);
//		return n % 10 + ret;
//	}
//	else
//		return n;
//	
//}
//#include<stdio.h>
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	int ret = DigitSum(num);
//	printf("%d\n", ret);
//	return 0;
//}
//void reverse_string(char* str)
//{
//	if (*str != '\0')//判断str在ASCII值是否为0
//	{
//		str++;//一直向后统计元素
//		reverse_string(str);
//		printf("%c", *(str - 1));//从最后一个字符串输出
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	return 0;
//}
#include<stdio.h>
#include<assert.h>
////非递归实现strlen
//int my_strlen(const char* str)
//{   
//	//断言，如果str指针是空指针就直接提示报错
//	assert(str);
//	int count = 0;
//	while ((*str++) != '\0')//当str指向\0的时候停止计数
//	{   
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = "abcdefgh";
//	int ret = my_strlen(str);
//	printf("%d", ret);
//	return 0;
//}
//递归实现strlen
//int my_strlen(char* str)
//{
//
//	if ((*str++)!='\0')
//	{
//		return my_strlen(str) + 1;
//	}
//	return 0;
//}
//int main()
//{
//	char str[] = "bitekeji";
//	int ret  = my_strlen(str);
//	printf("%d", ret);
//	return 0;
//}
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//非递归实现
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("请输入一个整数：>");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("该数的阶乘为：%d\n", ret);
//	return 0;
//}
////递归方法
//int factorial(int n)
//{
//	if (n >= 2) {
//		return n * factorial(n - 1);
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个整数：>");
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("该数的阶乘为：%d", ret);
//	return 0;
//}
//递归方式实现打印一个整数的每一位
#include<stdio.h>
void function(int n)
{
	if (n > 9)
	{
		function(n / 10);
		printf("%d ", n % 10);
	}
	else
		printf("%d ", n);
}
int main()
{
	int num = 0;
	printf("请输入一个数：>");
	scanf("%d",&num);
	printf("该数的各个为的数为：\n");
	function(num);
	
	return 0;
}