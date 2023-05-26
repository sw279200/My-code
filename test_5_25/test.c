#define _CRT_SECURE_NO_WARNINGS 1

#if 0

//二叉树遍历
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;

} BTNode;

//创建新节点
BTNode* BuyNode(BTDataType x) {
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL) {
        perror("malloc fail");
        return NULL;
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
    char c = a[(*pi)++];
    if (c == '#')
        return NULL;
    BTNode* root = BuyNode(c);
    root->left = BinaryTreeCreate(a, n, pi);
    root->right = BinaryTreeCreate(a, n, pi);
    return root;
}

//中序
void InOrder(BTNode* root) {
    if (root == NULL) {
        return;
    }

    //左根右
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

int main() {
    char str[101];
    while ((scanf("%s", str)) != EOF) {
        int i = 0;
        BTNode* bt = BinaryTreeCreate(str, strlen(str), &i);
        InOrder(bt);
    }
    return 0;
}



#endif

#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//判断两棵二叉树是否相同
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
        if(p==NULL&&q==NULL)
            return true;
        
        if(p==NULL||q==NULL)
            return false;

        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

//单值二叉树
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (root->left)
        if (root->left->val != root->val)
            return false;

    if (root->right)
        if (root->right->val != root->val)
            return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);

}
#endif