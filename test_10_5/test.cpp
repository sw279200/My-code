#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//简单多状态dp

class Solution {
public:
    //面试题 17.16.按摩师
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> f(n), g(n);//f[i]代表预约到i位置时，选择i位置的值的最大值
        //g[i]表示预约到i位置时，不选i位置的值的最大值

        f[0] = nums[0];//初始化

        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[n - 1], g[n - 1]);
    }

    //213. 打家劫舍 II
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + _rob(2, n - 2, nums), _rob(1, n - 1, nums));
    }

    int _rob(int left, int right, vector<int>& nums)
    {
        if (left > right) return 0;
        int n =nums.size();
        //创建dp表
        vector<int> f(n), g(n);

        //初始化
        f[left] = nums[left];

        for (int i = left + 1; i <= right; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);

        }

        return max(g[right], f[right]);
    }

    //删除并获得点数
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        const int N = 10001;
        vector<int>arr(N);
        for (auto x : nums) arr[x] += x;

        vector<int> f(N), g(N);
        f[0] = arr[0];

        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }

        return max(f[N-1], g[N-1]);
    }

    //LCR 091. 粉刷房子
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n+1, vector<int>(3));

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }

        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }

    //309. 买卖股票的最佳时机含冷冻期
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return max(dp[n - 1][1], dp[n - 1][2]);

    }

    //714. 买卖股票的最佳时机含手续费
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    //123. 买卖股票的最佳时机 III
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int m = 3;
        const int N = -0x3f3f3f3f;
        vector<vector<int>> f(n, vector<int>(m, N));
        vector<vector<int>> g(n, vector<int>(m, N));

        f[0][0] = -prices[0]; g[0][0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                if (j - 1 >= 0) g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        int ret = N;
        for (int i = 0; i < m; i++) ret = max(ret, g[n - 1][i]);
        return ret;
    }

    //188. 买卖股票的最佳时机 IV
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int m = min(k, n / 2);
        const int N = 0x3f3f3f3f;
        vector<vector<int>> f(n, vector<int>(m + 1, -N));
        vector<vector<int>> g(n, vector<int>(m + 1, -N));

        f[0][0] = -prices[0]; g[0][0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                if (j - 1 >= 0) g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        int ret = 0;
        for (int i = 0; i <= m; i++) ret = max(ret, g[n - 1][i]);
        return ret;
    }
};

int main()
{

	return 0;
}