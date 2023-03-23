#pragma once

#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//��ǿ�����ά����
typedef int SQDataType;
//��̬��
typedef struct SeqList
{
	SQDataType* a;
	int size; //��Ч���ݵĸ���
	int capacity;//����
}SL;


//��ʼ��˳���
void SeqListInit(SL* ps);
//��ӡ˳����е�����
void SeqListPrint(SL* ps);
//����˳���
void SeqListDestroy(SL* ps);

//��ɾ��ĵȽӿں���
//��˳����в���Ԫ��
void SeqListInsert(SL* ps,int pos, SQDataType x);

// ͷ�� β�� ͷɾ βɾ
void SeqListPushFront(SL* ps, SQDataType x);

void SeqListPushBack(SL* ps, SQDataType x);

void SeqListPopFront(SL* ps);

void SeqListPopBack(SL* ps);

void SeqListErase(SL* ps, int pos);

int SeqListFind(SL* ps, SQDataType x);

void SeqListModify(SL* ps, int pos, SQDataType x);
#endif