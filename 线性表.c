#define _CRT_SECURE_NO_WARNINGS 1
#include"FileName.h"

//输入元素信息
ElemType PutElem(void) {
	ElemType temp;
	scanf("%d", &temp);
	return temp;;
}

//输入整数
int inputInt(void) {
	int temp;
	scanf("%d", &temp);
	return temp;
}

//初始化顺序表
void InitList(SeqList** L) {
	*L=malloc(sizeof(SeqList)+1*sizeof(ElemType));
	if (*L == NULL) {
		printf("开辟失败\n");
		return;
	}
	(*L)->lenth = 0;
	(*L)->capacity = 1;
}

//销毁顺序表
void DestroyList(SeqList* L) {
	L->lenth = 0;
	L->capacity = 10;
}

//增容
void ExpandList(SeqList* L) {
	ElemType* newData = realloc(L, (L->capacity + 10) * sizeof(ElemType));
	if (newData == NULL) {
		printf("扩容失败\n");
		return;
	}
	L->capacity += 10;
}

//添加元素
void AddElem(SeqList* L) {
	if (L->lenth >= L->capacity) {
		ExpandList(L);
	}
	printf("请输入元素信息：");

	L->data[L->lenth] = PutElem();
	L->lenth++;
}

//删除元素
DelElem(SeqList* L) {
	int temp;
	printf("请输入要删除的元素位置：");
	temp = inputInt();
	if(temp>L->lenth){
		printf("位置不合法\n");
		return;
	}
	for (int i = temp - 1; i < L->lenth-1; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->lenth--;
}
//插入元素
void InsertElem(SeqList* L) {
	printf("请输入要插入的位置\n");
	int pos = inputInt();
	if (L->lenth >= L->capacity) {
		ExpandList(L);
	}
	if (pos < 1 || pos > L->lenth + 1) {
		printf("位置不合法\n");
		return;
	}
	L->lenth++;
	for (int i = L->lenth-1; i >pos-1;i--) {
		L->data[i] = L->data[i - 1];
	}
	printf("请输入要插入的元素：");
	L->data[pos - 1] = PutElem();
}

//查找元素
int SerchElem(SeqList* L) {
	ElemType temp = PutElem();
	for (int i = 0; i < L->lenth; i++) {
		if (L->data[i] == temp) {
			return i + 1; //返回位置
		}
	}
	printf("元素未找到\n");
}

//遍历元素
void ListElem(SeqList* L) {
	for (int i = 0; i < L->lenth; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//修改元素
void ModifyElem(SeqList* L) {
	printf("请输入要修改的元素位置：\n");
	int pos = inputInt();
	printf("请输入新元素值\n");
	L->data[pos-1] = PutElem();
}