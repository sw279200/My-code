#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//�õݹ�ͷǵݹ�ʵ�����n��쳲�������
// �õݹ鷽��
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
//�ǵݹ鷽��
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
//�õݹ�ʵ����n��k�η�
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
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//���룺1729�������19
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
//	if (*str != '\0')//�ж�str��ASCIIֵ�Ƿ�Ϊ0
//	{
//		str++;//һֱ���ͳ��Ԫ��
//		reverse_string(str);
//		printf("%c", *(str - 1));//�����һ���ַ������
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
////�ǵݹ�ʵ��strlen
//int my_strlen(const char* str)
//{   
//	//���ԣ����strָ���ǿ�ָ���ֱ����ʾ����
//	assert(str);
//	int count = 0;
//	while ((*str++) != '\0')//��strָ��\0��ʱ��ֹͣ����
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
//�ݹ�ʵ��strlen
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
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//�ǵݹ�ʵ��
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("������һ��������>");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("�����Ľ׳�Ϊ��%d\n", ret);
//	return 0;
//}
////�ݹ鷽��
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
//	printf("������һ��������>");
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("�����Ľ׳�Ϊ��%d", ret);
//	return 0;
//}
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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
	printf("������һ������>");
	scanf("%d",&num);
	printf("�����ĸ���Ϊ����Ϊ��\n");
	function(num);
	
	return 0;
}