#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//���ٶ���
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

//��β��
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

//��ͷ��
void QueuePop(Queue* pq)
{
	//1.һ��
	//2.���
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

//ȡ���еĶ�ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//ȡ���еĶ�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}

//���ض��г���
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

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}