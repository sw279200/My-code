#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void Space_replacement()
{
	string str;
	getline(cin, str);
	string s("");
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			s += "%100";
		else s += str[i];
	}
	cout << s << endl;
}

void binary_chop()
{
	int n = 0, v = 0;
	cin >> n >> v;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n==0||(n>0&&arr[n - 1] < v))
	{
		cout << n + 1 << endl;
		return;
	}

	int left = 0, right = n - 1;
	while (left < right)
	{
		int mid = left + (right - left) >> 1;
		if (arr[mid] >= v) right = mid;
		else left = mid + 1;
	}

	cout << left + 1 << endl;
}


int main()
{
	binary_chop();
	//Space_replacement();
	return 0;
}