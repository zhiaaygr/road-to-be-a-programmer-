#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct {
	int lenth;
	int capacity;
	ElemType data[];
}SeqList;

//输入元素信息
ElemType PutElem(void);

//输入整数
int inputInt(void);

//初始化顺序表
void InitList(SeqList** L);

//销毁顺序表
void DestroyList(SeqList* L);

//添加元素
void AddElem(SeqList*L);

//删除元素
DelElem(SeqList*L);

//插入元素
void InsertElem(SeqList* L);

//查找元素
int SerchElem(SeqList *L);

//遍历元素
void ListElem(SeqList*L);

//修改元素
void ModifyElem(SeqList* L);