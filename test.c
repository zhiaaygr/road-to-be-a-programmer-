#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

int main()
{
	//����ͨѶ¼
	Contact contact;
	//��ʼ��ͨѶ¼
	initcontact(&contact);
	int name[11];
	int input;
	while (1) {
		input = menu();
		switch (input)
		{
			//��ʾͨѶ¼
		case 1:
			ShowContact(&contact);
			break;
			//������ϵ��
		case 2:
			search(&contact);
			break;
			//�½���ϵ��
		case 3:
			addpho(&contact);
			increase_capacity(&contact);
			break;
			//ɾ����ϵ��
		case 4:
			delete(&contact);
			break;
			//�޸���ϵ����Ϣ
		case 5:
			printf("������Ҫ�޸��˵�����:>\n");
			delete(&contact);
			addpho(&contact);
			break;
			//����������
		case 6:
			sort(contact);
			ShowContact(&contact);
			break;
			//�˳�
		case 0:
			SaveContact(contact);
			DestroyContact(&contact);
			return 0;
		default:
			printf("�����������������");
			break;
		}
	}
}