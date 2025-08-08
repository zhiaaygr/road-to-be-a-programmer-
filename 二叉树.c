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
		(*T)->lflag = 0;	
	}
	else if ((*T)->lchild != NULL) {//如果左子树不为空，则左指针指向左子树
		(*T)->lflag = 1;//左指针为线索
	}
	createtree(&(*T)->rchild);
	if ((*T)->rchild != NULL) {//如果右子树不为空，则右指针指向线索
		(*T)->rflag = 0; // 右指针为孩子指针
	}
	if ((*T)->rchild == NULL) {//如果右子树为空，则右指针指向线索
		(*T)->rflag = 1; // 右指针为线索
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
	InOrder(T->lchild);
	printf("%c ", T->data);
	InOrder(T->rchild);
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


//具体元素线索化(先序)
void PreThreading(TreadTree T) {
 	if (T == NULL) {
		return;
	}
	//当前节点线索化
	if (T->lchild == NULL) {
		T->lchild = Prev;
		T->lflag = 1;
	}
	if (Prev != NULL) {
		if (Prev->rchild == NULL) {
			Prev->rchild = T;
			Prev->rflag = 1;
		}
	}
	Prev = T;//前驱更新
	//左节点线索化
	if(T->lflag==0)
	PreThreading(T->lchild);
	//右节点线索化
	if(T->rflag==0)
	PreThreading(T->rchild);
}

//具体元素线索化(中序)
void InThreading(TreadTree T) {
	if (T == NULL) {
		return;
	}
	InThreading(T->lchild);//前驱线索化
	if (T->lchild == NULL) {//左子树空则线索化
		T->lchild = Prev;
		T->lflag = 1;
	}
	if (Prev->rchild == NULL) {//前驱右子树空则线索化
		Prev->rchild = T;
		Prev->rflag = 1;
	}
	Prev = T;//更新前驱
	InThreading(T->rchild);//右子树线索化
}

//具体元素线索化(后序)
void PostThreading(TreadTree T) {
	if (T == NULL) {
		return;
	}
	//将双亲结点赋值,空指针不需要线索
	if (T->lchild != NULL) {
		T->lchild->parent = T;
	}
	if (T->rchild != NULL) {
		T->rchild->parent = T;
	}
	//左节点线索化
	//if(T->lflag==1)
	PostThreading(T->lchild);
	//右节点线索化
	//if (T->rflag == 0)
	PostThreading(T->rchild);
	if (T->lchild == NULL) {//左子树空则线索化
		T->lchild = Prev;
		T->lflag = 1;
	}
	if (Prev->rchild == NULL) {//前驱右子树空则线索化
		Prev->rchild = T;
		Prev->rflag = 1;
	}
	Prev = T;//更新前驱
}

//开始线索化
void ThreadingTree(TreadTree* head,TreadTree T,Order order) {
	*head = (TreadTree)malloc(sizeof(TreadNode));
	if (*head == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	(*head)->rchild = *head; // 头节点的右子树为空
	(*head)->lflag = 0; // 左指针为孩子指针
	(*head)->rflag = 1; // 右指针为线索
	if (T == NULL) {
		(*head)->lchild = *head; // 如果树为空，左子树指向头节点
	}
	else
	{
		(*head)->lchild = T;//左指针接上树（开始没有分清左右）
		Prev = *head; // 前驱初始化为头节点
		switch (order) {
		case Pre:
			PreThreading(T);
			break;
		case In:
			InThreading(T);
			break;
		case Post:
			PostThreading(T);
			break;
		}
		if (order != Post) {
			Prev->rchild = *head;//最后一个节点指向头节点形成环
			Prev->rflag = 1;//记录为线索
			(*head)->rchild = Prev;//头节点的右子树指向最后一个节点
		}
		else if (order == Post) {
			Prev->parent = *head;
		}
	}
}


//循环先序遍历
void ThreadPreOrder(TreadTree head) {
	TreadTree curr;
	curr = head->lchild;
	while (curr != head) {
		while (curr->lflag == 0) {
			printf("%c ", curr->data);//输出当前信息
			curr = curr->lchild;//向左行驶
		}
		printf("%c ", curr->data);//最后一个元素左子树为线索，但本身为树，需输出
		curr = curr->rchild;//移动到下一元素
	}
	printf("\n");
}

//循环中序遍历
void ThreadInOrder(TreadTree head) {
	TreadTree curr;
	curr = head->lchild;
	while (curr != head) {
		while (curr->lflag == 0) {
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rflag == 1 &&curr->rchild!=head) {
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}

//循环后序遍历,鸡肋，不要

