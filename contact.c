#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include <stdlib.h>

int menu()
{
	int input;
	printf("*****************************************\n");
	printf("*****1.显示通讯录      2.查找联系人 *****\n");
	printf("*****3.存储联系人      4.删除联系人 *****\n");
	printf("*****5.修改联系人信息  6.按姓名排序 *****\n");
	printf("*****0.退出                         *****\n");
	printf("请选择:>");
	scanf("%d", &input);
	return input;
}

//增加通讯录容量
void increase_capacity(Contact* contact) {
	assert(contact);
	if (contact->capacity == contact->count) {
		peoinf* pc = (peoinf*)realloc(contact->peo, (contact->capacity + 2) * sizeof(peoinf));
		if (pc == NULL)
		{
			printf("内存分配失败\n");
			exit(EXIT_FAILURE);
		}
		contact->peo = pc; //将指针指向新分配的内存
		contact->capacity += 2; //更新容量
	}
}

//加载通讯录
void LoadContact(Contact* contact) {
	peoinf temp = {0};
	FILE* file = fopen("contact.txt", "rb");
	if (file == NULL) {
		perror("LoadContact");
		return;
	}
	while (fread(&temp, sizeof(peoinf), 1, file) == 1) {
		if(contact->capacity==contact->count)
		increase_capacity(contact); //增加容量
		contact->peo[contact->count] = temp;
		contact->count++;
	}
	fclose(file);
}

//初始化通讯录
//静态版本
//void initcontact(Contact* contact)
//{
//	assert(contact);
//	memset(contact,0,sizeof(*contact));
//}
//动态版本
void initcontact(Contact* contact)
{
	assert(contact);
	contact->peo = (peoinf*)malloc(3 * sizeof(peoinf));
	assert(contact->peo); //确保内存分配成功
	contact->count = 0; //初始化联系人数量为0
	contact->capacity = 2; //初始容量为2
	LoadContact(contact);  //加载通讯录
}

//显示通讯录
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
	printf("%6s\t%12s\t%3s\t%5s\t%-30s\n","姓名","电话号码","年龄","性别","地址");
	for (int i = 0; i < contact->count; i++)
	{
		print(contact, i);
	}
}

//查找联系人
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
		printf("暂无联系人，请重新选择\n");
		return;
	}
	char name[11];
	printf("请输入要查找人的姓名\n");
	scanf("%s", name);
	int ret = findname(contact,name);
	if (ret != -1)
	{
		printf("%5s\t%12s\t%3s\t%5s\t%-30s\n", "姓名", "电话号码", "年龄", "性别", "地址");
		print(contact, ret);
	}
	else printf("查无此人\n");

}

//新建联系人
void addpho(Contact* contact)
{
	assert(contact);
	printf("请输入姓名:>\n");
	scanf("%s", contact->peo[contact->count].name);
	printf("请输入电话号码:>\n");
	scanf("%s", contact->peo[contact->count].phnum);
	printf("请输入年龄:>\n");
	scanf("%d", &contact->peo[contact->count].age);
	printf("请输入性别:>\n");
	scanf("%s", contact->peo[contact->count].sex);
	printf("请输入地址:>\n");
	scanf("%s", contact->peo[contact->count].adds);
	contact->count++;
}

//删除联系人
void delete(Contact* contact)
{
	assert(contact);
	int name[11];
	if (contact->count == 0)
	{
		printf("通讯录为空，无删除对象\n");
		return;
	}
	printf("请输入要删除人的名字:>\n"); 
	scanf("%s", name);
	int ret = findname(contact, name);
	if ( ret== -1) {
		printf("查无此人\n");
		return;
	}
	for (int i = ret; i < contact->count; i++)
	{
		contact->peo[i] = contact->peo[i + 1];
	}
	printf("删除成功\n");
	contact->count--;
}

//销毁通讯录
void DestroyContact(Contact* contact) {
	assert(contact);
	free(contact->peo); //释放联系人数组的内存
	contact->peo = NULL; //避免悬空指针
	contact->count = 0; //重置联系人数量
	contact->capacity = 0; //重置通讯录容量
	printf("已退出/n");
}

//存储通讯录
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

//按姓名排序
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

//交换信息
void change(peoinf* a, peoinf* b) {
	peoinf temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

