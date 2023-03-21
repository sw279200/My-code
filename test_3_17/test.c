#define _CRT_SECURE_NO_WARNINGS 1

////牛客小白月赛66重现赛
//#include<stdio.h>
//int main()
//{
//	int T = 0;
//	int n = 0;
//	
//	int arr[1100] = { 0 };
//	scanf("%d", &T);
//	while (T--)
//	{
//		int i = 0;
//		int flag = -1;
//		int count = 0;
//		scanf("%d", &n);
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i + 1]);
//			if (arr[1] % 2 == 1)
//			{
//				flag = 0;
//			}
//			else if(arr[i + 1] % 2 == 1&&arr[i+1]<arr[1]&&i>0)
//			{
//				flag = 1;
//			}
//
//		}
//		printf("%d\n", flag);
//	}
//	return 0;
//}

#include<stdio.h>
char arr1[200010] = { ' ' };
char arr2[200010] = { ' ' };
//把一个n位数的各个位数上的数存在数组中

void solve()
{
    int n = 0;
    scanf("%d", &n);
    char* A = arr1 + 1;
    char* B = arr2 + 1;
    scanf("%s", A);
    scanf("%s", B);
    int m = 0;
    for (m = 1; m <= n; m++)
    {
        if (arr1[m] > arr2[m])
        {
            printf("%d %d\n", m, m);
            return;
        }
    }
    for (m = 1; m <= n; m++)
    {
        if (arr1[m] == arr2[m])
        {
            printf("%d %d\n", m, m);
            return;
        }
    }
    printf("%d %d\n", n, n);
}
int main()
{
    int T = 0;
    scanf("%d", &T);

    while (T--)
    {
        solve();
    }
    return 0;
}

