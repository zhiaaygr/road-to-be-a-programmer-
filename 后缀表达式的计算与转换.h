#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct {
	ElemType* data;
	int top;
}Stack;

typedef enum {
	LEFT, RIGHT,
	ADD, SUB, MUL, DIV, MOD, EXP, NUM,SPACE
}contentType;

static int InStack[] = { 0,19,12,12,13,13,20,0 };
static int OutStack[] = { 19,19,12,12,13,13,20,0 };
static char* token[] = { "(", ")", "+", "-", "*", "/", "%", "^" };

//��ʼ��
Stack* InitStack(void);

//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(Stack* s);

//ѹջ
void Push(Stack *s, ElemType e);

// ��ȡջ��Ԫ�أ���������
ElemType GetTop(Stack * s);

//��ջ
ElemType Pop(Stack* s);

//�ж�Ԫ������
contentType GetContentType(ElemType* index, char* strsta);

//����ʽ�ӵ�ֵ
int Calculate(char* strsta, Stack* s);

//��׺ת��׺���ʽ
char* postfix(char* str);

//�ͷ�ջ
void freeStack(Stack* s);


