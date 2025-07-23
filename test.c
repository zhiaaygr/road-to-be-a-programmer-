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
		input = menu();
		switch (input)
		{
			//显示通讯录
		case 1:
			ShowContact(&contact);
			break;
			//查找联系人
		case 2:
			search(&contact);
			break;
			//新建联系人
		case 3:
			addpho(&contact);
			increase_capacity(&contact);
			break;
			//删除联系人
		case 4:
			delete(&contact);
			break;
			//修改联系人信息
		case 5:
			printf("请输入要修改人的名字:>\n");
			delete(&contact);
			addpho(&contact);
			break;
			//按姓名排序
		case 6:
			sort(contact);
			ShowContact(&contact);
			break;
			//退出
		case 0:
			SaveContact(contact);
			DestroyContact(&contact);
			return 0;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	}
}