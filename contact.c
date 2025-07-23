#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include <stdlib.h>

int menu()
{
	int input;
	printf("*****************************************\n");
	printf("*****1.��ʾͨѶ¼      2.������ϵ�� *****\n");
	printf("*****3.�洢��ϵ��      4.ɾ����ϵ�� *****\n");
	printf("*****5.�޸���ϵ����Ϣ  6.���������� *****\n");
	printf("*****0.�˳�                         *****\n");
	printf("��ѡ��:>");
	scanf("%d", &input);
	return input;
}

//����ͨѶ¼����
void increase_capacity(Contact* contact) {
	assert(contact);
	if (contact->capacity == contact->count) {
		peoinf* pc = (peoinf*)realloc(contact->peo, (contact->capacity + 2) * sizeof(peoinf));
		if (pc == NULL)
		{
			printf("�ڴ����ʧ��\n");
			exit(EXIT_FAILURE);
		}
		contact->peo = pc; //��ָ��ָ���·�����ڴ�
		contact->capacity += 2; //��������
	}
}

//����ͨѶ¼
void LoadContact(Contact* contact) {
	peoinf temp = {0};
	FILE* file = fopen("contact.txt", "rb");
	if (file == NULL) {
		perror("LoadContact");
		return;
	}
	while (fread(&temp, sizeof(peoinf), 1, file) == 1) {
		if(contact->capacity==contact->count)
		increase_capacity(contact); //��������
		contact->peo[contact->count] = temp;
		contact->count++;
	}
	fclose(file);
}

//��ʼ��ͨѶ¼
//��̬�汾
//void initcontact(Contact* contact)
//{
//	assert(contact);
//	memset(contact,0,sizeof(*contact));
//}
//��̬�汾
void initcontact(Contact* contact)
{
	assert(contact);
	contact->peo = (peoinf*)malloc(3 * sizeof(peoinf));
	assert(contact->peo); //ȷ���ڴ����ɹ�
	contact->count = 0; //��ʼ����ϵ������Ϊ0
	contact->capacity = 2; //��ʼ����Ϊ2
	LoadContact(contact);  //����ͨѶ¼
}

//��ʾͨѶ¼
void print(const Contact* contact,int i) {
	printf("%6s\t%12s\t%3d\t%5s\t%-30s\n", contact->peo[i].name,
		contact->peo[i].phnum,
		contact->peo[i].age,
		contact->peo[i].sex,
		contact->peo[i].adds);
}
void ShowContact(const Contact* contact)
{
	assert(contact);
	printf("%6s\t%12s\t%3s\t%5s\t%-30s\n","����","�绰����","����","�Ա�","��ַ");
	for (int i = 0; i < contact->count; i++)
	{
		print(contact, i);
	}
}

//������ϵ��
int findname(const Contact* contact, char name[])
{
	assert(contact);
	for (int i = 0; i < contact->count; i++)
	{
			if (strcmp(contact->peo[i].name, name) == 0) 
		
		return i;
	}
	return -1;
} 
void search(Contact* contact)
{
	assert(contact);
	if (contact->count == 0)
	{
		printf("������ϵ�ˣ�������ѡ��\n");
		return;
	}
	char name[11];
	printf("������Ҫ�����˵�����\n");
	scanf("%s", name);
	int ret = findname(contact,name);
	if (ret != -1)
	{
		printf("%5s\t%12s\t%3s\t%5s\t%-30s\n", "����", "�绰����", "����", "�Ա�", "��ַ");
		print(contact, ret);
	}
	else printf("���޴���\n");

}

//�½���ϵ��
void addpho(Contact* contact)
{
	assert(contact);
	printf("����������:>\n");
	scanf("%s", contact->peo[contact->count].name);
	printf("������绰����:>\n");
	scanf("%s", contact->peo[contact->count].phnum);
	printf("����������:>\n");
	scanf("%d", &contact->peo[contact->count].age);
	printf("�������Ա�:>\n");
	scanf("%s", contact->peo[contact->count].sex);
	printf("�������ַ:>\n");
	scanf("%s", contact->peo[contact->count].adds);
	contact->count++;
}

//ɾ����ϵ��
void delete(Contact* contact)
{
	assert(contact);
	int name[11];
	if (contact->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ���ɾ������\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>\n"); 
	scanf("%s", name);
	int ret = findname(contact, name);
	if ( ret== -1) {
		printf("���޴���\n");
		return;
	}
	for (int i = ret; i < contact->count; i++)
	{
		contact->peo[i] = contact->peo[i + 1];
	}
	printf("ɾ���ɹ�\n");
	contact->count--;
}

//����ͨѶ¼
void DestroyContact(Contact* contact) {
	assert(contact);
	free(contact->peo); //�ͷ���ϵ��������ڴ�
	contact->peo = NULL; //��������ָ��
	contact->count = 0; //������ϵ������
	contact->capacity = 0; //����ͨѶ¼����
	printf("���˳�/n");
}

//�洢ͨѶ¼
void SaveContact(const Contact* contact) {
	assert(contact && contact->peo);
	FILE* file = fopen("contact.txt", "wb");
	if (file == NULL) {
		perror("SaveContact");
		return;
		printf("yes");
	}
	for (int i = 0; i < contact->count; i++) {
		fwrite(contact->peo + i, sizeof(peoinf), 1, file);
	}
	fclose(file);
}

//����������
void sort(Contact contact) {
	assert(contact.peo);
	for (int i = 0; i < contact.count - 1; i++) {
		for (int j = 0; j < contact.count - 1 - i; j++) {
			if (strcmp(contact.peo[j].name, contact.peo[j + 1].name) > 0) {
				change(&contact.peo[j], &contact.peo[j + 1]);
			}
		}
	}
}

//������Ϣ
void change(peoinf* a, peoinf* b) {
	peoinf temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

