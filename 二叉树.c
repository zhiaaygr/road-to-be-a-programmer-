#define _CRT_SECURE_NO_WARNINGS 1
#include"������.h"

//�������������������
void createtree(TreadTree* T) {
	ElemType ch = str[index++];
	if (ch=='#') {
		*T = NULL;
		return;
	}
	*T = (TreadTree)malloc(sizeof(TreadNode));
	if (*T == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	(*T)->data = ch;
	createtree(&(*T)->lchild);
	if ((*T)->lchild != NULL) {//�����������Ϊ�գ�����ָ��ָ��������
		(*T)->lflag = 0; // ��ָ��Ϊ����ָ��
	}
	createtree(&(*T)->rchild);
	if ((*T)->rchild != NULL) {//�����������Ϊ�գ�����ָ��ָ��������
		(*T)->rflag = 0; // ��ָ��Ϊ����ָ
	}
}

// �ݹ�ǰ�����
void PreOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

// �ݹ��������
void InOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	PreOrder(T->lchild);
	printf("%c ", T->data);
	PreOrder(T->rchild);
}

// �ݹ�������
void PostOrder(TreadTree T) {
	if (T == NULL) {
		return;
	}
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c ", T->data);
}

//����Ԫ��������(����)
void Threading(TreadTree T) {
	if (T == NULL) {
		return;
	}
	Threading(T->lchild);
	if (T->lchild == NULL) {//����������������
		T->lchild = Prev;
		T->lflag = 1;
	}
	if (Prev->rchild == NULL) {//ǰ������������������
		Prev->rchild = T;
		Prev->rflag = 1;
	}
	Prev = T;//����ǰ��
	Threading(T->rchild);//�������ݹ�
}

//��ʼ������(����)
void InorderThreadingTree(TreadTree* head,TreadTree T) {
	*head = (TreadTree)malloc(sizeof(TreadTree));
	if (*head == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	(*head)->rchild = *head; // ͷ�ڵ��������Ϊ��
	(*head)->lflag = 0; // ��ָ��Ϊ����ָ��
	(*head)->rflag = 1; // ��ָ��Ϊ����
	if (T == NULL) {
		(*head)->lchild = head; // �����Ϊ�գ�������ָ��ͷ�ڵ�
	}
	else
	{
		(*head)->lchild = T;//��ָ�����������ʼû�з������ң�
		Prev = *head; // ǰ����ʼ��Ϊͷ�ڵ�
		Threading(T); // ������
		Prev->rchild = *head;//���һ���ڵ�ָ��ͷ�ڵ��γɻ�
		Prev->rflag = 1;//��¼Ϊ����
		(*head)->rchild = Prev;//ͷ�ڵ��������ָ�����һ���ڵ�
	}
}

//ѭ���������
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