#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//BiNode
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};

struct TreeNode* min;
void Creat(struct TreeNode** root)
{
    if (*root)
    {
        Creat(&(*root)->right);
        (*root)->right = min;
        min = *root;
        Creat(&(*root)->left);
        (*root)->left = NULL;//д���������Ȼ��һ���ݹ������
    }
}
struct TreeNode* convertBiNode(struct TreeNode* root) {
    min = NULL;//���һ���ڵ����һ��Ϊ��,ͬʱ�����˳�ʼ��������ȫ�ֱ��������⡣
    Creat(&root);
    return min;
}



