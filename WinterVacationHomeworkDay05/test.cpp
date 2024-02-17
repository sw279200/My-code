#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //LCR006.两数之和II
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        for (; left < right;)
        {
            if (numbers[left] + numbers[right] > target) right--;
            else if (numbers[left] + numbers[right] < target)left++;
            else return { left,right };
        }

        return { -1,-1 };
    }
    //数组中出现次数超过一半的数字
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        vector<int> v(10001, 0);
        for (size_t i = 0; i < numbers.size(); i++)
        {
            v[numbers[i]]++;
        }
        int  x = 0;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] > (numbers.size() / 2))
            {
                x = i;
            }
        }

        return x;
    }
};

int main()
{

	return 0;
}