#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//初始化链表
Node* InitList();

// 遍历链表
void ListNode(Node* head);

//输入元素信息
ElemType PutElem(void);

//输入整数
int PutInt(void);

//头插法增加元素
void AddElemHead(Node* head, ElemType* new);

//查找尾部地址
Node* FindTail(Node* head);

//尾插法增加元素
Node* AddElemTail(Node* head, Node* tail, ElemType new);

//寻找指定位置的地址
Node* FindPre(Node* head, int pos);

//指定位置插入元素
void InsertElem(Node* head, int pos, ElemType* new);

//删除元素
void DelElem(Node* head, int pos);

//计算链表长度
int GetLength(Node* head);

//释放链表
void freeLIst(Node* head);