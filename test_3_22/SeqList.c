#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//��ʼ��˳���
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//����˳���
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//��������Ƿ��㹻
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

//˳���Ĳ���
void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	assert(pos <= ps->size);
	//�������
	SeqListCheckCapacity(ps);
	//��pos���λ�õ��Ժ������������
	int end = ps->size - 1;
	while (pos <= end)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	//�����ֵ����˳�����
	ps->a[pos] = x;
	ps->size++;
}

//����˳����е�Ԫ��
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
	//���˳�����û�и�Ԫ�ؾͷ���-1
	return -1;
}
//˳����ɾ������
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int ret = SeqListFind(ps, ps->a[pos]);
	if (ret == -1)
	{
		printf("��Ҫɾ����Ԫ�ز����ڣ�\n");
		return;
	}
	int start = pos + 1;
	//��Ҫɾ����Ԫ�غ����Ԫ��ǰ��
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		start++;
	}
	ps->size--;
}

//�޸�˳����е�Ԫ��
void SeqListModify(SL* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}

//β������Ԫ��
void SeqListPushBack(SL* ps, SQDataType x)
{
	SeqListInsert(ps, ps->size, x);
}

//ͷ������Ԫ��
void SeqListPushFront(SL* ps, SQDataType x)
{
	SeqListInsert(ps, 0, x);
}

//β��ɾ��Ԫ��
void SeqListPopBack(SL* ps)
{
	SeqListErase(ps,ps->size);
}

//ͷ��ɾ��Ԫ��
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);    
	SeqListErase(ps, 0);
}

//��ӡ˳����е�Ԫ��
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}