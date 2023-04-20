#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>
//找出所有子集的异或总和再求和
int subsetXORSum(int* nums, int numsSize) {
    int sum = 0;//用来存放每个子集异或的和
    for (int i = 0; i < (1 << numsSize); i++)//(1<<numsSize)代表子集的总个数，因为每个集合的子集个数是2^n，这里把1向左移动numsSize位相当于是2^numsSize
    {
        int x = 0;//用来跟其中一个子集的所有元素进行异或的变量
        for (int j = 0; j < numsSize; j++)
        {
            if (i & (1 << j))//找到这个子集对应的元素
            {

                x ^= nums[j];//依次按位异或

            }
        }
        sum += x;//累加
    }
    return sum;
}


int main()
{
    int arr[] = { 3,4,5,6,7,8 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ans = subsetXORSum(arr, sz);
    printf("%d\n", ans);
    return 0;
}
#endif


#if 0
#include <stdio.h>
//双指针法求相交链表的交点
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
