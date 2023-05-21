#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <iostream>
using namespace std;
//最长连续不重复子序列
const int N = 100010;

int n;
int a[N], s[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		s[a[i]]++;
		while (s[a[i]] > 1)
		{
			s[a[j]]--;
			j++;
		}

		res = max(res, i - j + 1);
	}

	cout << res << endl;
}


#endif


#if 0

#include <iostream>
using namespace std;

int lowbit(int x)
{
	return x & (~x + 1);
}

int main()
{
	int  n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;

		int res = 0;
		while (x) x -= lowbit(x), res++;

		cout << res << " ";
	}

	////二进制形式
	//int n = 10;
	//unsigned int x = -n;

	//for (int i = 31; i >= 0; i--) cout << (x >> i & 1);
	//cout << endl;

	
}

#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> query, add;


int find(int x)
{
	int l = 0, r = alls.size() - 1;

	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x,c });
		alls.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({ l,r });

		alls.push_back(l);
		alls.push_back(r);
	}
	//去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	//处理插入
	for (auto item: add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}

	//处理前缀和
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	//处理询问
	for (auto item : query)
	{
		int l = find(item.first);
		int r = find(item.second);

		cout << s[r] - s[l - 1] << endl;
	}

}

#endif


#if 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;

const int N = 10010;

int n;

vector<PII> segs;
//区间和并
void merge(vector<PII>& segs)
{
	vector<PII> res;

	sort(segs.begin(), segs.end());
	int start = -2e9;
	int end = -2e9;
	for (auto seg : segs)
	{
		if (end < seg.first)
		{
			if (start != -2e9) res.push_back({ start,end });
			start = seg.first;
			end = seg.second;

		}
		else
		{
			end = max(end, seg.second);
		}
	}
	if (start != -2e9) res.push_back({ start,end });

	segs = res;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left, right;
		cin >> left >> right;
		segs.push_back({ left,right});
	}

	merge(segs);

	cout << segs.size() << endl;
	return 0;
}

#endif