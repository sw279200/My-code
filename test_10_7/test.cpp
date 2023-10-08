#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
#include<stdio.h>
using namespace std;


/*void solve()
{
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 1; i < 16; i++)
	{
		if (i%2==1&&s[i] != '0')
		{
			flag = false;
			break;
		}
	}

	if (flag) cout << "Yes" << endl;
	else  cout << "No" << endl;
}*/

bool cmp2(pair<int, int>a, pair<int, int> b) {
	if (a.second == b.second)  return a.first < b.first;
	return a.second > b.second;//¶ÔÓÚsecondµÄÉýÐò
}
void solve()
{
	int n = 0;
	cin >> n;
	map<int, int>hash;
	vector<pair<int, int>> vecs;
	
	
	for (int i = 0; i < n; i++)
	{	
		bool flag = false;
		for (int j = 0; j <n; j++)
		{
			char t; cin >> t;
			if (t == 'o')
			{
				hash[i + 1]++;
				flag = true;
			}
			
		}
		if (!flag) hash[i + 1] = 0;
	}
	for (auto it = hash.begin(); it != hash.end(); it++) {
		vecs.push_back(make_pair(it->first, it->second));
	}
	sort(vecs.begin(), vecs.end(), cmp2);
	for (auto t : vecs)cout << t.first << " ";
	cout << endl;
}

int main()
{
	solve();
	return 0;
}