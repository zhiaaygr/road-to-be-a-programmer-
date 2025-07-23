#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 100

//��ӡ�˵���ѡ��
int menu();


// ����ͨѶ¼
typedef struct peoinf {
	char name[11];
	char phnum[12];
	int age;
	char sex[5];
	char adds[30];
} peoinf;
//��̬�汾
//typedef struct Contact {
//	peoinf peo[MAX];
//	int count;
//}Contact;

//��̬�汾
typedef struct Contact {
	peoinf *peo; //ָ����ϵ�������ָ��
	int count;   //��ǰ��ϵ������
	int capacity; //ͨѶ¼����
} Contact;

//����ͨѶ¼
void LoadContact(Contact* contact);

//����ͨѶ¼����
void increase_capacity(Contact* contact);


//��ʼ��ͨѶ¼
void initcontact(Contact *contact);

//��ʾͨѶ¼
void ShowContact(const Contact* contact);

//������ϵ��
int findname(Contact *contact,char name[]);
void search(Contact* contact);

//�½���ϵ��
void addpho(Contact *contact);

//ɾ����ϵ��
void delete(Contact *contact);

//����ͨѶ¼
void DestroyContact(Contact* contact); 

//�洢ͨѶ¼
void SaveContact(Contact contact);

//����������
void sort(Contact contact);
//������Ϣ
void change(peoinf* a, peoinf* b);

