#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//ÆûË®Æ¿
int pressurized_bottle(int n)
{
	if (n == 1||n==0) return 0;
	else if (n == 2) return 1;
	else return n / 3 + pressurized_bottle(n/3+n % 3);
}

void solve()
{
	int n = 1;
	while (cin >> n && n != 0)
	{
		cout << pressurized_bottle(n) << endl;
	}
}

void solution()
{
	string strA, strB;
	getline(cin, strA);
	getline(cin, strB);



}

int main()
{
	//solve();
	return 0;
}