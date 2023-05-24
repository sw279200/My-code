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

//�����½ڵ�
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

//���ӽ��
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

//ǰ��
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//������
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//����
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//�����
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}


//����
void TailOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//���Ҹ�
	TailOrder(root->left);
	TailOrder(root->right);
	printf("%d ", root->data);
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
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeLevelKSize(root->left, k - 1) + BTreeLevelKSize(root->right, k - 1);

}


int main()
{

	BTNode* bt = CreateBinaryTree();
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

	return 0;
}
