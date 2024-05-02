#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//ƽ����
long long squareNumber(long long x)
{
	long long a = (long long)(sqrt(x) + 0.5);
	return a * a;
}


//����
typedef long long ll;
 //�ж�a�����Ƿ��ֳܷɲ�����m�ݣ�����ÿһ������֮�Ͳ�����d
// a�����С
 //����ֵ�����ܳɷֲ�����m�ݣ�����true�����򷵻�false
 bool check(long long d, int n, int m, vector<int> &a)
 {
	long long sum = 0;             //������¼��ǰ����һ�ݵ�����֮��
	int cnt = 1;                       //��ÿһ������֮�Ͳ�����d������£�����Ҫ�ֳɵķ���
	
		for (int i = 0; i < n; i++)
		{
		    if (a[i] > d)         //�������Ԫ�ش�����d ��ֱ�ӷ���false
			        return false;
		sum += a[i];          //��a[i]���뵱ǰ��һ����
		if (sum > d)
			    {
			    sum = a[i];           //a[i]�����ó���Ϊһ������Ŀ�ͷ
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
 // ����������ֳ�������m�ݣ�ʹ������֮��������һ�ݵ�����֮����С
 // n�������С
 // m�����е�m
 // a���������飬��СΪn
 // ����ֵ�����ŷ����У�����֮��������һ�ݵ�����֮��

 long long getAnswer(int n, int m, vector<int> a)
 {
	// l ��ʾ���½�->��������С�ĵ�����  r ��ʾ���Ͻ�->������g��
		long long l = 1, r = 0;
	
		//�����ʼ�Ͻ�r
		for (int i = 0; i < n; i++)
		    r += a[i];
	
		//���ִ�
		while (l <= r)
		{
		    long long mid = (l + r) >> 1;
		    if (check(mid, n, m, a))      //��֤mid�ɲ�����Ϊ�𰸣�������ܣ��Ͻ���С
			    r = mid - 1;
		    else
			    l = mid + 1;
	}
	return r + 1;      //r + 1 �����һ������check��mid��ֵ
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

//����ͼ
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N]; // ��Žڵ�����
int q[N]; // ���� -- ���������������
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
	int hh = 0, tt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0) // �ҵ��������Ϊ0�ĵ�
		{
			q[tt++] = i; // ������ֻҪ�������һ���������м���
		}
	}
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--; // ������һ��Ԫ�����Ϊ1 Ҳ����
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