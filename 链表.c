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

//寻找第k个节点
Node* find_node_k(Node* head, int k) {
	Node* fast = head->next; // 从第一个元素开始
	Node* slow = head->next; // 从第一个元素开始
	for (int i = 0; i < k; i++) {
		fast = fast->next; // 快指针先走k步
	}
	while (fast != NULL) {
		slow = slow->next; // 慢指针每次走一步
		fast = fast->next; // 快指针每次走一步
	}
	return slow; // 慢指针此时指向的就是倒数第k个节点
}

// 去掉链表的绝对值相同元素，保留第一个（abs函数），最多有n个整数
void remove_duplicate(Node* head, int n) {
	ElemType* arr = (ElemType*)malloc(sizeof(ElemType) * (n + 1));
	if (arr == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = 0; // 初始化数组
	}
	head = head->next; // 从第一个元素开始
	while (head->next != NULL) {
		if (arr[abs(head->data)] == 0) {
			arr[abs(head->data)] = 1;
		}
		else {
			Node* temp = head; // 保存该节点
			head = head->next; // 将当前节点的next指向下一个节点的next
			free(temp); // 释放下一个节点的内存
		}
	}
}
// 反转链表
void reverse_list(Node* head) {
	Node* first;
	Node* second;
	Node* third;
	first = NULL;
	second = head->next;
	third = head->next;
	while(second!=NULL){
		third = third->next;
		second->next = first;
		first = second;
		second = third;
	}
	head->next = first;
}

// 寻找中间值
Node* find_middle(Node* head) {
	Node *fast,*slow;
	fast = slow = head;
	while (1) {
		fast = fast->next->next;
		slow = slow->next;
		//偶数个元素
		if (fast->next == NULL) {
			return slow;
		}
		//奇数个元素
		if (fast== NULL) {
			return slow;
		}
	}
}

// 判断是否是有环
int IfCycle(Node* head) {
	Node* fast, * slow;
	fast = slow = head;
	for (int i = 0; i < 100000000; ++i) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			return 1;
		}
	}
	return -1;
}

//寻找环的入口
Node* find_cycle_entry(Node* head) {
	int size,temp,flag=0;
	Node* fast, * slow;
	fast = slow = head; // 初始化快慢指针
	for (int i=0;;i++) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			flag++;
			if (flag == 2) {
				size = i - temp; // 计算环的长度
				break;
			}
			temp = i;
		}
	}
	fast = slow = head; // 重置快慢指针
	for (int i = 0; i < size; i++) {
		fast = fast->next;
	}
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast; // 返回环的入口节点
}
