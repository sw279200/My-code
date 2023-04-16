#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>
#include <math.h>
//数列第几个数是多少？
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 2;//记录是第几个数，从第三个数开始算
    int num1 = 1;
    int num2 = n;
    int temp = 0;

    while (count < n)
    {
        temp = fabs(num2 - num1);
        num1 = num2;
        num2 = temp;
        count++;//代表temp是运算到的第几个数

    }

    printf("%d\n", temp);

    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>


int main() {
    char a[1001], b[1001], ans[1001];
    while (scanf("%s %s", &a, &b) != EOF) {
        // 计算输入数字长度
        int lena = strlen(a);
        int lenb = strlen(b);
        /**
         * 大数相加，倒序计算每一位的和
         * i: a的指针
         * j: b的指针
         * t: 计算结果ans的指针
         * k: 进位
         */
        int i, j, t = 0, k = 0;
        for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
            int temp = k + (a[i] - '0') + (b[j] - '0');
            ans[t++] = temp % 10 + '0';
            k = temp / 10;
        }
        while (k || i >= 0 || j >= 0) { // 进位不为0，或者两个数中任意一个指针没有走完所有位
            int temp = (k + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0));
            ans[t++] = temp % 10 + '0';
            k = temp / 10;
            i--;
            j--;
        }
        // 倒序输出计算结果
        while (t) {
            printf("%c", ans[--t]);
        }
        printf("\n");
    }
}
#endif

#if 1
#include<stdio.h>
#include <string.h>
int main()
{
    int a[100], i, j, n, t, s = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = n; i < 2 * n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] > a[i + n])  s -= 50;
            if (a[i] < a[i + n])  s += 50;
            if (a[i] == a[i + n]);
        }

        if (s >= 0) printf("%d\n", s);
        else printf("0\n");    //挣的钱最少为0元

        s = 0;  //初始化s的值
    }

    return 0;
}

#endif