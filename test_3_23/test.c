#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//С������63ħ��ʦ��ӵ
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int arr[101] = { 0 };
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int sum = 0;//�ܹ���
//	int hurt = 2;//�˺�
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int j = 0;
//	for (j = 0; j < m; j++)
//	{
//		for (i = 0; i < n; i++)
//		{
//			if (arr[i] == hurt)
//			{
//				hurt++;
//				arr[i] -= hurt;
//			}
//			else
//			{
//				arr[i] -= hurt;
//			}
//			
//		}
//		sum += hurt;
//		
//	}
//	
//	printf("%d\n", sum);
//}

#include<stdio.h>
void solve()
{
	int n = 0;
	int tree_high[1001] = { 0 };
	scanf("%d", &n);
	int i = 0;
	int a, k, b, m;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tree_high[i]);
	}
	scanf("%d %d %d", &a, &k, &b);
	scanf("%d", &m);
	m -= 1;//�ڶ���Ż�����
	for (i = 0; i < m ; i++)
	{
		int j = 0;
		for (j = 0; j < n; j++)
		{

			tree_high[j] += a;//ÿ�춼�᳤a����

			if (tree_high[j] > k)
			{
				tree_high[j] = b;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", tree_high[i]);
	}
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
	return 0;
}