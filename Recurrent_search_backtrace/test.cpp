#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    //汉诺塔问题
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) { 
        int n = A.size();
        move(n, A, B, C);
    } 

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n - 1, A, C, B);    // 将A上面n-1个通过C移到B
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了
        move(n - 1, B, A, C);     // 将B上面n-1个通过空的A移到C

    }

    //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* head = nullptr;
        if (list1->val < list2->val)
        {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);

        }
        else
        {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }

        return head;
    }
};

int main()
{

    return 0;
}