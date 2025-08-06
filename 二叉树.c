#define _CRT_SECURE_NO_WARNINGS 1
#include"二叉树.h"

//生成树（按先序遍历）
void createtree(TreadTree* T) {
	ElemType ch = str[index++];
	if (ch=='#') {
		*T = NULL;
		return;
	}
	*T = (TreadTree)malloc(sizeof(TreadNode));
	if (*T == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	(*T)->data = ch;
	createtree(&(*T)->lchild);
	if ((*T)->lchild != NULL) {//如果左子树不为空，则左指针指向左子树
		(*T)->lflag = 0; // 左指针为孩子指针
	}
	createtree(&(*T)->rchild);
	if ((*T)->rchild != NULL) {//如果右子树不为空，则右指针指向右子树
		(*T)->rflag = 0; // 右指针为孩子指
	}
}

// 递归前序遍历
void PreOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

// 递归中序遍历
void InOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	PreOrder(T->lchild);
	printf("%c ", T->data);
	PreOrder(T->rchild);
}

// 递归后序遍历
void PostOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c ", T->data);
}

//具体元素线索化(中序)
void Threading(TreadTree T) {
	if (T == NULL) {
		return;
	}
	Threading(T->lchild);
	if (T->lchild == NULL) {//左子树空则线索化
		T->lchild = Prev;
		T->lflag = 1;
	}
	if (Prev->rchild == NULL) {//前驱右子树空则线索化
		Prev->rchild = T;
		Prev->rflag = 1;
	}
	Prev = T;//更新前驱
	Threading(T->rchild);//右子树递归
}

//开始线索化(中序)
void InorderThreadingTree(TreadTree* head,TreadTree T) {
	*head = (TreadTree)malloc(sizeof(TreadTree));
	if (*head == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	(*head)->rchild = *head; // 头节点的右子树为空
	(*head)->lflag = 0; // 左指针为孩子指针
	(*head)->rflag = 1; // 右指针为线索
	if (T == NULL) {
		(*head)->lchild = head; // 如果树为空，左子树指向头节点
	}
	else
	{
		(*head)->lchild = T;//左指针接上树（开始没有分清左右）
		Prev = *head; // 前驱初始化为头节点
		Threading(T); // 线索化
		Prev->rchild = *head;//最后一个节点指向头节点形成环
		Prev->rflag = 1;//记录为线索
		(*head)->rchild = Prev;//头节点的右子树指向最后一个节点
	}
}

//循环中序遍历
void Inorder(TreadTree T) {
	TreadTree curr;
	curr = T->lchild;
	while (curr != T) {
		while (curr->lflag == 0) {
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rflag == 1 &&curr->rchild!=T) {
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}