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
    //��ŵ������
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

        move(n - 1, A, C, B);    // ��A����n-1��ͨ��C�Ƶ�B
        C.push_back(A.back());  // ��A���һ���Ƶ�C
        A.pop_back();          // ��ʱ��A����
        move(n - 1, B, A, C);     // ��B����n-1��ͨ���յ�A�Ƶ�C

    }

    //�ϲ�������������
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