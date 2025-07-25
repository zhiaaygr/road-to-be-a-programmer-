#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//��ʼ������
Node* InitList();

// ��������
void ListNode(Node* head);

//����Ԫ����Ϣ
ElemType PutElem(void);

//��������
int PutInt(void);

//ͷ�巨����Ԫ��
void AddElemHead(Node* head, ElemType* new);

//����β����ַ
Node* FindTail(Node* head);

//β�巨����Ԫ��
Node* AddElemTail(Node* head, Node* tail, ElemType new);

//Ѱ��ָ��λ�õĵ�ַ
Node* FindPre(Node* head, int pos);

//ָ��λ�ò���Ԫ��
void InsertElem(Node* head, int pos, ElemType* new);

//ɾ��Ԫ��
void DelElem(Node* head, int pos);

//����������
int GetLength(Node* head);

//�ͷ�����
void freeLIst(Node* head);

//Ѱ�ҵ�k���ڵ�
Node* find_node_k(Node* head, int k);

// ȥ������ľ���ֵ��ͬԪ�أ�������һ����abs������,�����n��Ԫ��
void remove_duplicate(Node* head,int n);

// ��ת����
void reverse_list(Node* head);

// Ѱ���м�ֵ
Node* find_middle(Node* head);

// �ж��Ƿ����л�
int IfCycle(Node* head);

//Ѱ�һ������
Node* find_cycle_entry(Node* head);