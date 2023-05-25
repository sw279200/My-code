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

//初始化
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//入队列
void QueuePush(Queue* pq, QDataType x);

//出队列
void QueuePop(Queue* pq);

//取队列的队头元素
QDataType QueueFront(Queue* pq);

//取队列的队尾元素
QDataType QueueBack(Queue* pq);

//返回队列长度
int QueueSize(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);