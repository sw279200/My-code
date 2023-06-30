

#if 0
#include <iostream>

using namespace std;
int count(int n)
{
	int m = 1;
	while (n > 0)
	{
		n /= 10;
		m*=10;
	}

	return m;
}

bool solve(int n)
{
	if ((n * n) % count(n) == n)
		return true;
	else
		return false;
}

//n以内自守数的数量
int main()
{
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		if (solve(i))
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}


#endif

#include <iostream>

using namespace std;
#include <math.h>

//求小于n的质数的个数
bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 2;i<=n-1;i++)
	{
		if (isPrime(i))
			count++;
	}
	cout << count << endl;
	return 0;
}

