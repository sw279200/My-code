#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
  //给定两个用链表表示的整数，每个节点包含一个数位。

  //    这些数位是反向存放的，也就是个位排在链表首部。

  //    编写函数对这两个整数求和，并用链表形式返回结果。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            }
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }

    int maxDepth(string s) {
        int ans = 0, size = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++size;
                ans = max(ans, size);
            }
            else if (ch == ')') {
                --size;
            }
        }
        return ans;
    }
};