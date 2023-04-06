#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//栈的实现

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}stack;

//初始化
void StackInit(stack* ps);

//销毁
void StackDestroy(stack* ps);

//压栈
void StackPush(stack* ps, STDataType x);

//出栈
void StackPop(stack* ps);

//返回栈顶元素
STDataType StackTop(stack* ps);

//判空
bool StackEmpty(stack* ps);

//栈长
int StackSize(stack* ps);
