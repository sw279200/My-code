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
    //���ֲ���
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

    //�����������в���Ԫ�صĵ�һ�������һ��λ��
    vector<int> searchRange(vector<int>& nums, int target) {
        ////����һ�������ⷨ
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
        //�����������ֲ���
        if (nums.empty() || nums[nums.size() - 1]<target || nums[0] > target) return { -1,-1 };
        //����˵�
        int left = 0, right = nums.size() - 1, start = -1, end = -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)left = mid + 1;
            else right = mid;
        }
        if (nums[left] == target) start = left;
        left = 0, right = nums.size() - 1;
        //���Ҷ˵�
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        if (nums[right] == target) end = right;
        return { start,end };
    }

    //��������λ��
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

    //��x������ƽ����
    int mySqrt(int x) {
        if (x < 1) return 0; //�߽紦��
        int left = 1, right = x;
        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }

    //ɽ������ķ嶥����
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

    //Ѱ�ҷ�ֵ
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

    //Ѱ����ת���������е���Сֵ
    int findMin(vector<int>& nums) {
        ////�����һ��Ԫ��Ϊ�ο�
        //int left = 0, right = nums.size() - 1, n = nums.size() - 1;
        //while (left < right)
        //{
        //    int mid = left + (right - left) / 2;
        //    if (nums[mid] > nums[n]) left = mid + 1;
        //    else right = mid;
        //}
        //return nums[left];

        //�Ե�һ��Ԫ��Ϊ�ο�
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

    //����
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