#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    //专题五. 位运算

    //判断字符是否唯一
    bool isUnique(string astr) {
        int n = astr.size(), x = 0;
        if (n > 26) return false;
        for (int i = 0; i < n; i++)
        {
            if (((x >> (astr[i] - 'a')) & 1) == 0) x |= (1 << (astr[i] - 'a'));
            else return false;
        }
        return true;
    }


    //丢失的数字
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),x = 0;
        for (int i = 0; i <= n; i++)
            x ^= i;

        for (int i = 0; i < n; i++)
            x ^= nums[i];
        return x;
    }

    //两数相加
    int getSum(int a, int b) {
        
        while (b != 0)
        {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry ;
        }

        return a;
    }

    //只出现一次的数字II
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int k = 0; k < 32; k++)
        {
            int sum = 0;
            for (int x : nums)
                if (((x >> k) & 1) == 1) sum++;
            sum %= 3;
            if (sum == 1) ret |= (1 << k);
        }
        return ret;
    }

    //消失的两个数字
    vector<int> missingTwo(vector<int>& nums) {
        int res1 = 0, res0 = 0, k = 0, n = nums.size();
        // 1. 将所有的数异或在⼀起
        for (int m : nums) k ^= m;
        for (int i = 1; i <= n + 2; i++) k ^= i;
        for (int j = 0; j < 32; j++)
            if (((k >> j) & 1) == 1) // 2.找出res0,res1中⽐特位不同的那⼀位
            {
                // 3. 根据 j 位的不同，将所有的数划分为两类来异或
                for (int m : nums)
                    if (((m >> j) & 1) == 0) res0 ^= m;
                    else res1 ^= m;
                for (int i = 1; i <= n + 2; i++)
                    if (((i >> j) & 1) == 0) res0 ^= i;
                    else res1 ^= i;
                break;
            }
        return { res0,res1 };
    }

    //专题六. 模拟
    
    //替换所有问号
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if ((i == 0 || s[i - 1] != ch) && (i == s.size() - 1 || s[i + 1] != ch))
                    {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }

    //提莫攻击
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size(), sum = duration, t = timeSeries[0] + duration;
        for (int i = 1; i < n; i++)
        {
            //只加刷新中毒后比之前的预定消失中毒时刻多出来的中毒时间
            if (timeSeries[i] >= timeSeries[i - 1] && timeSeries[i] <= t)
                sum += timeSeries[i] + duration - t;
            else
                sum += duration;  //如果不在这个时间范围直接加所造成的中毒时间

            t = timeSeries[i] + duration;
        }

        return sum;
    }

    //N字型变换
    string convert(string s, int numRows) {
        //方法一：暴力枚举
       /* vector<vector<char>> vvc(numRows,vector<char>(s.size(),' '));
        int count = 0,i = 0, j = 0;
        while (count < s.size())
        {
            if (j == 0)
                while (count < s.size()&&j < numRows-1)
                    vvc[j++][i] = s[count++];
            if(j==numRows-1)
                while(count < s.size()&&j>0)
                    vvc[j--][i++] = s[count++];
        }
        string str("");
        for (int k = 0; k < vvc.size(); k++)
            for (int m = 0; m < vvc[k].size(); m++)
                if (vvc[k][m] != ' ')
                    str += vvc[k][m];

        return str;*/

        //方法二：利用公差
        // 处理边界情况
        if (numRows == 1) return s;
        string ret;
        int d = 2 * numRows - 2, n = s.size();
        // 1. 先处理第⼀⾏
        for (int i = 0; i < n; i += d)
            ret += s[i];
        // 2. 处理中间⾏
        for (int k = 1; k < numRows - 1; k++) // 枚举每⼀⾏
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }
        // 3. 处理最后⼀⾏
        for (int i = numRows - 1; i < n; i += d)
            ret += s[i];
        return ret;
    }


    //外观数列
    string countAndSay(int n) {
        ////递归思想
        //if (n == 1)return "1";
        //string s = countAndSay(n - 1);
        //string res("");
        //int left = 0, right = 0;
        //for (; right < s.size(); right++)
        //{
        //    if (s[left] != s[right])
        //    {
        //        res += right - left + '0';
        //        res += s[left];
        //        left = right;
        //    }
        //}
        //res += right - left + '0'; 
        //res += s[left];
        //left = right;
        //return res;

        //方法二：循环
        string ret = "1";
        for (int i = 1; i < n; i++) // 解释 n - 1 次 ret 即可
        {
            string tmp;
            int len = ret.size();
            for (int left = 0, right = 0; right < len; )
            {
                while (right < len && ret[left] == ret[right]) right++;
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }

    //数青蛙
    int minNumberOfFrogs(string croakOfFrogs) {
        string s = "croak";
        int n = s.size();
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; i++)
            index[s[i]] = i;

        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0) return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }

        for (int j = 0; j < n - 1; j++)
            if (hash[j] != 0) return -1;
        return hash[n - 1];
    }
};

int main()
{
    Solution sol;
    string s("PAYPALISHIRING");
    cout<<sol.convert(s,4)<<endl;
	return 0;
}