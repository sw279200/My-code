#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//��ʼ��
void StackInit(stack* ps)
{
	assert(ps);
	ps->arr = (STDataType*)malloc(4 * sizeof(STDataType));
	 if (ps->arr == NULL)
	 {
		 printf("malloc fail\n");
		 exit(-1);
	 }
	ps->capacity = 4;
	ps->top = 0;

}

//����
void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//ѹջ
void StackPush(stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* temp= (STDataType*)realloc(ps->arr, ps->capacity *2* sizeof(STDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = temp;
			ps->capacity *= 2;
		}
	}
	ps->arr[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;

}

//����ջ��Ԫ��
STDataType StackTop(stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return (ps->arr[ps->top - 1]);
}

//�п�
bool StackEmpty(stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

//ջ��
int StackSize(stack* ps)
{
	assert(ps);

	return ps->top;
}