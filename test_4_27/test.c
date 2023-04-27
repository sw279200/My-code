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
        (*root)->left = NULL;//写外边来，不然上一步递归出问题
    }
}
struct TreeNode* convertBiNode(struct TreeNode* root) {
    min = NULL;//最后一个节点的下一个为空,同时进行了初始化，避免全局变量出问题。
    Creat(&root);
    return min;
}



