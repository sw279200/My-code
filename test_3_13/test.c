#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[18]={0};
//	int i = 0;
//	for (i = 0; i < 18; i++)
//	{
//		if (i <= n - 1)
//		{
//			arr[i] = 1;
//		}
//		
//		if ((i+1)%6==0)
//			printf("%d\n", arr[i]);
//		else
//		printf("%d", arr[i]);
//		
//	}
//	return 0;
//}

#include<stdio.h>

void del_num(int arr[], int n,int num)
{
	int i = 0;
	int sz = 0;
	for (i = 0; i < n; i++)
	{
		if (*(arr + i) == num)
		{
			break;
		}
	}
	for (; i < n-1; i++)
	{
		*(arr + i) = *(arr + i + 1);
	}
}
int main()
{
	
	return 0;
}