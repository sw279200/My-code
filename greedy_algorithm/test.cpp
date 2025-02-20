#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
    //柠檬水找零
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0, five = 0;
        for (auto x : bills)
        {
            if (x == 5)five++;
            else if (x == 10)
            {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else if (x == 20)
            {
                if (ten >= 1 && five >= 1)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
    //将数组和减半的最少操作次数
    int halveArray(vector<int>& nums) {
        priority_queue<double>heap;
        double sum = 0.0;
        for (auto x : nums)
        {
            sum += x;
            heap.push(x);
        }
        sum /= 2.0;
        int count = 0;
        while (sum > 0)
        {
            double t = heap.top();
            heap.pop();
            t /= 2.0;
            sum -= t;
            count++;
            heap.push(t);
        }
        return count;
    }

    //最大数
    string largestNumber(vector<int>& nums) {
        vector<string>vs;
        for (auto ts : nums) vs.push_back(to_string(ts));
        sort(vs.begin(), vs.end(), [](const string& s1, const string& s2)
            {
                return s1 + s2 > s2 + s1;
            });
        string str("");
        for (auto& x : vs) str += x;
        if (str[0] == '0') return "0";
        else return str;
    }

    //摆动序列
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int ret = 0, left = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int right = nums[i + 1] - nums[i];
            if (right == 0) continue;
            if (left * right <= 0) ret++;
            left = right;
        }
        return ret + 1;


    }
    //最长递增子序列
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        ret.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ret.back()) ret.push_back(nums[i]);
            else
            {
                int left = 0, right = ret.size() - 1;
                while (left < right)
                {
                    int mid = (left + right) >> 1;
                    if (ret[mid] < nums[i]) left = mid + 1;
                    else right = mid;
                }
                ret[left] = nums[i];
            }

        }
        return ret.size();
    }

    //递增的三元子序列
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        ret.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ret.back()) ret.push_back(nums[i]);
            else
            {
                int left = 0, right = ret.size() - 1;
                while (left < right)
                {
                    int mid = (left + right) >> 1;
                    if (ret[mid] < nums[i]) left = mid + 1;
                    else right = mid;
                }
                ret[left] = nums[i];
            }
            if (ret.size() == 3) return true;

        }
        return false;
    }
    
    //最长连续递增子序列
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(),count = 1,ret = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i]) count++;
            else
            {
                ret = max(count, ret);
                count = 1;
            }
        }
        ret = max(count, ret);
        return ret;
    }

};

int main()
{
    Solution sol;
    vector<int> v;
    v.push_back(5);
    v.push_back(5);
    v.push_back(10);
    v.push_back(10);
    v.push_back(20);
    cout << sol.lemonadeChange(v) << endl;

    return 0;
}