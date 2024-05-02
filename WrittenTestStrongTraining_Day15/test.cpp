#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//平方数
long long squareNumber(long long x)
{
	long long a = (long long)(sqrt(x) + 0.5);
	return a * a;
}


//分组
typedef long long ll;
 //判断a数组是否能分成不超过m份，满足每一份数字之和不超过d
// a数组大小
 //返回值：若能成分不超过m份，返回true，否则返回false
 bool check(long long d, int n, int m, vector<int> &a)
 {
	long long sum = 0;             //用来记录当前的那一份的数字之和
	int cnt = 1;                       //在每一份数字之和不超过d的情况下，至少要分成的份数
	
		for (int i = 0; i < n; i++)
		{
		    if (a[i] > d)         //如果单个元素大于了d ，直接返回false
			        return false;
		sum += a[i];          //将a[i]加入当前这一份中
		if (sum > d)
			    {
			    sum = a[i];           //a[i]单独拿出作为一个新组的开头
			        cnt++;
			    }
		}
	return cnt <= m;
	 }



 bool check2(long long d, int n, int m, vector<int > &a)
 {
	    ll sum = 0;
	    int cnt = 1;
	    for (int i = 0; i < n; i++)
		    {
		        if (a[i] > d)
			            return false;
		    sum += a[i];
		        if (sum > d)
			        {
			            sum = a[i];
			            cnt++;
			        }
		}
	
		    return cnt <= m;
}
 // 将所给数组分成连续的m份，使得数字之和最大的那一份的数字之和最小
 // n：数组大小
 // m：题中的m
 // a：所给数组，大小为n
 // 返回值：最优方案中，数字之和最大的那一份的数字之和

 long long getAnswer(int n, int m, vector<int> a)
 {
	// l 表示答案下界->数组中最小的单个数  r 表示答案上界->数组总g和
		long long l = 1, r = 0;
	
		//求出初始上界r
		for (int i = 0; i < n; i++)
		    r += a[i];
	
		//二分答案
		while (l <= r)
		{
		    long long mid = (l + r) >> 1;
		    if (check(mid, n, m, a))      //验证mid可不可能为答案，如果可能，上界缩小
			    r = mid - 1;
		    else
			    l = mid + 1;
	}
	return r + 1;      //r + 1 是最后一个满足check的mid的值
 }

void Grouping()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		    scanf("%d", &a[i]);
	printf("%lld\n", getAnswer(n, m, a));
}

//拓扑图
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N]; // 存放节点的入度
int q[N]; // 队列 -- 用来存放拓扑序列
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
	int hh = 0, tt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0) // 找到所有入度为0的点
		{
			q[tt++] = i; // 这里是只要输出任意一个拓扑序列即可
		}
	}
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--; // 如果最后一个元素入度为1 也就是
			if (d[j] == 0) q[tt++] = j;
		}
	}

	return tt == n;
}

void solve()
{
	cin >> n >> m;

	memset(h, -1, sizeof h);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	if (topsort())
	{
		for (int i = 0; i < n; i++) cout << q[i] << ' ';

	}
	else cout << "-1" << endl;
}

int main()
{
	/*long long n;
	cin >> n;
	cout << squareNumber(n) << endl;*/
	solve();
	return 0;
}