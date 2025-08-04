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

//初始化
Stack* InitStack(void);

//判断栈是否为空
int IsEmpty(Stack* s);

//压栈
void Push(Stack *s, ElemType e);

// 获取栈顶元素（不弹出）
ElemType GetTop(Stack * s);

//出栈
ElemType Pop(Stack* s);

//判断元素类型
contentType GetContentType(ElemType* index, char* strsta);

//计算式子的值
int Calculate(char* strsta, Stack* s);

//中缀转后缀表达式
char* postfix(char* str);

//释放栈
void freeStack(Stack* s);


