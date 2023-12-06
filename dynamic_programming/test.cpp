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

    //最长等差数列
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> hash;
        hash[nums[0]] = 0;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ret = 2;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = 2 * nums[i] - nums[j];
                if (hash.count(a)) dp[i][j] = dp[hash[a]][i] + 1;

                ret = max(ret, dp[i][j]);
            }
            hash[nums[i]] = i;
        }
        return ret;
    }

    //等差数列划分 II - 子序列
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<int>>hash;
        for (int i = 0; i < n; i++) hash[nums[i]].push_back(i);
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int sum = 0;
        for (int j = 2; j < n; j++)
        {
            for (int i = 1; i < j; i++)
            {
                long long a = (long long)2 * nums[i] - nums[j];
                if (hash.count(a))
                {
                    for (auto k : hash[a])
                    {
                        if (k < i) dp[i][j] += dp[k][i] + 1;
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }


    // 回文子串
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n));
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j)dp[i][j] = 1;
                    else if (i + 1 == j)dp[i][j] = 1;
                    else if (dp[i + 1][j - 1] == 1)dp[i][j] = 1;
                }
                ret += dp[i][j];
            }
        }

        return ret;
    }


    //最长回文子串
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int start = 0, end = 0,len = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j) dp[i][j] = 1;
                    else if (i + 1 == j)dp[i][j] = 1;
                    else if (dp[i + 1][j - 1] == 1)dp[i][j] = 1;
                    if (dp[i][j]==1&&len < j - i + 1)
                    {
                        len = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, len);    
    }

    //1745. 分割回文串 IV
    bool checkPartitioning(string s) {
        /*int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n));
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j)dp[i][j] = 1;
                    else if (i + 1 == j)dp[i][j] = 1;
                    else if (dp[i + 1][j - 1] == 1)dp[i][j] = 1;
                }
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i; j < n - 1; j++)
            {
                if (dp[0][i - 1] == 1 && dp[i][j] == 1 && dp[j + 1][n - 1] == 1)
                {
                    return true;
                }
            }
        }

        return false;*/

        // 1. ⽤ dp 把所有的⼦串是否是回⽂预处理⼀下
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
        // 2. 枚举所有的第⼆个字符串的起始位置以及结束位置
        for (int i = 1; i < n - 1; i++)
            for (int j = i; j < n - 1; j++)
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                    return true;
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.countSubstrings("dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg") << endl;
    return 0;
}