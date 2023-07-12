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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @param m int����
     * @param n int����
     * @return ListNode��
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
    //����һ�������ͷ�ڵ� head�������д���룬����ɾȥ�������� �ܺ� ֵΪ 0 �������ڵ���ɵ����У�ֱ������������������Ϊֹ��
    struct ListNode* removeZeroSumSublists(struct ListNode* head) {
        struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));//ͷ�ڵ���ܻᱻ������Ҫ����һ������ͷ�ڵ�
        dummy->next = head;
        struct ListNode* p = dummy;
        struct ListNode* q = p->next;
        int x = 0;
        while (p)//��ʵ�����������˿���ָ���˼��
        {
            x = 0;//���ﻹ��Ҫ���µ�
            q = p->next;
            while (q)
            {
                x -= q->val;//�ü�����һ������������(ʡȥ�ܶ��鷳)
                if (x == 0)
                {
                    p->next = q->next;//ɾ���ڵ�
                }
                q = q->next;
            }
            p = p->next;
        }
        return dummy->next;

    }
};