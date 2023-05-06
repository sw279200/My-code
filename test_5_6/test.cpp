#define _CRT_SECURE_NO_WARNINGS 1

#if 1
//Á´±í·Ö¸î
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        auto* Big = (ListNode*)malloc(sizeof(ListNode));
        auto* Small = (ListNode*)malloc(sizeof(ListNode));
        Big->next = Small->next = nullptr;
        ListNode* cur = pHead;
        ListNode* curS = Small;
        ListNode* curB = Big;
        while (cur)
        {
            if (cur->val >= x)
            {
                curB->next = cur;
                cur = cur->next;
                curB = curB->next;
                curB->next = nullptr;
            }
            else
            {
                curS->next = cur;
                cur = cur->next;
                curS = curS->next;
                curS->next = nullptr;
            }

        }

        curS->next = Big->next;
        return Small->next;
    }
};
#endif



