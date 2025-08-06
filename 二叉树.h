#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct TreadNode {
	char data;
	struct TreadNode* lchild;
	struct TreadNode* rchild;
	int lflag;
	int rflag;
}TreadNode;

typedef TreadNode* TreadTree;

TreadTree Prev;
static int index = 0;
static char str[] = "AB#D##C##";

//������
void createtree(TreadTree* T);

// �ݹ�ǰ�����
void PreOrder(TreadTree T);

// �ݹ��������
void InOrder(TreadTree T);

// �ݹ�������
void PostOrder(TreadTree T);

//����Ԫ��������
void Threading(TreadTree T);

//��ʼ������
void InorderThreadingTree(TreadTree* head, TreadTree T);

//ѭ���������
void Inorder(TreadTree T);