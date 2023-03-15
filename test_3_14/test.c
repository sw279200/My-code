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
#include<string.h>
int a[10000000];//判断安全牌是否使用过

int safe[3];//暂存安全牌
int main() {
    memset(a, 0, sizeof(a));//所有安全牌数值置0
    int m, q;
    int cnt = 0;//判断有几张安全牌
    scanf("%d%d", &m, &q);
    for (int i = 1; i <= q; i++) {
        int op;// 1对方拿牌 2对方弃牌
        int sum;//对方拿到的牌
        scanf("%d%d", &op, &sum);
        int l = (sum - 3);//对方拿到的牌 你对应的安全牌(x-3)
        int r = (sum + 3);//对方拿到的牌 你对应的安全牌(x+3)
        safe[1] = l;
        safe[2] = r;
        for (int j = 1; j <= 2; j++) {
            if (safe[j]<1 || safe[j]>m)continue;//越界抛出
            //对方拿牌
            if (op == 1) {
                if (a[safe[j]] == 0) {//表示这个安全牌没使用
                    cnt++;//安全牌数量增加
                }
                //对应安全牌数量增加
                a[safe[j]]++;
            }
            //对方弃牌
            else {
                if (a[safe[j]] == 1) {
                    //若对方手上只有一张并且要扔
                    // 那你对应的安全牌也可以扔了
                    cnt--;//安全牌数量减少
                }
                //对应安全牌数量减少
                a[safe[j]]--;
            }
        }
        printf("%d\n", cnt);
    }

}


