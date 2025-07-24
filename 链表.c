#define _CRT_SECURE_NO_WARNINGS 1
#include"链表.h"

//输入元素信息
ElemType PutElem(void) {
	ElemType temp;
	scanf("%d", &temp);
	return temp;;
}

//输入整数
int PutInt(void) {
	int temp;
	scanf("%d", &temp);
	return temp;
}
//初始化链表
Node* InitList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	head->next = NULL; // 初始化时头结点的next指针指向NULL
	head->data = 0; // 头结点的数据可以设置为0或其他值
	return head;
}

// 遍历链表
void ListNode(Node* head) {
	head = head->next; // 从第一个元素开始遍历链表
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

//头插法增加元素
void AddElemHead(Node* head, ElemType new){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->next = head->next; // 将新节点的next指向当前头结点的下一个节点
	newNode->data = new; // 将新节点的数据设置为传入的值
	head->next = newNode; // 将头结点的next指向新节点
}

//查找尾部地址
Node* FindTail(Node* head) {
	Node* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;//返回尾节点
}

//尾插法增加元素
Node* AddElemTail(Node* head, Node* tail,ElemType new) {
	Node* newcode = (Node*)malloc(sizeof(Node));
	newcode->data = new;// 将新节点的数据设置为传入的值
	newcode->next = tail->next;// 将新节点的next指向NULL
	tail->next = newcode; // 将尾节点的next指向新节点
	return newcode; // 返回新节点作为新的尾节点
}

//寻找指定位置的地址
Node* FindPre(Node* head, int pos) {
	Node* precursor = head;
	for (int i = 0; i < pos-1; i++) {
		if (precursor->next == NULL) {
			return NULL; // 如果位置不合法，返回NULL
		}
		precursor = precursor->next;
	}
	return precursor;
}

//指定位置插入元素
void InsertElem(Node* head, int pos, ElemType new) {
	Node* precursor = FindPre(head, pos);
	if (precursor == NULL) {
		printf("位置不合法\n");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		return;
	}
	newNode->data = new;//赋值
	newNode->next = precursor->next;//将目标位置地址赋值给新节点的next
	precursor->next = newNode;//将前驱节点的next指向新节点
}

//删除元素
void DelElem(Node* head, int pos) {
	Node* precursor = FindPre(head, pos);
	Node* delelem = precursor->next;
	precursor->next = delelem->next;
	free(delelem);
}

//计算链表长度
int GetLength(Node* head) {
	int length = 0;
	while (head->next!= NULL) {
		head = head->next;
		length++;
	}
	return length;
}

//释放链表
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