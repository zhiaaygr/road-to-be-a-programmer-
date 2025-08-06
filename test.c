#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

int main()
{
	//定义通讯录
	Contact contact;
	//初始化通讯录
	initcontact(&contact);
	int name[11];
	int input;
	while (1) {
		input = menu();//menu函数返回选择
		chose (input);//调用选择函数
	}

}
