#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    //922. 按奇偶排序数组II
    void mysort(vector<int>& nums,int x)
    {
        int n = nums.size();
        for (int i = x; i < n; i += 2)
        {
            for (int j = i; j < n-2; j += 2)
            {
                swap(nums[j], nums[j + 2]);
            }
        }
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for (int odd = 1, even = 0; odd< n && even <n ;)
        {
            while (odd<n&&nums[odd] % 2 != 0)
            {
                odd += 2;
            }
            while (even < n&&nums[even]%2!=1)
            {
                even += 2;
            }
            if(odd<n&&even<n)
            swap(nums[odd], nums[even]);
        }
        return nums;
      

    }

    //连续子数组的最大和
    int FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int sum = INT_MIN,maxsum = INT_MIN;
        for (auto x : array)
        {
            if (x + sum < x)
            {
                sum = x;
            }
            else
            {
                sum += x;
            }

            if (sum > maxsum)maxsum = sum;
        }
        return maxsum;
    }
};

int main()
{

	return 0;
}