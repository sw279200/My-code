#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{		
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;


//先序
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//中序
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//后序
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}


//节点个数
int BTNodeSize(BTNode* root)
{
	return root == NULL ? 0 : BTNodeSize(root->left) + BTNodeSize(root->right) + 1;
}

//叶子数
int LeafNodeSize(BTNode* root)
{
	//空节点
	if (root == NULL)
	{
		return 0;
	}
	//叶子节点
	if (root->left == NULL && root->right==NULL)
	{
		return 1;
	}
	//既不是叶子节点也不是空节点

	return LeafNodeSize(root->left) + LeafNodeSize(root->right);
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if(root)
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* Front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", Front -> data);
		if (Front->left)
		{
			QueuePush(&q, Front->left);
		}
		if (Front->right)
		{
			QueuePush(&q, Front->right);
		}

	}
	printf("\n");
	QueueDestroy(&q);

}

int main()
{
	BTNode* A =(BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B=(BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;


	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;
	
	A->left = B;
	A->right = C;
	B->right = E;
	B->left = D;


	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("BTNodeSize: %d\n", BTNodeSize(A));
	printf("BTNodeSize: %d\n", BTNodeSize(B));
	printf("BTNodeSize: %d\n", BTNodeSize(C));
	printf("叶子节点数：%d\n", LeafNodeSize(A));

	LevelOrder(A);
	return 0;
}
