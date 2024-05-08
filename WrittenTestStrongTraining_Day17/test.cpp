#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;

//小乐乐改数字
void solve()
{
	int n;
	cin >> n;
	vector<int> v;
	while (n)
	{
		if ((n % 10) % 2 == 0)v.push_back(0);
		else v.push_back(1);
		n /= 10;
	}
	long long sum = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		sum += v[i];
		if (i != 0)sum *= 10;
	}
	cout << sum;
}


//十字爆破
void CrossBlasting()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> vv(n, vector<int>(m));
	vector<long long> rowSum(n), lineSum(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vv[i][j]);
			rowSum[i] += vv[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			lineSum[i] += vv[j][i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << rowSum[i] + lineSum[j] - vv[i][j] << " ";
		}
		cout << endl;
	}

}


//比那名居的桃子
int inf = 9999999;
long long a[1100000], b[1100000];

void solve2()
{
	int n, m, i, flag, t;
	long long maxx, minn;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		if (i == 1)
			a[1] = t;
		else a[i] = t + a[i - 1];
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		if (i == 1)
			b[i] = t;
		else b[i] = t + b[i - 1];
	}
	maxx = -inf;
	minn = inf;
	for (i = 1; i <= n; i++)
	{
		if (a[i + m - 1] - a[i - 1] > maxx)
		{
			flag = i;
			maxx = a[i + m - 1] - a[i - 1];
			minn = b[i + m - 1] - b[i - 1];
		}
		else if (a[i + m - 1] - a[i - 1] == maxx && b[i + m - 1] - b[i - 1] < minn)
		{
			flag = i;
			minn = b[i + m - 1] - b[i - 1];
		}
	}
	printf("%d\n", flag);
}




int main() {
	solve2();
	//CrossBlasting();
}