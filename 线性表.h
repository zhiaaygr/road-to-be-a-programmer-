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

//����Ԫ����Ϣ
ElemType PutElem(void);

//��������
int inputInt(void);

//��ʼ��˳���
void InitList(SeqList** L);

//����˳���
void DestroyList(SeqList* L);

//���Ԫ��
void AddElem(SeqList*L);

//ɾ��Ԫ��
DelElem(SeqList*L);

//����Ԫ��
void InsertElem(SeqList* L);

//����Ԫ��
int SerchElem(SeqList *L);

//����Ԫ��
void ListElem(SeqList*L);

//�޸�Ԫ��
void ModifyElem(SeqList* L);