#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//删除链表中的节点
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
//2181.合并0之间的节点
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
//142.环形链表Ⅱ
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
        //因为要判断fast和slow是否相等，所以位操作要放前面
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