#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//�����
void QueuePush(Queue* pq, QDataType x);

//������
void QueuePop(Queue* pq);

//ȡ���еĶ�ͷԪ��
QDataType QueueFront(Queue* pq);

//ȡ���еĶ�βԪ��
QDataType QueueBack(Queue* pq);

//���ض��г���
int QueueSize(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);