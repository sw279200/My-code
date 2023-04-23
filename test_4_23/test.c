#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;

        }
        tail = tail->next;
    }

    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    return head;

}
#endif


#if 0

//回文链表
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* last = cur->next;
    head->next = NULL;
    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = last;
        if (last)
        {
            last = last->next;
        }
    }
    return prev;

}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    struct ListNode* low = head;
    struct ListNode* fast = head;
    if ((low->next->next) == NULL)
    {
        if (low->val != low->next->val)
        {
            return false;
        }
        else
            return true;
    }
    while ((fast != NULL) && (fast->next != NULL))
    {
        low = low->next;
        fast = fast->next->next;
    }
    struct ListNode* cur = low;
    struct ListNode* newhead = reverseList(cur);
    while (newhead != low->next)
    {
        if (newhead->val != head->val)
        {
            return false;
        }
        head = head->next;
        newhead = newhead->next;
    }
    return true;

}


#endif

#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//两个链表第一个重合的节点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {

    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    while (pA != pB)
    {
        pA = pA != NULL ? pA->next : headB;
        pB = pB != NULL ? pB->next : headA;
    }
    return pA;


}
#endif

//删除中间节点

#if 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
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