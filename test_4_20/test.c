#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>
//�ҳ������Ӽ�������ܺ������
int subsetXORSum(int* nums, int numsSize) {
    int sum = 0;//�������ÿ���Ӽ����ĺ�
    for (int i = 0; i < (1 << numsSize); i++)//(1<<numsSize)�����Ӽ����ܸ�������Ϊÿ�����ϵ��Ӽ�������2^n�������1�����ƶ�numsSizeλ�൱����2^numsSize
    {
        int x = 0;//����������һ���Ӽ�������Ԫ�ؽ������ı���
        for (int j = 0; j < numsSize; j++)
        {
            if (i & (1 << j))//�ҵ�����Ӽ���Ӧ��Ԫ��
            {

                x ^= nums[j];//���ΰ�λ���

            }
        }
        sum += x;//�ۼ�
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
//˫ָ�뷨���ཻ����Ľ���
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
