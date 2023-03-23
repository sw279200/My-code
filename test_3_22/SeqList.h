#pragma once

#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//增强程序可维护性
typedef int SQDataType;
//动态的
typedef struct SeqList
{
	SQDataType* a;
	int size; //有效数据的个数
	int capacity;//容量
}SL;


//初始化顺序表
void SeqListInit(SL* ps);
//打印顺序表中的内容
void SeqListPrint(SL* ps);
//销毁顺序表
void SeqListDestroy(SL* ps);

//增删查改等接口函数
//向顺序表中插入元素
void SeqListInsert(SL* ps,int pos, SQDataType x);

// 头插 尾插 头删 尾删
void SeqListPushFront(SL* ps, SQDataType x);

void SeqListPushBack(SL* ps, SQDataType x);

void SeqListPopFront(SL* ps);

void SeqListPopBack(SL* ps);

void SeqListErase(SL* ps, int pos);

int SeqListFind(SL* ps, SQDataType x);

void SeqListModify(SL* ps, int pos, SQDataType x);
#endif