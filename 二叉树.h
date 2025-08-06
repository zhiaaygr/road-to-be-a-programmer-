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

//生成树
void createtree(TreadTree* T);

// 递归前序遍历
void PreOrder(TreadTree T);

// 递归中序遍历
void InOrder(TreadTree T);

// 递归后序遍历
void PostOrder(TreadTree T);

//具体元素线索化
void Threading(TreadTree T);

//开始线索化
void InorderThreadingTree(TreadTree* head, TreadTree T);

//循环中序遍历
void Inorder(TreadTree T);