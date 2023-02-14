#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//初始化数组的函数
//void InitArr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &n, &m);
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	InitArr(arr1, n);//初始化数组arr1
//	InitArr(arr2, m);//初始化数组arr2
//	int j = 0;
//	for (j = 0; j < m; j++)
//	{
//		arr1[n + j] = arr2[j];
//	}
//  //冒泡排序
//	int i = 0;
//	for (i = 0; i < m + n - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m + n - i - 1; j++)
//		{
//			if (arr1[j + 1] < arr1[j])
//			{
//				int temp = arr1[j];
//				arr1[j] = arr1[j + 1];
//				arr1[j + 1] = temp;
//			}
//		}
//	}
// //遍历排序后的数组
//	int k = 0;
//	for (k = 0; k < m + n; k++)
//	{
//		printf("%d ", arr1[k]);
//	}
//	return 0;
//}
//int function(int n)
//{
//	if (n>=2)
//	{
//		return function(n - 1) + function(n - 2);
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = function(n);
//	printf("%d\n", ret);
//	return 0;
//}
#include<math.h>

//int main()
//{
//	long int n = 0;
//	for (n = 10000; n <= 99999; n++)
//	{
//		int i = 10;
//		int sum = 0;
//		while (i<=10000)
//		{
//			sum += (n % i)* (n / i);
//			i *= 10;
//		}
//		if (n == sum)
//		{
//			printf("%ld ", n);
//		}
//	}
//	return 0;
//}
//int main() {
//    int a, b, c;
//    while ((scanf("%d %d %d", &a, &b, &c)) != EOF) {
//        if ((a + b > c) && (a + c > b) && (b + c > a)) {
//            if (a == b || a == c || b == c) {
//                if (a == b && b == c) {
//                    printf("Equilateral triangle!\n");
//                }
//                else
//                    printf("Isosceles triangle!\n");
//            }
//            else {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}

////写一个函数打印arr数组的内容，不使用数组下标，使用指针。
////arr是一个整形一维数组。
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//打印菱形的上半部分
//	int i = 0;
//	for (i = 0; i <=n/2; i++)
//	{
//		int  j = 0;
//		for (j = 0; j < n; j++)
//		{
//			if (j >= n / 2 - i && j <= n / 2 + i)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	 }
//	//打印菱形的下半部分
//	for (i = n/2-1; i >=0; i--)
//	{
//		int  j = 0;
//		for (j = n-1; j >=0; j--)
//		{
//			if (j >= n / 2 - i && j <= n / 2 + i)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}
//#include<math.h>
////求出该数十个几位数
//int count(int m)
//{
//	if (m > 9)
//	{
//		return 1+count(m / 10);
//	}
//	else
//	return 1;
//}
////用递归求水仙花数
//int IsNarcissus(int n,int m)
//{
//	if (n > 9)//判断该数是否位两位及以上的数
//	{
//		return (int)pow(n % 10, m) + IsNarcissus(n / 10,m);//对该数的个位数取出并与其他各个位数上的数字自幂m相加
//	}
//	else
//		return (int)pow(n, m);
//}
//int main()
//{
//	int n = 0;
//	for (n = 0; n <= 100000; n++)
//	{
//		if (IsNarcissus(n,count(n))==n)
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}

////求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
////例如：2 + 22 + 222 + 2222 + 22222
//
//int Sum(int a,int m)
//{
//	if (m != 0)
//	{
//		int sum = 0;
//		int i = 0;
//		for (i = 0; i < m; i++)
//		{
//			sum += a * pow(10, i);
//		}
//		return sum + Sum(a, m - 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	while (1)
//	{
//		int n;
//		printf("请输入一个0到9的数：>");
//		scanf("%d", &n);
//		if (n >= 0 && n <= 9)
//		{
//			int ret = Sum(n,5);
//			printf("%d", ret);
//			break;
//		}
//		printf("输入错误，请重新输入!\n");
//	}
//	
//	
//	return 0;
//}
//#include<string.h>
//
//int main()
//{
//	char arr[100];
//	int i = 0;
//	gets(arr);
//
//	for (i = strlen(arr)-1; i >= 0; i--)
//	{
//		putchar(arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int func(int m)
//{
//    int n = 1, s;     //n:这次新换的，s:上一次换过之后剩余的
//    int sum = m;     //初始化总换取的数量为所给钱数
//    while (n != 0)
//    {
//        n = m / 2;
//        s = m % 2;
//        m = n + s;
//        sum = sum + n;
//    }
//    return sum;
//}
//
//int main()
//{
//    int i = func(20);
//    printf("喝的汽水的总数为：%d", i);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
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
// ------------------------------------
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
// 
//void move(int arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从左边找偶数
//		while ((left < right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//从右边找奇数
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//
//	//1 3 5 7 9 9 7 5 3 1
//	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//
//}
//#include<assert.h>
//#include<stdio.h>
//void my_strcpy(char* dest, const char* src)
//{
//	assert(src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxx";
//	char arr2[] = "hello bit";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

int my_strlen(char* str)
{


	if ((*str++) != '\0')
	{
		return my_strlen(str) + 1;
	}
	return 0;
}
int main()
{
	char str[] = "bitekeji";
	int ret = my_strlen(str);
	printf("%d", ret);
	return 0;
}