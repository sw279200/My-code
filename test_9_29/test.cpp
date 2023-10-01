#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;
class Solution {
public:
    //二分查找
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, index = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else { index = mid; break; }
        }
        return index;
    }

    //在排序数组中查找元素的第一个和最后一个位置
    vector<int> searchRange(vector<int>& nums, int target) {
        ////方法一：暴力解法
        //if (nums.empty() || nums[nums.size() - 1]<target || nums[0] > target) 
        //    return { -1,-1 };
        //int left = 0, right = nums.size() - 1;
        //while (left <= right)
        //{
        //    if (nums[left] < target)
        //        left++;
        //    if (nums[right] > target)
        //        right--;
        //    if (nums[left] == target && nums[right] == target)
        //        return { left,right };
        //}

        //return { -1,-1 };
        //方法二：二分查找
        if (nums.empty() || nums[nums.size() - 1]<target || nums[0] > target) return { -1,-1 };
        //找左端点
        int left = 0, right = nums.size() - 1, start = -1, end = -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)left = mid + 1;
            else right = mid;
        }
        if (nums[left] == target) start = left;
        left = 0, right = nums.size() - 1;
        //找右端点
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        if (nums[right] == target) end = right;
        return { start,end };
    }

    //搜索插入位置
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (target > nums[right]) return right + 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
        }

        return left;
    }

    //求x的算术平方根
    int mySqrt(int x) {
        if (x < 1) return 0; //边界处理
        int left = 1, right = x;
        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }

    //山脉数组的峰顶索引
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1]) left = mid;
            else right = mid - 1;
        }
        return left;
    }

    //寻找峰值
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else if (nums[mid] > nums[mid + 1])right = mid;
        }
        return left;
    }

    //寻找旋转排序数组中的最小值
    int findMin(vector<int>& nums) {
        ////以最后一个元素为参考
        //int left = 0, right = nums.size() - 1, n = nums.size() - 1;
        //while (left < right)
        //{
        //    int mid = left + (right - left) / 2;
        //    if (nums[mid] > nums[n]) left = mid + 1;
        //    else right = mid;
        //}
        //return nums[left];

        //以第一个元素为参考
        int left = 0, right = nums.size() - 1, n = nums.size() - 1;
        if (nums[left] > nums[right])
        {
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] < nums[0]) right = mid;
                else left = mid + 1;
            }
        }
        return nums[left];
    }

    //点名
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid)  left = mid + 1;
            else right = mid;
        }
        if (records[left] == left)
            return left + 1;
        else return left;
    }
};

int main()
{
	
	return 0;
}