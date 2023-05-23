#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//交换两个元素
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) >> 1;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			break;
		}
	}

}


//向下调整算法
void AdjustDown(int* a, int n, int parent)
{
	int child = parent*2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent*2 + 1;
		}
		else
		{
			break;
		}

	}
}


//堆初始化
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}


//销毁
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php -> size = php->capacity = 0;
	free(php);
}

//插入
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newCapacity = (php->capacity == 0) ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a,sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			return;
		}	
		php->a = tmp;
		php->capacity = newCapacity;
	}
	
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}
// 删除堆顶数据
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}


//获取堆顶元素
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

//判空
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//获取堆的大小
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}