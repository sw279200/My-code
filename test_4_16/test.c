#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>
#include <math.h>
//���еڼ������Ƕ��٣�
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 2;//��¼�ǵڼ��������ӵ���������ʼ��
    int num1 = 1;
    int num2 = n;
    int temp = 0;

    while (count < n)
    {
        temp = fabs(num2 - num1);
        num1 = num2;
        num2 = temp;
        count++;//����temp�����㵽�ĵڼ�����

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
        // �����������ֳ���
        int lena = strlen(a);
        int lenb = strlen(b);
        /**
         * ������ӣ��������ÿһλ�ĺ�
         * i: a��ָ��
         * j: b��ָ��
         * t: ������ans��ָ��
         * k: ��λ
         */
        int i, j, t = 0, k = 0;
        for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
            int temp = k + (a[i] - '0') + (b[j] - '0');
            ans[t++] = temp % 10 + '0';
            k = temp / 10;
        }
        while (k || i >= 0 || j >= 0) { // ��λ��Ϊ0������������������һ��ָ��û����������λ
            int temp = (k + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0));
            ans[t++] = temp % 10 + '0';
            k = temp / 10;
            i--;
            j--;
        }
        // �������������
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
        else printf("0\n");    //����Ǯ����Ϊ0Ԫ

        s = 0;  //��ʼ��s��ֵ
    }

    return 0;
}

#endif