#define _CRT_SECURE_NO_WARNINGS 1

#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//���ص�����k���ڵ�
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
//���������е�����K���ڵ�
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
