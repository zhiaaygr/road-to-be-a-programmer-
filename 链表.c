#define _CRT_SECURE_NO_WARNINGS 1
#include"����.h"

//����Ԫ����Ϣ
ElemType PutElem(void) {
	ElemType temp;
	scanf("%d", &temp);
	return temp;;
}

//��������
int PutInt(void) {
	int temp;
	scanf("%d", &temp);
	return temp;
}
//��ʼ������
Node* InitList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	head->next = NULL; // ��ʼ��ʱͷ����nextָ��ָ��NULL
	head->data = 0; // ͷ�������ݿ�������Ϊ0������ֵ
	return head;
}

// ��������
void ListNode(Node* head) {
	head = head->next; // �ӵ�һ��Ԫ�ؿ�ʼ��������
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

//ͷ�巨����Ԫ��
void AddElemHead(Node* head, ElemType new){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	newNode->next = head->next; // ���½ڵ��nextָ��ǰͷ������һ���ڵ�
	newNode->data = new; // ���½ڵ����������Ϊ�����ֵ
	head->next = newNode; // ��ͷ����nextָ���½ڵ�
}

//����β����ַ
Node* FindTail(Node* head) {
	Node* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;//����β�ڵ�
}

//β�巨����Ԫ��
Node* AddElemTail(Node* head, Node* tail,ElemType new) {
	Node* newcode = (Node*)malloc(sizeof(Node));
	newcode->data = new;// ���½ڵ����������Ϊ�����ֵ
	newcode->next = tail->next;// ���½ڵ��nextָ��NULL
	tail->next = newcode; // ��β�ڵ��nextָ���½ڵ�
	return newcode; // �����½ڵ���Ϊ�µ�β�ڵ�
}

//Ѱ��ָ��λ�õĵ�ַ
Node* FindPre(Node* head, int pos) {
	Node* precursor = head;
	for (int i = 0; i < pos-1; i++) {
		if (precursor->next == NULL) {
			return NULL; // ���λ�ò��Ϸ�������NULL
		}
		precursor = precursor->next;
	}
	return precursor;
}

//ָ��λ�ò���Ԫ��
void InsertElem(Node* head, int pos, ElemType new) {
	Node* precursor = FindPre(head, pos);
	if (precursor == NULL) {
		printf("λ�ò��Ϸ�\n");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("�ڴ����ʧ��\n");
		return;
	}
	newNode->data = new;//��ֵ
	newNode->next = precursor->next;//��Ŀ��λ�õ�ַ��ֵ���½ڵ��next
	precursor->next = newNode;//��ǰ���ڵ��nextָ���½ڵ�
}

//ɾ��Ԫ��
void DelElem(Node* head, int pos) {
	Node* precursor = FindPre(head, pos);
	Node* delelem = precursor->next;
	precursor->next = delelem->next;
	free(delelem);
}

//����������
int GetLength(Node* head) {
	int length = 0;
	while (head->next!= NULL) {
		head = head->next;
		length++;
	}
	return length;
}

//�ͷ�����
void freeLIst(Node* head) {
	Node* temp;
	Node*L  = head->next;
	while (L!=NULL) {
		temp = L->next;
		free(L);
		L = temp;
	}
	head->next = NULL;
}