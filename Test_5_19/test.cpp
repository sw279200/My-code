#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//高精度乘法

#include <iostream>
using namespace std;
#include <vector>

vector<int> mul(vector<int>A, int b)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int>A;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}

	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; i--)
	{
		printf("%d", C[i]);
	}
	return 0;
}

#endif

#if 0
//高精度除法

#include <iostream>
using namespace std;
#include <vector>

vector<int> div(vector<int>A, int b,int &r)
{
	vector<int>C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}

	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int>A;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	int r;//余数
	auto C = div(A, b,r);
	for (int i = C.size() - 1; i >= 0; i--)
	{
		printf("%d", C[i]);
	}
	cout << endl << r << endl;
	return 0;
}

#endif


#if 0
#include <iostream>
using namespace std;

#include <vector>
//求前缀和
const int N = 100010;
int a[N],s[N];
int m, n;

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}

	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}


#endif

#if 1

#include <iostream>
using namespace std;
const int N = 1010;
int a[N][N], s[N][N];
int n, m, q;
int main()
{

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	while (q--)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	}

	return 0;
}


#endif