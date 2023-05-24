#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

//创建新节点
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//链接结点
BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;
	return node1;
}

//前序
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//根左右
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//中序
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//左根右
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}


//后序
void TailOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//左右根
	TailOrder(root->left);
	TailOrder(root->right);
	printf("%d ", root->data);
}

//树的节点个数
int BTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

//叶子节点个数
int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

//二叉树的高度
int BTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	int leftTreeSize = BTreeHeight(root->left);
	int rightTreeSize = BTreeHeight(root->right);

	return leftTreeSize > rightTreeSize ? leftTreeSize + 1 : rightTreeSize + 1;
}

// 二叉树第k层结点个数
int BTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeLevelKSize(root->left, k - 1) + BTreeLevelKSize(root->right, k - 1);

}


int main()
{

	BTNode* bt = CreateBinaryTree();
	//前序
	printf("前序：\n");
	PrevOrder(bt);
	printf("\n");
	printf("中序：\n");
	InOrder(bt);
	printf("\n");
	printf("后序：\n");
	TailOrder(bt);
	printf("\n");

	int btSize = BTreeSize(bt);
	printf("二叉树结点的个数为：  %d\n", btSize);
	printf("二叉树叶子结点的个数为：  %d\n", BTreeLeafSize(bt));
	printf("二叉树的高度为：  %d\n", BTreeHeight(bt));
	int  k = 3;
	printf("二叉树第%d层结点个数为：%d\n", k, BTreeLevelKSize(bt, k));

	return 0;
}
