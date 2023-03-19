#define _CRT_SECURE_NO_WARNINGS 1

//小月白赛64A题
// 
//#include<stdio.h>
//int main()
//{
//	int n, k, a, b;
//	scanf("%d %d %d %d", &n, &k, &a, &b);
//	int ans = 0;
//	if ((a * (n - 1)) > ((k - 1) * b + (n - 1) * b))
//		ans = 1;
//	else if ((a * (n - 1))<((k - 1) * b + (n - 1) * b))
//		ans = 2;
//	else
//		ans = 0;
//	printf("%d\n", ans);
//	return 0;
//}

//文文的进制数比大小
//#include<stdio.h>
//#include<math.h>
//
//long long num(long long  m, int n)
//{
//    int count = 0;
//    long long  sum = 0;
//    int number;
//    while (m)
//    {
//        number = m % 10;
//        m /= 10;
//        sum += number * ((long long)pow(n, count));
//        count++;
//    }
//
//    return sum;
//}
//
//
//int main()
//{
//
//    long long a, c;
//    int b, d;
//    scanf("%lld %d", &a, &b);
//    scanf("%lld %d", &c, &d);
//    long long x = num(a, b);
//    long long y = num(c, d);
//    if (x >= y)
//        printf("Yes");
//    else
//        printf("No");
//    return 0;
//}

//求一个离二进制数最近的平方数
#include<stdio.h>
#include<math.h>
int main()
{
    long long n = 0;
    scanf("%lld", &n);
    long long x = (long long)pow(((long long)sqrt(n)), 2);
    long long y = (long long)pow(((long long)sqrt(n) + 1), 2);
    if ((n - x) > (y - n))
        printf("%lld\n", y);
    else
        printf("%lld\n", x);
    return 0;
}