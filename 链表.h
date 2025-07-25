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

//寻找第k个节点
Node* find_node_k(Node* head, int k);

// 去掉链表的绝对值相同元素，保留第一个（abs函数）,最多有n个元素
void remove_duplicate(Node* head,int n);

// 反转链表
void reverse_list(Node* head);

// 寻找中间值
Node* find_middle(Node* head);

// 判断是否是有环
int IfCycle(Node* head);

//寻找环的入口
Node* find_cycle_entry(Node* head);