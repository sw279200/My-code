#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    //长度最小的子数组

    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT_MAX;   //记录结果
        int left = 0, right = 0;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];      //进窗口
            while (sum >= target)
            {
                min = min > right - left + 1 ? right - left + 1 : min;//更新窗口

                sum -= nums[left];//出窗口
                left++;
            }
            right++;
        }
        return min == INT_MAX ? 0 : min;
    }

    //无重复字符的最长子串
    int lengthOfLongestSubstring(string s) {
        /*int Maxlen = 0;
        int n = s.size();
        if (n < 2)
        {
            return n;
        }
        int left = 0, right = 1;
        for (; right < n; right++)
        {
            int i = left;
            while (i < right)
            {
                if (s[i] == s[right])
                {
                    Maxlen = max(Maxlen, right - left);
                    left = i + 1;
                    break;
                }
                i++;
            }
        }
        Maxlen = max(Maxlen, right - left);
        return Maxlen;*/

        int hash[128] = { 0 };
        int left = 0,right = 0,ret = 0,n = s.size();
        while (right < n)
        {
            hash[s[left]]++; //将字符放入哈希表
            while (hash[s[right]] > 1) hash[s[left]]--; //删除重复的哈希表元素

            ret = max(ret, right - left + 1);  //更新结果
            right++;   //让下一个字符进入滑动窗口
        }

        return ret;

        //int ret = 0; // 记录结果
        //int n = s.length();
        //// 1. 枚举从不同位置开始的最⻓重复⼦串
        //// 枚举起始位置
        //for (int i = 0; i < n; i++)
        //{
        //    // 创建⼀个哈希表，统计频次
        //    int hash[128] = { 0 };
        //    // 寻找结束为⽌
        //    for (int j = i; j < n; j++)
        //    {
        //        hash[s[j]]++; // 统计字符出现的频次
        //        if (hash[s[j]] > 1) // 如果出现重复的
        //            break;
        //        // 如果没有重复，就更新 ret
        //        ret = max(ret, j - i + 1);
        //    }
        //}
        //// 2. 返回结果    
        //return ret;
    }
    //最大连续1的个数
    int longestOnes(vector<int>& nums, int k) {
        //int n = nums.size();
        //int MaxSize = 0;
        //int count[2] = { 0 };   //统计滑动窗口0和1的个数
        //int left = 0, right = 0;
        //
        //for (; right < n; )
        //{
        //                     
        //    while (right<n&&count[0] <= k)   count[nums[right++]]++;   //进滑动窗口
        //    //当滑动窗口中0的个数大于k时
        //    while(left<right&&count[0] > k)
        //    {
        //        count[nums[left++]]--;
        //        MaxSize = max(MaxSize, right - left);
        //        
        //    }
        //}
        //MaxSize = max(MaxSize, right - left);
        //return MaxSize;
        int ret = 0;
        for (int left = 0, right = 0, zero = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0) zero++; // 进窗⼝
            while (zero > k) // 判断
                if (nums[left++] == 0) zero--; // 出窗⼝
            ret = max(ret, right - left + 1); // 更新结果
        }
        return ret;
    }

    //将x减到0的最小操作数
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), SUM = 0, MaxLen = 0;
        for (int i = 0; i < n; i++)
            SUM += nums[i];
        if (x == SUM)
            return n;
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += nums[right];
            while (left<right && sum > SUM - x)sum -= nums[left++];
            if (sum == SUM - x) MaxLen = max(MaxLen, right - left + 1);

        }
        return (n - MaxLen) == n ? -1 : n - MaxLen;
    }

    //水果成篮
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), ret = n, MaxLen = 0;
        vector<int>hash(n, 0);
        for (int count = 0, left = 0, right = 0; right < n; right++)
        {
            hash[fruits[right]]++;
            if (hash[fruits[right]] == 1)  count++;//统计目前篮子里的水果种类              
            while (left < right && count>2)
            {
                ret = -1;
                hash[fruits[left++]]--;
                if (hash[fruits[left - 1]] == 0)  count--;
            }
            MaxLen = max(MaxLen, right - left + 1);

        }
        return ret == -1 ? MaxLen : ret;

    }

    bool IsEqual(vector<int>& v1, vector<int>& v2)
    {
        bool flag = true;
        for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
        {
            flag = false;
            break;
        }
        return flag;
    }

    //找到字符串中所有字母的异位词
    vector<int> findAnagrams(string s, string p) {
        ////自己想的方法
        //int n = s.size(), len = p.size();
        //vector<int> v, vs(26, 0), vp(26, 0);
        //for (auto e : p) vp[e - 'a']++;
        //for (int left = 0, right = 0; right < n; right++)
        //{
        //    vs[s[right] - 'a']++;
        //    if (len == (right - left + 1))
        //    {
        //        if (IsEqual(vp, vs)) v.push_back(left);
        //        vs[s[left] - 'a']--;
        //        left++;
        //    }

        //}
        //return v;

        //老师的方法
        vector<int> ret;
        int hash1[26] = { 0 }; // 统计字符串 p 中每个字符出现的个数
        for (auto ch : p) hash1[ch - 'a']++;
        int hash2[26] = { 0 }; // 统计窗⼝⾥⾯的每⼀个字符出现的个数
        int m = p.size();
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            // 进窗⼝ + 维护 count
            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;
            if (right - left + 1 > m) // 判断
            {
                char out = s[left++];
                // 出窗⼝ + 维护 count
                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;
            }
            // 更新结果
            if (count == m) ret.push_back(left);
        }
        return ret;
    }
};

int main()
{
    vector<int> v = { 3,2,20,1,1,3 };
    Solution sol;
    //cout << sol.minOperations(v, 10) << endl;
   // cout << sol.longestOnes(v, 3) << endl;
    
	return 0;
}