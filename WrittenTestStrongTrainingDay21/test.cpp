#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Ï´ÅÆ
void riffle(vector<int>& nums)
{
	int len = nums.size();
	vector<int> arr1(len/2, 0),arr2(len/2,0);
	for (int i = 0; i < len / 2; i++)
	{
		arr1[i] = nums[i];
		arr2[i] = nums[len / 2 + i];
	}
	int j = 0, k = 0,m = 0;
	while (j < len / 2&&k<len/2)
	{
		nums[m++] = arr1[j++];
		nums[m++] = arr2[k++];
	}

}

//MP3¹â±êÎ»ÖÃ
void solve(int n, string commit)
{
	int cursor = 1,len = commit.size();
	if (n <= 4)
	{
		for (int i = 0; i < len; i++)
		{
			if (cursor == n && commit[i] == 'D')cursor = 1;
			else if (cursor == 1 && commit[i] == 'U') cursor = n;
			else if (commit[i] == 'D') cursor++;
			else if (commit[i] == 'U')cursor--;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		cout << cursor << endl;
	}
	else
	{
		int up = n - 3 , down = n;
		for (int i = 0; i < len; i++)
		{
			if (cursor == n && commit[i] == 'D')
			{
				cursor = 1;
				up = 1;
				down = 4;
			}
			else if (cursor == 1 && commit[i] == 'U') 
			{
				cursor = n;
				down = n;
				up = n - 3;
			}
			else if (cursor == up && commit[i] == 'U')
			{
				up--;
				cursor = up;
				down--;
			}
			else if (cursor == down && commit[i] == 'D')
			{
				down++;
				cursor = down;
				up++;
			}
			else if (commit[i] == 'D') cursor++;
			else if (commit[i] == 'U')cursor--;
		}

		for (int i = up; i <= down; i++) cout << i << " ";
		cout << endl;
		cout << cursor<< endl;
	}
}

int main()
{
	int n = 0;
	string commit;
	cin >> n >> commit;
	solve(n, commit);
	return 0;
}


//
//int main()
//{
//	int T = 0;
//	cin >> T;
//	while (T--)
//	{
//		int n = 0, k = 0;
//		cin >> n >> k;
//		vector<int> v(2*n,0);
//		for (int i = 0; i < 2 * n; i++)cin >> v[i];
//		while (k--) riffle(v);
//		for (int i = 0; i < 2 * n; i++)
//		{
//			if (i == (2 * n)-1) cout << v[i];
//			else cout << v[i] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}