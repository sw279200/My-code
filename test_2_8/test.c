#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//int num_sum(int m,int n)
//{
//	int i = 0;
//	int sum = 1;
//	
//	for (i = 0; i < m; i++)
//	{
//		int j = 0;
//		int ret = (n-1)*pow(n,m-i-1);
//			sum += ret;
//	}
//	return sum;
//}
//
//int main()
//{
//	unsigned int x;
//	unsigned int y;
//	int ans;
//	scanf("%d %d", &x, &y);
//	int x_count = num_sum(y,x);
//	int y_count = num_sum(x,y);
//	if (x_count == y_count)
//	{
//		printf("%d", x > y ? y : x);
//	}
//	else if (x_count > y_count)
//	{
//		printf("%d", x);
//	}
//	else
//		printf("%d", y);
//	return 0;
//}
//#include<assert.h>
//#include<string.h>
//void reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	scanf("%s", arr);//abcdef--->fedcba
//	//������
//	reverse(arr);
//	printf("�������ַ�����%s\n", arr);
//
//	return 0;
//}
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�i�Ƿ���ˮ�ɻ�������������
		//1.����i��λ�� - nλ��
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp /= 10)
		{
			n++;
		}
		//2.����i��ÿһλ��n�η�֮��sum
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//3.�Ƚ�i==sum
		if (i == sum)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
