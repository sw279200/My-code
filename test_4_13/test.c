#define _CRT_SECURE_NO_WARNINGS 1

////打印DNA的双螺旋结构
//#include <stdio.h>
//void solve()
//{
//	int a = 0, b = 0;
//
//	scanf("%d %d", &a, &b);
//	for (int k = 1; k <= a; k++)
//	{
//		if (k == 1 || k == a)
//		{
//			printf("X");
//		}
//		else
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//	while (b--)
//	{
//		for (int i = 2; i <= a/2; i++)
//		{
//			for (int j = 1; j <= a-i+1; j++)
//			{
//				if (j == i ||j == a-i+1)
//					printf("X");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//		for (int i = (a + 1) / 2; i >=1; i--)
//		{
//			for (int j = 1; j <= a-i+1; j++)
//			{
//				if (j == i || j == a - i + 1)
//					printf("X");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	printf("\n");
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		solve();
//	}
//	
//	return 0;
//}

////IP判断
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <string.h>
////判断是否合法
//int isLegal(char* str)
//{
//	assert(str);
//	char* ps = str;
//	while (*ps)
//	{
//		if ((*ps >= '0' && *ps <= '9') || *ps == '.')
//		{
//			ps++;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	char* pa = str;
//	
//	int count = 3;
//	while (count--&&(*pa))
//	{
//		char arr[4] = { 0 };
//		int i = 0;
//		while (*pa != '.')
//		{
//			arr[i] = *pa;
//			pa++;
//			i++;
//		}
//		pa++;
//		if (strlen(arr) >= 2 && arr[0] == '0')
//			return 0;
//
//		int num = atoi(arr);
//		if (num < 0 || num>255)
//			return 0;
//	}
//	return 1;
//
//}
//int main()
//{
//	char str[31];
//	while (scanf("%s", str) != EOF)
//	{
//		if (isLegal(str)==0)
//		{
//			printf("N\n");
//		}
//		else
//		{
//			printf("Y\n");
//		}
//	}
//	return 0;
//}


////Tom数
////方法一
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//
//	char num[20] = { 0 };
//	while (scanf("%s", num)!=EOF)
//	{
//		int i = 0;
//		long long sum = 0;
//		while (num[i])
//		{
//			sum += num[i]-48;
//			i++;
//		}
//		printf("%lld\n", sum);
//	}
//	return 0;
//}

////Tom数
//
//#include <stdio.h>
////方法二：
//int main()
//{
//
//    long long num = 0;
//    while (scanf("%lld", &num)!=EOF)
//    {
//        int arr[20] = { 0 };
//        int i = 0;
//        while (num)
//        {
//            arr[i] = num % 10;
//            num /= 10;
//            i++;
//        }
//        int sum = 0;
//        for (; i >= 0; i--)
//        {
//            sum += arr[i];
//        }
//        printf("%d\n", sum);
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int n = 0;
//
//	while (scanf("%d", &n) != EOF)
//	{
//		
//		while (n--)
//		{
//			char arr[50] = { 0 };
//			scanf("%s", arr);
//			if (strcmp(arr, "fork") == 0 || 
//				strcmp(arr, "chopsticks") == 0 ||
//				strcmp(arr, "bowl") == 0||
//				strcmp(arr, "knife") == 0)
//				printf("%s ", arr);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int grade = 0;
//	while (~scanf("%d", &grade))
//	{
//		if (grade >= 90 && grade <= 100)
//		{
//			printf("A\n");
//		}
//		else if (grade <= 89 && grade >= 75)
//			printf("B\n");
//		else if (grade >= 60 && grade <= 74)
//			printf("C\n");
//		else if (grade >= 0 && grade <= 59)
//			printf("D\n");
//		else
//			printf("Error!\n");
//	}
//	return 0;
//}

#include <stdio.h>
//程序员的表白
int main()
{
	int n = 0;
	while (~scanf("%d", &n))
	{
		int m = n;
		while (n--)
		{
			for (int i = 1; i <= m + 2; i++)
			{
				if (i == 1 || i == m + 2)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		for (int j = 1; j <= m+2; j++)
		{
			printf("*");
		}
		printf("\n\n");
	}
	return 0;
}