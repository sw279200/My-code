#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char str[10];
//	scanf("%s", str);
//	int len = strlen(str);
//	int i = 0;
//	for (i = 0; i < len/2; i++)
//	{
//		char temp = str[i];
//		str[i] = str[len - i - 1];
//		str[len - i - 1] = temp;
//	}
//	printf("%s", str);
//	return 0;
//}
//int main()
//{
//	int s = 0;
//	int v = 0;
//	int h = 0;
//	int m = 0;
//	int t = 0;
//	scanf("%d%d", &s, &v);
//	t = s / v+11;
//	while (t >= 60)
//	{
//		h++;
//		t -= 60;
//	}
//	m = t;
//	printf("%02d:%02d", (7 - h), (60 - m));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int h = 0;
//	int r = 0;
//	scanf("%d%d", &h, &r);
//	double tong;
//	tong =20000/(h * 3.14 * r * r);
//	int count = (int)tong + 1;
//	printf("%d", count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	long long a1;
//	long long a2;
//	scanf("%lld%lld", &a1, &a2);
//	long long price=0;
//	if (a1 >= 0 && a2 > 0)
//	{
//		while (a2 >9)
//		{
//			a2 /= 10;
//		}
//		if (a2 > 5)
//		{
//			price = a1 + 1;
//		}
//		else if (a2 < 5)
//		{
//			price = a1;
//		}
//		else
//		{
//			if (a1 % 2 == 0)
//			{
//				price = a1;
//			}
//			else
//			{
//				price = a1 + 1;
//				
//			}
//		}
//		if (price == a1 + 1 && a2 > 5)
//		{
//			printf("duo le");
//		}
//		else if (price == a1 && a2 < 5)
//		{
//			printf("shao le");
//
//		}
//		else if (a2 == 5 && price % 2 == 0)
//		{
//			printf("gang gang hao");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	while (scanf("%d%d%d", &a, &b, &c)!=EOF)
//	{
//		
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if ((a * a + b * b == c * c) || (a * a == b * b + c * c) || (b * b == a * a + c * c))
//			{
//				printf("Right triangle\n");
//			}
//			else if ((a * a + b * b > c * c) && (a * a + c * c > b * b) && (b * b + c * c > a * a))
//			{
//				printf("Acute triangle\n");
//			}
//			else
//				printf("Obtuse triangle\n");
//
//			if ((a == b ) || (a == c ) || (b == c))
//			{
//				printf("Isosceles triangle\n");
//			}
//			if (a == b && b == c)
//			{
//				printf("Equilateral triangle\n");
//			}
//		}
//		else
//			printf("Not triangle\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	long long x = 0;
//	long long  n = 0;
//	scanf("%lld%lld",&x,&n);
//	long long sum = 0;
//	sum += n / 7 * 5 * 250;
//	//printf("%lld", sum);
//	n %= 7; 
//	for (int i = 1; i <= n; i++)
//	{
//		int t = x + i-1;
//		if (t > 7)t -= t;
//		if (t <= 5)sum += 250;
//	}
//	printf("%lld", sum);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int year;
	int month;
	int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d%d", &year,&month);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		arr[1] = 29;
	
	printf("%d", arr[month-1]);

	return 0;
}