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

//�����½ڵ�
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

//���ӽ��
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	char c = a[(*pi)++];
	if (c == '#')
		return NULL;
	BTNode* root = BuyNode(c);
	root->left = BinaryTreeCreate(a, n, pi);
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}

//ǰ��
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//������
	printf("%c", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//����
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//�����
	InOrder(root->left);
	printf("%c", root->data);
	InOrder(root->right);
}


//����
void TailOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}

	//���Ҹ�
	TailOrder(root->left);
	TailOrder(root->right);
	printf("%c", root->data);
}

//���Ľڵ����
int BTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

//Ҷ�ӽڵ����
int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

//�������ĸ߶�
int BTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftTreeSize = BTreeHeight(root->left);
	int rightTreeSize = BTreeHeight(root->right);

	return leftTreeSize > rightTreeSize ? leftTreeSize + 1 : rightTreeSize + 1;
}

// ��������k�������
int BTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeLevelKSize(root->left, k - 1) + BTreeLevelKSize(root->right, k - 1);

}


// ����������ֵΪx�Ľڵ�
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

// �������
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

// �ж϶������Ƿ�����ȫ������
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
	printf("������ǰ��������ַ�������һ�Ŷ�������\n");
	scanf("%s", str);
	int i = 0;
	BTNode* bt = BinaryTreeCreate(str, strlen(str), &i);
	//ǰ��
	printf("ǰ��\n");
	PrevOrder(bt);
	printf("\n");
	printf("����\n");
	InOrder(bt);
	printf("\n");
	printf("����\n");
	TailOrder(bt);
	printf("\n");

	int btSize = BTreeSize(bt);
	printf("���������ĸ���Ϊ��  %d\n", btSize);
	printf("������Ҷ�ӽ��ĸ���Ϊ��  %d\n", BTreeLeafSize(bt));
	printf("�������ĸ߶�Ϊ��  %d\n", BTreeHeight(bt));
	int  k = 3;
	printf("��������%d�������Ϊ��%d\n", k, BTreeLevelKSize(bt, k));

	// ����������ֵΪx�Ľڵ�
	char x = 'D';
	BTNode* fx = BinaryTreeFind(bt, x);
	if (fx != NULL)
		printf("�ҵ��ˣ�ֵΪ%c\n", fx->data);
	else
		printf("û���ҵ���\n");
	// �������
	printf("���������������\n");
	BinaryTreeLevelOrder(bt);

	if (BinaryTreeComplete(bt))
		printf("�ö���������ȫ������\n");
	else
		printf("�ö�����������ȫ������\n");
	return 0;
}



