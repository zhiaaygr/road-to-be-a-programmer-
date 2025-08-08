#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct TreadNode {
	char data;
	struct TreadNode* lchild;
	struct TreadNode* rchild;
	struct TreadNode* parent;
	int lflag;
	int rflag;
}TreadNode;

typedef TreadNode* TreadTree;

typedef enum {
	Pre,
	In,
	Post,
} Order;

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

//具体元素线索化(先序)
void PreThreading(TreadTree T);

//具体元素线索化(中序)
void InThreading(TreadTree T);

//具体元素线索化(后序)
void PostThreading(TreadTree T);

//开始线索化
void ThreadingTree(TreadTree* head, TreadTree T,Order order);

//循环先序遍历
void ThreadPreOrder(TreadTree T);

//循环中序遍历
void ThreadInOrder(TreadTree T);

//循环后序遍历,鸡肋，不要

