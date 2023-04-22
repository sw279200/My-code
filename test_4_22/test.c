#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	char Date[20] = {0};
	
	scanf("%s",Date);
	int len = strlen(Date);
	int i = 0;
	while (Date[i] != '.')
	{
		printf("%c", Date[i]);
		i++;
	}
	i++;
	printf("年");
	while (Date[i] != '.')
	{
		printf("%c", Date[i]);
		i++;
		
	}
	printf("月");
	i++;
	while (Date[i])
	{
		printf("%c", Date[i]);
		i++;
		
	}
	printf("日\n");
	return 0;
}
#endif

#if 0
//删除链表节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;
	if (head->val == val)
	{
		struct ListNode* next = head->next;
		head = next;
	}
	else
	{

		struct ListNode* prev = NULL;
		struct ListNode* cur = head;
		struct ListNode* last = cur->next;
		while (cur->val != val)
		{
			prev = cur;
			cur = last;
			if (last)
				last = last->next;
		}
		prev->next = last;
	}
	return head;

}
#endif

#if 0

#include <stdio.h>
//链表相交

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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


#if 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* reversePrint(struct ListNode* head, int* returnSize) {
	if (head == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int i = 0;
	struct ListNode* cur = head;
	int* arr = (int*)malloc(10000 * sizeof(int));
	while (cur != NULL)
	{

		arr[i++] = cur->val;
		cur = cur->next;

	}
	int left = 0, right = i - 1;
	for (; left < right; left++, right--)
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	*returnSize = i;
	return arr;
}
#endif