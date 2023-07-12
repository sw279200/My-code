#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;


  struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */


    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if (head->next == nullptr)
            return head;

        ListNode* cur = head;
        int count = 1;
        vector<int> v;
        while (cur != nullptr)
        {
            if (count >= m && count <= n)
                v.push_back(cur->val);

            cur = cur->next;
            count++;
        }

        reverse(v.begin(), v.end());
        count = 1;
        cur = head;
        vector<int>::iterator it = v.begin();
        while (it != v.end()&&cur != nullptr)
        {
            if (it!=v.end() && count >= m && count <= n)
            {
                cur->val = *it;
                it++;
            }

            cur = cur->next;
            count++;
        }
        
        return head;
    }
    //给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
    struct ListNode* removeZeroSumSublists(struct ListNode* head) {
        struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));//头节点可能会被消除，要建立一个虚拟头节点
        dummy->next = head;
        struct ListNode* p = dummy;
        struct ListNode* q = p->next;
        int x = 0;
        while (p)//其实本质上是用了快慢指针的思想
        {
            x = 0;//这里还是要更新的
            q = p->next;
            while (q)
            {
                x -= q->val;//用减号是一个真正的亮点(省去很多麻烦)
                if (x == 0)
                {
                    p->next = q->next;//删除节点
                }
                q = q->next;
            }
            p = p->next;
        }
        return dummy->next;

    }
};