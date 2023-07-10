#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <vector>
using namespace std;
//����һ������ nums �����顸��̬�͡��ļ��㹫ʽΪ��
//runningSum[i] = sum(nums[0]��nums[i]) ��
//�뷵�� nums �Ķ�̬�͡�

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

//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

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