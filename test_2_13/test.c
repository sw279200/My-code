#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	//����������ʱ������������������������
//	int a = 3;
//	int b = 5;
//	printf("����ǰ��a = %d b = %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������a = %d b = %d\n",a,b);
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
//	/*дһ���������ز����������� 1 �ĸ�����
//		���磺 15    0000 1111    4 �� 1*/
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
//	int k = 1;            //1�Ķ�����Ϊ0001 
//	printf("������һ��ʮ������:\n");
//	scanf("%d", &n);
//	count = 0;
//	while (k)            //ֱ��k��λ���Ƶ�0��ֹͣ ��0000 
//	{
//		if (n & k)            //��λ�����㣬��n�Ķ�����ÿһλ��k�е�1��ȣ������� 
//			count++;         //ͳ��1������ 
//		k <<= 1;	            //��k��λ���ƣ�����0001��1��λ�� 
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
//	printf("�������������֣�");
//	scanf("%d%d", &m, &n);
//	q = m ^ n;  // ��������λ��򣬶�Ӧ��ͬ��λ������1
//	while (q)
//	{
//		q = q & (q - 1);  //��λ�뷽������һ�������б���λΪ1�ĸ���
//		count++;
//	}
//	printf("count=%d", count);
//	system("pause");
//	return 0;
//}
#include <stdio.h>

void print(int m) {
	int i = 0;
	printf("����λ��\n");
	for (i = 30; i >= 0; i -= 2) {

		printf("%d", (m >> i) & 1);
	}
	printf("\n");
	printf("ż��λ��\n");
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
