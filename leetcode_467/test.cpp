#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //环绕字符串中唯一的子字符串
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] = dp[i - 1] + 1;

        int hash[26] = { 0 };

        for(int i = 0;i<n;i++)
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);

        int sum = 0;
        for (auto x : hash) sum += x;

        return sum;
    }

    //最长递归子序列
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), Max = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            int maxi = 0;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])dp[i] = max(dp[j] + 1, dp[i]);
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};

int main()
{

	return 0;
}