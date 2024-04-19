#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//反转部分单向链表
void reserve_part()
{
	int n = 0,left,right;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	cin >> left >> right;
	left--;
	while ((left != right) && (left != --right)) {
		swap(v[left], v[right]);
		++left;
	}
	for (auto x : v)cout << x << " ";
}


//猴子分桃
void Pointspeach()
{
	int n = 0;
	while (cin >> n && n != 0)
	{
		cout << (long long)pow(5, n) - 4 << " " << (long long)pow(4, n) + n - 4 << endl;
	}
}



int main()
{
	Pointspeach();
	//reserve_part();
	return 0;
}