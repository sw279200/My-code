#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//¸´ÔÓÁ´±íµÄ¸´ÖÆ
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        while (cur != NULL)
        {
            Node* copy = (Node*)malloc(sizeof(Node));
            copy->val = cur->val;
            Node* next = cur->next;
            cur->next = copy;
            copy->next = next;
            cur = next;
        }


        cur = head;
        while (cur != NULL)
        {
            Node* copy = cur->next;

            if (cur->random == NULL)
            {
                copy->random = NULL;
            }
            else
            {
                copy->random = cur->random->next;
            }
            cur = copy->next;
        }

        Node* copyHead = NULL, * copyTail = NULL;
        cur = head;
        while (cur != NULL)
        {
            Node* copy = cur->next;
            Node* next = NULL;
            if (copy)
                next = copy->next;
            if (copyTail == NULL)
            {
                copyHead = copyTail = copy;
            }
            else
            {
                copyTail->next = copy;
                copyTail = copyTail->next;
            }
            cur->next = next;
            cur = next;

        }
        return copyHead;
    }
};