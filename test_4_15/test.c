#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>

int Max(int x, int y)
{
	return x > y ? x : y;
}
//��Զ�ķᱮ
int main()
{
	int n = 0;
	int arr[11] = {0};
	while (~scanf("%d", &n)&&n!=0)
	{
		
		int i = 0;
		int max = 0;
		for (; i < n; i++)
		{
			scanf("%d", &arr[i]);
			max = Max(max, arr[i]);
		}
		printf("%d\n", max);
	}
	return 0;
}

#endif


#if 0
//���ǹ�
#include <stdio.h>
//�ж�����С���ѵ��ǹ������Ƿ���ͬ
int isSame(int arr[], int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		if (arr[i] != arr[0])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n = 0;
	int arr[100] = { 0 };
	int Share[100] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//������¼��ʦ�������ǹ�����
	int count = 0;
	while (isSame(arr, n))//ֱ������С���ѵ��ǹ�����ͬ������ѭ��
	{
		for (int i = 0; i < n; i++)
		{
			Share[i+1] = arr[i]/2;
		}

		//ÿ��С���Ѷ����Լ���һ���ǹ����ָ��Լ���ߵ�С����
		for (int i = 1; i < n; i++)
		{
			arr[i] = arr[i] / 2 + Share[i];
		}
		arr[0] = arr[0] / 2 + Share[n];
		
		for (int j = 0; j < n; j++)
		{
			//�ж���ЩС�������������ǹ�
			if (arr[j] % 2 == 1)
			{
				//��ʦ��������С����һ���ǹ�
				arr[j] += 1;
				//��¼��ʦ�����ǹ�������
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
#endif


#if 0
//������
#include <stdio.h>
#include <stdlib.h>
//�ж��Ƿ��ǻ�����
int isPalindromic(int num,int n)
{
	int arr[12] = { 0 };
	int count = 0;
	int sum = 0;
	while (num)
	{
		arr[count] = num % 10;
		sum += arr[count];
		count++;
		num /= 10;
	}
	count--;
	int flag = 0;
	int left = 0;
	while (left < count)
	{
		if (arr[left++] != arr[count--])
		{
			flag = 1;
			break;
		}
	}
	if (sum == n && flag == 0)
	{
		return 1;
	}
	else
	{
		return  0;
	}
}
int main()
{
	int flag = 0;
	int n = 0;
	scanf("%d", &n);
	for (int i = 10000; i <= 999999; i++)
	{
		if (isPalindromic(i, n))
		{
			flag = 1;
			printf("%d\n", i);
		}
	}
	if (flag == 0)
		printf("-1\n");
	return 0;
}
#endif

#if 0

#include <stdio.h>

int gcb(int a, int b) {
	return b == 0 ? a : gcb(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcb(a, b);
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	//printf("%d", lcm(18, 24));
	scanf("%d %d %d", &a, &b, &c);
	int t = lcm(a, lcm(b, c));
	printf("%d", t);
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int n = 0;
	int k = 0;
	int t = 0;
	scanf("%d %d %d", &n, &k, &t);
	int sum = 0;
	int count = 1;
	while (count / n != t)
	{
		if (count > k - 1&&count%n==1)
		{
			sum += count % k;
		}
		 if(count%n==1&&count<=k-1)
		sum += count;
		count++;
	}
	printf("%d\n", sum);
	return 0;
}
#endif

#include <stdio.h>
//������Ϸ

int main(void)
{
	long long n, k, t, s = 0;
	scanf("%lld%lld%lld", &n, &k, &t);
	for (long long i = 0; i < t; i++)
		s += i * n % 2 == 0 ? ((i * n / 2 % k) * ((i * n + 1) % k) + 1) % k : ((i * n % k) * ((i * n + 1) / 2 % k) + 1) % k;
	printf("%lld", s);
	return 0;
}