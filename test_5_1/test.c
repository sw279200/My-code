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


//2130. 链表最大孪生和
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {

    //方法二
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        //头插
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;

}
int Max(int x, int y)
{
    return x > y ? x : y;
}
int pairSum(struct ListNode* head) {
    struct ListNode* low = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        low = low->next;
        fast = fast->next->next;

    }
    struct ListNode* cur = reverseList(low);
    int max = -99999999;
    while (cur)
    {
        max = Max(max, (head->val + cur->val));
        head = head->next;
        cur = cur->next;
    }

    return max;

}

#endif


#if 1
#include <stdio.h>
//1669. 合并两个链表
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

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode* p, * q; q = p = list1;
    for (int i = 1; i < a; i++)p = p->next;
    for (int i = 0; i <= b; i++)q = q->next;
    struct ListNode* t = list2;
    while (t->next)t = t->next;
    p->next = list2;
    t->next = q;
    return list1;
    
}
#endif