#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    //子数组序列

    //最大子数组和
    int maxSubArray(vector<int>& nums) {
        //方法一：
       /* int i = 0,sum = 0,Max = -0x3f3f3f3f;
        while (i < nums.size())
        {
            if (sum + nums[i] < nums[i])sum = nums[i++];
            
            else sum += nums[i++];
       
              Max = max(Max, sum);
        }
        return Max;*/

        //方法二：
        int n = nums.size();

        //创建dp表
        vector<int> dp(n + 1);
        int MaxNum = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            MaxNum = max(MaxNum, dp[i]);
        }
        return MaxNum;
    }

    //环形子数组的最大和
    int maxSubarraySumCircular(vector<int>& nums) {
        int  n = nums.size();
        //创建dp表
        vector<int> f(n + 1), g(n + 1);
        int sum = 0;
        int MaxSum = -0x3f3f3f3f, MinSum = 0x3f3f3f3f;
        for (auto e : nums) sum += e;
        for (int i = 1; i <= n; i++)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
            MaxSum = max(f[i], MaxSum);
            MinSum = min(g[i], MinSum);
        }
        return sum == MinSum ? MaxSum : max(MaxSum, sum - MinSum);
    }

    //乘积最大子数组
    int maxProduct(vector<int>& nums) {
        /*int n = nums.size();
        vector<int> f(n + 1), g(n + 1);
        f[0] = g[0] = 1;
        int MaxPro = -0x3f3f3f3f, MinPro = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            if (nums[i - 1] < 0)
            {
                f[i] = max(g[i - 1] * nums[i - 1], nums[i - 1]);
                g[i] = min(f[i - 1] * nums[i - 1], nums[i - 1]);
            }
            else if (nums[i - 1] > 0)
            {
                f[i] = max(f[i - 1] * nums[i - 1], nums[i - 1]);
                g[i] = min(g[i - 1] * nums[i - 1], nums[i - 1]);
            }
            else
            {
                f[i] = 0;
                g[i] = 0;
            }
            MaxPro = max(MaxPro, f[i]);
        }

        return MaxPro;*/
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1);
        f[0] = g[0] = 1;
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1], y = nums[i - 1] * f[i - 1], z = nums[i - 1] * g[i - 1];
            f[i] = max(x, max(y, z));
            g[i] = min(x, min(y, z));
            ret = max(f[i], ret);
        }
        return ret;

    }

    //1567. 乘积为正数的最长子数组长度
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1);
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (nums[i - 1] > 0)
            {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
            }
            else if (nums[i - 1] < 0)
            {
                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
                g[i] = f[i - 1] + 1;
            }
            else f[i] = g[i] = 0;
            ret = max(ret, f[i]);
        }
        return ret;
    }

    //等差数列划分
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int sum = 0;
        for (int i = 2; i < n; i++)
        {
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }
        return sum;
    }

    //978. 最长湍流子数组
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,1),g(n,1);
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1]) f[i] = g[i - 1] + 1;
            
            if (nums[i] < nums[i - 1]) g[i] = f[i - 1] + 1;

            ret = max(ret, max(f[i], g[i]));
        }
        return ret;
       
    }

    //139. 单词拆分
    bool wordBreak(string s, vector<string>& wordDict) {

    }

};

int main()
{

    return 0;
}