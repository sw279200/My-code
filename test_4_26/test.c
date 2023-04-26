#define _CRT_SECURE_NO_WARNINGS 1




//鞍点
#include<stdio.h>


int Max(int x, int y)
{
    return x > y ? x : y;
}

int Min(int x, int y)
{
    return x < y ? x : y;
}

void solve()
{

    int arr[20][20] = { 0 };
    int n, m;
    scanf("%d %d", &n, &m);
    int max[20] = { -9999999999 };
    int min[20] = { 9999999999 };
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            scanf("%d", &arr[i][j]);
            max[i] = Max(max[i], arr[i][j]);//把每一行的最大值存起来
        }
    }
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            min[i] = Min(min[i], arr[j][i]);//把每一行列的最小值存起来
        }
    }
    int flag = 0;
    int l = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((arr[i][j] == max[i]) && (arr[i][j] == min[j]))
            {
                l = i;
                c = j;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        printf("%d:%d,%d\n", arr[l][c], l, c);
    }
    else
    {
        printf("not found\n");
    }
}
int main()
{

    solve();
    return 0;
}

