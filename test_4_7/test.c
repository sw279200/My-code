#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define N 1000000
//有n人围成一圈，顺序排号。从第1个人开始报数（从1到3报数），
 //凡报到3的人退出圈子，问最后留下的是原来的第几号的那位
 
void main()
{
	int group[N];
	int totalNum = 0, restNum = 0, count = 0, roundcount = 0;

	scanf("%d", &totalNum);

	//排号操作
	for (int i = 0; i < totalNum; i++)
	{
		group[i] = i + 1;
	}

	restNum = totalNum;

	//只要不只剩下一个人,那么就重复报数
	while (restNum > 1)
	{
		roundcount = 0;
		//遍历整个数组,重复报数,直到一轮结束
		while (roundcount < totalNum)
		{
			if (group[roundcount] != 0)
			{
				count++;
				//报到3重头报数
				if (count == 3)
				{
					group[roundcount] = 0;//退出的人以0为标识
					restNum--;
					count = 0;
				}
			}
			roundcount++;
		}
	}

	for (int i = 0; i < totalNum; i++)
	{
		if (group[i] != 0)
		{
			printf("%d", group[i]);
			break;
		}
	}
}

//#include<stdio.h>
////进制转换
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[20] = { 0 };
//	int i = 0;
//	while (n)
//	{
//		arr[i++] = n % 8;
//		n /= 8;
//		
//	}
//	while (i--)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

