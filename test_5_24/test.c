#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef char BTDataType;
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
		return NULL;
	}

	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//链接结点
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	char c = a[(*pi)++];
	if (c == '#')
		return NULL;
	BTNode* root = BuyNode(c);
	root->left = BinaryTreeCreate(a, n, pi);
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}

//前序
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//根左右
	printf("%c", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//中序
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//左根右
	InOrder(root->left);
	printf("%c", root->data);
	InOrder(root->right);
}


//后序
void TailOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//左右根
	TailOrder(root->left);
	TailOrder(root->right);
	printf("%c", root->data);
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
	assert(k > 0);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeLevelKSize(root->left, k - 1) + BTreeLevelKSize(root->right, k - 1);

}


// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* leftTree = BinaryTreeFind(root->left, x);

	if (leftTree)
		return leftTree;

	BTNode* rightTree = BinaryTreeFind(root->right, x);

	if (rightTree)
		return rightTree;

	return NULL;

}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}

	printf("\n");
	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
			break;
		else
		{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (cur!=NULL)
			return false;
		QueuePop(&q);
	}
	return true;
}

int main()
{
	char str[101];
	printf("请输入前序遍历的字符串构建一颗二叉树：\n");
	scanf("%s", str);
	int i = 0;
	BTNode* bt = BinaryTreeCreate(str, strlen(str), &i);
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

	// 二叉树查找值为x的节点
	char x = 'D';
	BTNode* fx = BinaryTreeFind(bt, x);
	if (fx != NULL)
		printf("找到了，值为%c\n", fx->data);
	else
		printf("没有找到！\n");
	// 层序遍历
	printf("二叉树层序遍历：\n");
	BinaryTreeLevelOrder(bt);

	if (BinaryTreeComplete(bt))
		printf("该二叉树是完全二叉树\n");
	else
		printf("该二叉树不是完全二叉树\n");
	return 0;
}



