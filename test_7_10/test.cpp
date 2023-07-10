#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <vector>
using namespace std;
//给你一个数组 nums 。数组「动态和」的计算公式为：
//runningSum[i] = sum(nums[0]…nums[i]) 。
//请返回 nums 的动态和。

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int x = 0;
            for (int j = 0; j <= i; j++)
            {
                x += nums[j];
            }
            nums[i] = x;
        }

        return nums;
    }
};
int main()
{
    vector<int> arr;
    arr.resize(10);
    for (int i = 1; i <= 4; i++)
    {
        arr.push_back(i);
    }
    Solution sol;
    sol.runningSum(arr);
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
	return 0;
}
#endif
#include <vector>
#include <iostream>
using namespace std;

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;
        if (target < nums[0])
        {
            ans = 0;
            return ans;
        }
        if (target > nums[nums.size() - 1])
        {
            ans = nums.size();
            return ans;
        }
        for (int i = 0; i < nums.size(); i++) {

            if (target == nums[i]) {
                ans = i;
                break;
            }

            if (target > nums[i] && target < nums[i + 1]) {
                ans = i + 1;
                break;
            }


        }
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 3, 5, 6};
    int target = 5;
    Solution sol;
    cout << sol.searchInsert(nums, target) << endl;
    return 0;
}