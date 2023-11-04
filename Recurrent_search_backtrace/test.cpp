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
 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    //��ת����
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr||head->next == nullptr) return head;
        ListNode* newhead = reverseList(head->next);
        head = head->next->next;
        head->next = nullptr;
        return newhead;
    }

    // �������������еĽڵ�
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* tmp = swapPairs(head->next->next);
        ListNode* newhead = head->next;
        newhead->next = head;
        head->next = tmp;
        return newhead;
    }

    //������
    double myPow(double x, int n) {
        return n < 0 ? 1.00 / Pow(x, -(long long)n) : Pow(x, n);
    }
    double Pow(double x, int n)
    {
        if (n == 0) return 1.0;
        double tmp = Pow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }

    //���㲼����������ֵ
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) return root->val == 1;
        return root->val == 2 ? evaluateTree(root->left) || evaluateTree(root->right) 
            : evaluateTree(root->left) && evaluateTree(root->right);
    }
};

int main()
{

    return 0;
}