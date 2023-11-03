#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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

        for (int i = 0; i < n; i++)
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);

        int sum = 0;
        for (auto x : hash) sum += x;

        return sum;
    }

    //最长递增子序列
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
    //摆动序列
    int wiggleMaxLength(vector<int>& nums) {
        /*int n = nums.size();
        vector<int> v, dp(n, 0);
        dp[0] = 1;
        int x = nums[0];
        for (auto e : nums)
        {
            v.push_back(e - x);
            x = e;
        }
        int Max = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (v[i] * v[j] < 0)  dp[i] = max(dp[i], dp[j] + 1);
                else dp[i] = max(dp[i], dp[j]);
            if (v[i] != 0)
                Max = max(dp[i] + 1, Max);
        }
        return Max;*/

        //方法二：
        int n = nums.size();
        vector<int> g(n, 1), f(n, 1);
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) f[i] = max(f[i], g[j] + 1);
                else if (nums[i] < nums[j]) g[i] = max(g[i], f[j] + 1);
            }
            ret = max(ret, max(f[i], g[i]));
        }
        return ret;
    }

    //最长递增子序列的个数
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1),dpCount(n,1);
        int leni = 1, retcount = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                {
                    if (dp[i] == dp[j] + 1)dpCount[i] += dpCount[j];
                    else if (dp[i] < dp[j] + 1)
                    {
                        dpCount[i] = dpCount[j];
                        dp[i] = dp[j]+1;
                    }
                }
            if (leni == dp[i]) retcount += dpCount[i];
            else if (leni < dp[i]) leni = dp[i], retcount = dpCount[i];
        }   
        return retcount;
    }

    //最长数对链
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int Max = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            Max = max(Max, dp[i]);
        }
        return Max;
    }

    //最长定差子序列
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;
        hash[arr[0]] = 1;
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            ret = max(ret, hash[arr[i]]);
        }
        return ret;
    }

    //最长的斐波那契子序列的长度
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ret = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) hash[arr[i]] = i;
        vector<vector<int>>dp(n, vector<int>(n, 2));
        for (int i = 2; i < n; i++)
            for (int j = 1; j < i; j++)
            {
                int x = arr[i] - arr[j];
                if (hash.count(x) && arr[j] > x) dp[j][i] = dp[hash[x]][j] + 1;
                ret = max(ret, dp[j][i]);
            }
        return ret < 3 ? 0 : ret;
    }
};

int main()
{

    return 0;
}