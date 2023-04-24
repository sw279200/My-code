#define _CRT_SECURE_NO_WARNINGS 1

#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//返回倒数第k个节点
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
int kthToLast(struct ListNode* head, int k) {

    struct ListNode* fast = head;
    struct ListNode* low = head;

    while (k--)
    {
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        low = low->next;
    }

    return low->val;
}

#endif


#if 1
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
//返回链表中倒数第K个节点
struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    struct ListNode* fast = head;
    struct ListNode* low = head;

    while (k--)
    {
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        low = low->next;
    }

    return low;
}
#endif
