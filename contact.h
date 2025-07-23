#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 100

//打印菜单并选择
int menu();


// 建立通讯录
typedef struct peoinf {
	char name[11];
	char phnum[12];
	int age;
	char sex[5];
	char adds[30];
} peoinf;
//静态版本
//typedef struct Contact {
//	peoinf peo[MAX];
//	int count;
//}Contact;

//动态版本
typedef struct Contact {
	peoinf *peo; //指向联系人数组的指针
	int count;   //当前联系人数量
	int capacity; //通讯录容量
} Contact;

//加载通讯录
void LoadContact(Contact* contact);

//增加通讯录容量
void increase_capacity(Contact* contact);


//初始化通讯录
void initcontact(Contact *contact);

//显示通讯录
void ShowContact(const Contact* contact);

//查找联系人
int findname(Contact *contact,char name[]);
void search(Contact* contact);

//新建联系人
void addpho(Contact *contact);

//删除联系人
void delete(Contact *contact);

//销毁通讯录
void DestroyContact(Contact* contact); 

//存储通讯录
void SaveContact(Contact contact);

//按姓名排序
void sort(Contact contact);
//交换信息
void change(peoinf* a, peoinf* b);

