#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int minSum = INT_MAX;
		int maxSum = 0;
		for (int i = 0; i < len; i++)
		{
			if (minSum > arr[i]) minSum = arr[i];
			maxSum += arr[i];
		}

		vector<int> dp(maxSum + 1);
		dp[0] = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = maxSum; j >= arr[i]; --j)
			{
				dp[j] = max(dp[j - arr[i]] + arr[i], dp[j]);
			}
		}

		for (int j = minSum; j <= maxSum; j++)
		{
			if (dp[j] != j)
			{
				return j;
			}
		}

		return maxSum + 1;
	}
};

int main() {
	int n = 0;
	while (cin >> n && n != 0)
	{
		int count = log2(n);		
		cout << count << endl;
	}
	return 0;
}
// 64 位输出请用 printf("%lld")