#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//ջ��ʵ��

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}stack;

//��ʼ��
void StackInit(stack* ps);

//����
void StackDestroy(stack* ps);

//ѹջ
void StackPush(stack* ps, STDataType x);

//��ջ
void StackPop(stack* ps);

//����ջ��Ԫ��
STDataType StackTop(stack* ps);

//�п�
bool StackEmpty(stack* ps);

//ջ��
int StackSize(stack* ps);
