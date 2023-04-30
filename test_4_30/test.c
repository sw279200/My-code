#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//ɾ�������еĽڵ�
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode* next;
};
void deleteNode(struct ListNode* node) {
    struct ListNode* cur = node;
    while (cur->next->next != NULL)
    {
        cur->val = cur->next->val;
        cur = cur->next;
    }
    cur->val = cur->next->val;
    free(cur->next);
    cur->next = NULL;
}
#endif


#if 0
//2181.�ϲ�0֮��Ľڵ�
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* cur = head->next;
    struct ListNode* newhead = NULL;
    struct ListNode* tail = newhead;
    while (cur)
    {
        int sum = 0;
        while (cur && cur->val != 0)
        {
            sum += (cur->val);
            cur = cur->next;
        }
        if (cur && newhead == NULL)
        {

            cur->val = sum;
            tail = newhead = cur;
            cur = cur->next;
            tail->next = NULL;
        }
        else if (cur)
        {

            cur->val = sum;
            tail->next = cur;
            cur = cur->next;
            tail = tail->next;
            tail->next = NULL;

        }


    }
    return newhead;
}



#endif

#if 1
//142.���������
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        //��ΪҪ�ж�fast��slow�Ƿ���ȣ�����λ����Ҫ��ǰ��
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;
}
#endif