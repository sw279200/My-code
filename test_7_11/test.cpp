#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>
using namespace std;

//�������� nums ���������У������е�ֵ ������ͬ ��
//
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ �����������磬[0, 1, 2, 4, 5, 6, 7] ���±� 3 ������ת����ܱ�Ϊ?[4, 5, 6, 7, 0, 1, 2] ��
//
//    ���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻�? - 1?��
//
//    ��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    /*Definition for singly - linked list.
        * struct ListNode {
        *int val;
        *ListNode* next;
        *ListNode() : val(0), next(nullptr) {}
        *ListNode(int x) : val(x), next(nullptr) {}
        *ListNode(int x, ListNode* next) : val(x), next(next) {}
        *
    };
    */
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        int arr[30] = { 0 };
        int count = 0;
        struct ListNode* cur = head;
        while (cur)
        {
            arr[count++] = cur->val;
            cur = cur->next;
        }

        for (int i = 0; i < count; i++)
        {
            sum += arr[i] * pow(2, count - i - 1);
        }
        return sum;

    }
};

int main()
{
    vector<int>nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution sol;
    cout<<sol.search(nums, target)<<endl;
    
    ListNode* head = new ListNode(1);
    ListNode* L1 = new ListNode(0);
    ListNode* L2 = new ListNode(1);

    head->next = L1;
    L1->next = L2;
    L2->next = nullptr;

    cout<<sol.getDecimalValue(head)<<endl;
    return 0;
}