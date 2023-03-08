#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[1001][3];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
//	}
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			int sum1 = arr[i][0] + arr[i][1] + arr[i][2];
//			int sum2 = arr[j][0] + arr[j][1] + arr[j][2];
//			if (abs(arr[i][0] - arr[j][0])<=5 && abs(arr[i][1] - arr[j][1])<=5 && abs(arr[i][2] - arr[j][2])<=5 && i != j && abs(sum1 - sum2)<=10)
//				count++;
//		}
//	}
//	printf("%d",count/2);
//	return 0;
//}
//#include<stdio.h>
//int a[103][103];
//int n, m, k;
//int x, y;
//
////若果是萤石t=2，是火把t=1 
//void light(int x, int y, int t) {
//	for (int i = x - t; i <= x + t; i++) {
//		for (int j = y - t; j <= y + t; j++) {
//			if (i > n || i<1 || j>n || j < 1) {
//				continue;
//			}
//			else {
//				a[i][j] = 1;
//			}
//		}
//	}
//}
//
//void ys(int x, int y) {
//	light(x, y, 2);
//}
//
//void hb(int x, int y) {
//	light(x, y, 1);
//	if (x + 2 <= n) {
//		a[x + 2][y] = 1;
//	}
//	if (x - 2 > 0) {
//		a[x - 2][y] = 1;
//	}
//	if (y + 2 <= n) {
//		a[x][y + 2] = 1;
//	}
//	if (y - 2 > 0) {
//		a[x][y - 2] = 1;
//	}
//}
//
//
//int main() {
//
//	scanf("%d %d %d",&n,&m,&k);
//	for (int i = 1; i <= m; i++) {
//		scanf("%d %d", &x, &y);
//		hb(x, y);
//	}
//	for (int i = 1; i <= k; i++) {
//		scanf("%d %d",&x,&y);
//		ys(x, y);
//	}
//
//
//	int count = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (a[i][j] == 0) {
//				count++;
//			}
//		}
//	}
//	printf("%d",count);
//
//	return 0;
//}
//#include<stdio.h>
////在屏幕上打印倒的杨辉三角。
//
//int main()
//{
//	int n = 0;
//	int arr[20][20]={0};
//	//输入一个1-20的数
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//
//	for (i = 2; i < n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i - 1; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (i = n-1; i>=0; i--)
//	{
//		int j = 0;
//		for(j = i; j>=0; j--)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	int n, m, a[3000]={0}, i, j, k, min = 0;
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	for (i = 0; i < n - m + 1; i++) {
//		k = 0;
//		if (i == 0) {
//			for (j = i; j < i + m; j++)
//				min += a[j];
//		}
//		else {
//			for (j = i; j < i + m; j++)
//				k += a[j];
//			if (k < min) min = k;
//		}
//	}
//	printf("%d", min);
//	return 0;
//}
#include<stdio.h>

int main()
{
	char str[1100][4];
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%s", &str[i]);
	}
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if ((str[j][0] == 'Y' || str[j][0] == 'y') && (str[j][1] == 'E' || str[j][1] == 'e') && (str[j][2] == 'S' || str[j][2] == 's'))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
