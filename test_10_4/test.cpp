#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    //第 N 个泰波那契数
    //动态规划求解步骤
    //1. 找出状态表示
    //2. 状态转换方程
    //3. 初始化
    //4. dp表填表顺序
    //5. 返回值

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int a = 0, b = 1, c = 1, d = 0;
        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b; b = c; c = d;
        }

        return d;
    }

    //面试题 08.01. 三步问题
    int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;

        unsigned int a = 1, b = 2, c = 4, d = 0;
        for (int i = 4; i <= n; i++)
        {
            d = a + b + c;
            d %= 1000000007;
            a = b; b = c; c = d;
        }
        return d;
    }

    //746. 使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost) {
       //方法一
        //int n = cost.size();
        //vector<int> dp(n+1);

        ////结合状态转换方程
        //for (int i = 2; i <= n; i++)
        //    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        //return dp[n];

        //方法二
        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];

        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = min(dp[i + 1] + cost[i], dp[i + 2] + cost[i]);
        }

        return min(dp[0], dp[1]);
    }

    //解码方法
    int numDecodings(string s) {
        //  int n = s.size();
      //   vector<int> dp(n);
      //   //初始化
      //   dp[0] = s[0] != '0';
      //   if (n == 1) return dp[0];

      //   //判断单独解码是否成功
      //   if (s[0] != '0' && s[1] != '0')dp[1] += 1;
      //   int t = (s[0] - '0') * 10 + s[1] - '0';
      //   if (t >= 10 && t <= 26) dp[1] += 1;//判断两个字符结合是否解码成功

      //   for (int i = 2; i < n; i++)
      //   {
      //       if (s[i] != '0') dp[i] += dp[i - 1];
      //       int tmp = (s[i-1] - '0') * 10 + s[i] - '0';
      //       if (tmp >= 10 && tmp <= 26) dp[i] += dp[i-2];
      //   }

      //   return dp[n - 1];

      //优化
        int n = s.size();
        vector<int> dp(n + 1);
        //初始化
        dp[0] = 1;
        dp[1] = s[1 - 1] != '0';
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }

    //不同路径
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }

    //不同路径II
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (obstacleGrid[i - 1][j - 1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
        return dp[m][n];
    }

    //LCR 166. 珠宝的最高价值
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size(), n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = frame[i - 1][j - 1] + max(dp[i][j - 1], dp[i - 1][j]);

        return dp[m][n];
    }

    //931. 下降路径最小和
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 2));
        for (int k = 1; k <= m; k++) dp[k][0] = dp[k][n + 1] = INT_MAX;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
            }
        int minSum = INT_MAX;
        for (int i = 1; i <= n; i++)
            minSum = min(dp[m][i], minSum);
        return minSum;
    }

    //64. 最小路径和
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[1][0] = dp[0][1] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        return dp[m][n];
    }

    //地下城游戏
     int calculateMinimumHP(vector<vector<int>>& dungeon) {
         int m = dungeon.size(), n = dungeon[0].size();

         vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
         dp[m - 1][n] = dp[m][n - 1] = 1;

         for (int i = m - 1; i >= 0; i--)
             for (int j = n - 1; j >= 0; j--)
             {
                 dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                 dp[i][j] = max(1, dp[i][j]);
             }
         return dp[0][0];
    }
};

int main()
{
    Solution sol;
    cout<<sol.tribonacci(37)<<endl;
	return 0;
}