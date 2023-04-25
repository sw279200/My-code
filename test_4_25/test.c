#define _CRT_SECURE_NO_WARNINGS 1


#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//二进制链表转整数
 struct ListNode {
    int val;
    struct ListNode* next;
    
};

int getDecimalValue(struct ListNode* head) {
    int sum = 0;
    int arr[30] = { 0 };
    int count = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        arr[count++] = cur->val;
        cur = cur->next;
    }

    for (int i = 0; i < count; i++)
    {
        sum += arr[i] * pow(2, count - i - 1);
    }
    return sum;



}
#endif


#if 0

//移除重复节点
#include  <stdio.h>
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

struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode* cur = head;
    struct ListNode* tail = head;
    struct ListNode* newcur = head;
    struct ListNode* last = cur->next;
    cur = last;
    if (last)
        last = last->next;
    head->next = NULL;
    while (cur)
    {

        newcur = head;
        int flag = 0;
        while (newcur)
        {
            if (cur->val == newcur->val)
            {
                flag = 1;
                break;
            }
            newcur = newcur->next;
        }

        if (flag == 0)
        {
            tail->next = cur;
            tail = tail->next;
        }
        cur->next = NULL;
        cur = last;
        if (last)
            last = last->next;
    }
    return head;
}
#endif

#if 0
//Excel表列名称
#include<stdio.h>
#include<stdlib.h>
char* convertToTitle(int columnNumber) {
    int i = 0;
    int arr[9] = { 0 };

    while (columnNumber > 0)
    {
        arr[i++] = (columnNumber - 1) % 26;

        if (columnNumber <= 26)
            break;
        columnNumber = (columnNumber - 1) / 26;


    }
    i--;
    char* ps = (char*)malloc(10 * sizeof(char));

    for (int j = i; j >= 0; j--)
    {
        ps[i - j] = 'A' + arr[j];
    }
    ps[i + 1] = '\0';
    return ps;

}
int main()
{
    char* pa = convertToTitle(701);
    printf("%s\n", pa);
    return 0;
}
#endif


#if 1
#include <stdio.h>

int titleToNumber(char* columnTitle) {
    int num = 0;
    int len = strlen(columnTitle);
    while (*columnTitle)
    {
        num += (*(columnTitle)-'@') * pow(26, len - 1);
        columnTitle++;
        len--;
    }
    return num;
}
int main()
{
    char ps[] = "Z";
    printf("%d\n", titleToNumber(ps));
    return 0;
}
#endif