#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//销毁顺序表
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//检查容量是否足够
void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType *temp = (SQDataType* )realloc(ps->a, newcapacity * sizeof(SQDataType));

		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
	}
	

}

//顺序表的插入
void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	assert(pos <= ps->size);
	//检查容量
	SeqListCheckCapacity(ps);
	//把pos这个位置的以后的数据往后移
	int end = ps->size - 1;
	while (pos <= end)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	//把这个值插入顺序表中
	ps->a[pos] = x;
	ps->size++;
}

//查找顺序表中的元素
int SeqListFind(SL* ps, SQDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	//如果顺序表中没有该元素就返回-1
	return -1;
}
//顺序表的删除操作
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int ret = SeqListFind(ps, ps->a[pos]);
	if (ret == -1)
	{
		printf("你要删除的元素不存在！\n");
		return;
	}
	int start = pos + 1;
	//把要删除的元素后面的元素前移
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		start++;
	}
	ps->size--;
}

//修改顺序表中的元素
void SeqListModify(SL* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}

//尾部插入元素
void SeqListPushBack(SL* ps, SQDataType x)
{
	SeqListInsert(ps, ps->size, x);
}

//头部插入元素
void SeqListPushFront(SL* ps, SQDataType x)
{
	SeqListInsert(ps, 0, x);
}

//尾部删除元素
void SeqListPopBack(SL* ps)
{
	SeqListErase(ps,ps->size);
}

//头部删除元素
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);    
	SeqListErase(ps, 0);
}

//打印顺序表中的元素
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}