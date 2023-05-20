#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//一维差分
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) insert(i, i, a[i]);


	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}

	for (int i = 1; i <= n; i++) b[i] += b[i - 1];

	for (int i = 1; i <= n; i++) printf("%d ", b[i]);

	return 0;
}


#endif

#if 1
//二维差分
#include <iostream>

using namespace std;
const int N = 1010;
int n, m, q;

int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);

	while (q--)
	{
		int x1, y1, x2, y2,c;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
		insert(x1, y1, x2, y2, c);

	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	return 0;
}



#endif