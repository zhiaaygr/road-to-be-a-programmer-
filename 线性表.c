#define _CRT_SECURE_NO_WARNINGS 1
#include"FileName.h"

//����Ԫ����Ϣ
ElemType PutElem(void) {
	ElemType temp;
	scanf("%d", &temp);
	return temp;;
}

//��������
int inputInt(void) {
	int temp;
	scanf("%d", &temp);
	return temp;
}

//��ʼ��˳���
void InitList(SeqList** L) {
	*L=malloc(sizeof(SeqList)+1*sizeof(ElemType));
	if (*L == NULL) {
		printf("����ʧ��\n");
		return;
	}
	(*L)->lenth = 0;
	(*L)->capacity = 1;
}

//����˳���
void DestroyList(SeqList* L) {
	L->lenth = 0;
	L->capacity = 10;
}

//����
void ExpandList(SeqList* L) {
	ElemType* newData = realloc(L, (L->capacity + 10) * sizeof(ElemType));
	if (newData == NULL) {
		printf("����ʧ��\n");
		return;
	}
	L->capacity += 10;
}

//���Ԫ��
void AddElem(SeqList* L) {
	if (L->lenth >= L->capacity) {
		ExpandList(L);
	}
	printf("������Ԫ����Ϣ��");

	L->data[L->lenth] = PutElem();
	L->lenth++;
}

//ɾ��Ԫ��
DelElem(SeqList* L) {
	int temp;
	printf("������Ҫɾ����Ԫ��λ�ã�");
	temp = inputInt();
	if(temp>L->lenth){
		printf("λ�ò��Ϸ�\n");
		return;
	}
	for (int i = temp - 1; i < L->lenth-1; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->lenth--;
}
//����Ԫ��
void InsertElem(SeqList* L) {
	printf("������Ҫ�����λ��\n");
	int pos = inputInt();
	if (L->lenth >= L->capacity) {
		ExpandList(L);
	}
	if (pos < 1 || pos > L->lenth + 1) {
		printf("λ�ò��Ϸ�\n");
		return;
	}
	L->lenth++;
	for (int i = L->lenth-1; i >pos-1;i--) {
		L->data[i] = L->data[i - 1];
	}
	printf("������Ҫ�����Ԫ�أ�");
	L->data[pos - 1] = PutElem();
}

//����Ԫ��
int SerchElem(SeqList* L) {
	ElemType temp = PutElem();
	for (int i = 0; i < L->lenth; i++) {
		if (L->data[i] == temp) {
			return i + 1; //����λ��
		}
	}
	printf("Ԫ��δ�ҵ�\n");
}

//����Ԫ��
void ListElem(SeqList* L) {
	for (int i = 0; i < L->lenth; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//�޸�Ԫ��
void ModifyElem(SeqList* L) {
	printf("������Ҫ�޸ĵ�Ԫ��λ�ã�\n");
	int pos = inputInt();
	printf("��������Ԫ��ֵ\n");
	L->data[pos-1] = PutElem();
}