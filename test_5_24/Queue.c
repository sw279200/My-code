#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;

}

//队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->tail = newnode;
		pq->head = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;


	}

}

//队头出
void QueuePop(Queue* pq)
{
	//1.一个
	//2.多个
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//取队列的队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//取队列的队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}

//返回队列长度
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (!cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}