#define _CRT_SECURE_NO_WARNINGS 1

////输入一行字符，
////分别统计出其中英文字母、空格、数字和其它字符的个数。
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[10000];
//	int a = 0, b = 0, c = 0, d = 0;
//	gets(arr);
//	int i = 0;
//	int n = strlen(arr);
//	for (i = 0; i < n; i++)
//	{
//		if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
//		{
//			a++;
//		}
//		else if (arr[i] == ' ')
//		{
//			b++;
//		}
//		else if (arr[i] >= '0' && arr[i] <= '9')
//		{
//			c++;
//		}
//		else
//		{
//			d++;
//		}
//	}
//	printf("%d\n%d\n%d\n%d\n", a, b, c, d);
//	return 0;
//}

//#include<stdio.h>
////以科学计数法输出1到30的阶乘和
//int main()
//{
//
//	double sum = 0.0;
//	for (int i = 1; i <= 30; i++)
//	{
//		double x = 1.0;
//		for (int j = 1; j <= i; j++)
//		{
//			x *= j;
//		}
//		sum += x;
//	}
//	printf("%.2e", sum);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//typedef struct info
//{
//	char birth[100];
//	char id[100];
//	char sex[100];
//	double grade;
//}info;
//info s[100] = { 0 };
//int main()
//{
//	
//	
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("#############添加学生信息############\n");
//		printf("请输入需要添加信息的同学的学号:>\n");
//		scanf("%s", s[i].id);
//		printf("请输入需要添加信息的同学的出生日期:>\n");
//		scanf("%s", s[i].birth);
//		printf("请输入需要添加信息的同学的性别:>\n");
//		scanf("%s", s[i].sex);
//		printf("请输入需要添加信息的同学的成绩:>\n");
//		scanf("%lf", &s[i].grade);
//	}
//	printf("学号\t出生日期\t性别\t成绩\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("************************************************\n");
//		printf("%-5s\t%-8s\t%-5s\t%-5.1lf\n", s[i].id, s[i].birth, s[i].sex, s[i].grade);
//	}
//	double min = 100.0;
//	double max = 0.0;
//	double sum = 0.0;
//	for (i = 0; i < 3; i++)
//	{
//		sum += s[i].grade;
//		if (s[i].grade < min)
//		{
//			min = s[i].grade;
//		}
//		if (s[i].grade > max)
//		{
//			max = s[i].grade;
//		}
//	}
//	printf("三个同学的最高分为:%.1lf分,最低分为:%.1lf,平均分为:%.2lf,总分为:%.2lf\n", max, min, sum / 3, sum);
//	return 0;
//}

//
////输入一个正数x和一个正整数n，求下列算式的值。要求定义两个调用函数：
//// fact(n)计算n的阶乘；mypow(x,n)计算x的n次幂（即xn），两个函数的返回值类型是double。
////x - x2 / 2!+ x3 / 3!+ ... + (-1)n - 1xn / n!
////×输出保留4位小数。
//
//#include<stdio.h>
//double Mypow(double x, int n)
//{
//	double res = 1;
//	while (n)
//	{
//		if (n & 1)        // 等价于 if (n % 2 != 0)
//		{
//			res *= x;
//		}
//		n >>= 1;
//		x *= x;
//	}
//	return res;
//}
//
//double fact(int n)
//{
//	double num = 1.0;
//	int i = 1;
//	for (; i <= n; i++)
//	{
//		num *= i;
//	}
//	return num;
//}
//int main()
//{
//	double x;
//	int n;
//	scanf("%lf %d", &x, &n);
//	int i = 2;
//	double ans=x;
//	for (; i <= n; i++)
//	{
//		ans +=( Mypow(-1.000,i-1 )*Mypow(x,i))/fact(i);
//	}
//	printf("%.4lf", ans);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double x, y;
//	scanf("%lf", &x);
//	if (x < 0)
//	{
//		y = fabs(x);
//	}
//	else if (x>=0.0&&x<2.0)
//	{
//		y = sqrt(x+1);
//	}
//	else if (x >= 2.0 && x < 4.0)
//	{
//		y = pow(x + 2, 5);
//	}
//	else if (x>=4.0)
//	{
//		y = 2 * x + 5;
//	}
//	printf("%.2lf", y);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int arr[7][7];
//	int n = 0;
//	scanf("%d", &n);
//	int max = 0;
//	int x = 0;
//	int y = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		
//		for(int j = 1; j <= n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (max < fabs(arr[i][j]))
//			{
//				max = fabs(arr[i][j]);
//			}
//		}
//		
//	}
//	for (int i = 1; i <= n; i++)
//	{
//
//		for (int j = 1; j <= n; j++)
//		{
//			if (max==fabs(arr[i][j]))
//			{
//				printf("%d %d %d\n", arr[i][j], i, j);
//				break;
//			}
//		}
//
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int x = 0, y = 0, z = 0;
//	int n = 1;
//	do 
//	{
//		scanf("%d", &n);
//		if (n >= 85)
//		{
//			x++;
//		}
//		else if (n >= 60 && n < 84)
//		{
//			y++;
//		}
//		else if(n<60&&n>0)
//		{
//			z++;
//		}
//	} while (n);
//	printf(">=85:%d\n60-84:%d\n<60:%d\n", x, y, z);
//	return 0;
//}
//
//#include<stdio.h>
//double fact(int k)
//{
//	int i = 1;
//	double x = 1.000;
//	for (i = 1; i <= k; i++)
//	{
//		x *=(double)i;
//	}
//	return x;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	double sum = 0.0;
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum += 1 / fact(i);
//	}
//	printf("sum=%.5lf\n", sum);
//}

//#include<stdio.h>
//#include<math.h>
//int IsPrime(int n)
//{
//	int i = 2;
//	for (; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 2;
//	for (; i <= n; i++)
//	{
//		if (IsPrime(i))
//			printf("%d\n", i);
//	}
//	return 0;
//}

#include<stdio.h>
#include<string.h>

int main()
{
	char str[1001];
	int n = 0;
	scanf("%d", &n);
	getchar();
	int i = 0;
	for (i = 0; i < n; i++)
	{
		gets(str);
		puts(str);
		printf("\n");
	}
	while (~scanf("%s",str))
	{
		printf("%s\n", str);
		printf("\n");

	}
	return 0;
}

