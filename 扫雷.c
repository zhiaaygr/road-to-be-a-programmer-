#include"game��h.h"
#define _CRT_SECURE_NO_WARNINGS

//��ӡ�˵�
int menu() {
	int temp;
	printf("����0������Ϸ��1Ϊ����ģʽ��2Ϊ�м�ģʽ��Ϊ�߼�ģʽ\n");
	scanf_s("%d", &temp);
	return temp;
}

//����ģʽ
int beginnermode() {
	char num[ROWS][COLS]; //�����Χ�׵���Ϣ
	char ground[ROWS][COLS];//����׵�λ�� 
	char show[ROWS][COLS]; //չʾ������
	initshow(show);
	initground(ground);
	initshowout(ground);
	initnum(num,ground);
	display(show);
	game(num, ground, show);
}

//
void game(char num[ROWS][COLS], char ground[ROWS][COLS], char show[ROWS][COLS]){
	int temp, count = 0, remain = ROW * COL;
	while (1) {
		temp = chose();
		switch (temp)
		{
		case 0:
			return 1;
		case 1:
			if (mine(show, ground, num, &remain)) {
				display(show);
				//displaymine(ground);  ���ڼ��
				return 1;
			}
			display(show);
			displaymine(ground);
			break;
		case 2:
			excalmationmark(show, ground, &count);
			display(show);
			//displaymine(ground);
			break;
		case 3:
			questionmark(show);
			display(show);
			//displaymine(ground);
			break;
		case 4:
			cancelmark(show);
			display(show);
			break;
		default:
			printf("�����������������\n");
			break;

		}
		if (remain == WINNUM || check(show, ground, count)) {
			printf("��Ӯ��\n");
			return 1;
		}

	}
}


//��ʼ��show����
void initshow(char show[ROWS][COLS]) {
	initshowout(show);
	initshowin(show);
}
//��ʼ��show�߽�
void initshowout(char show[ROWS][COLS]) {
	for (int i = 0; i <= COL; i++) {
		show[i][0] = i + '0';
		show[0][i] = i + '0';
	}
}
//��ʼ��show�ڲ�
void initshowin(char show[ROWS][COLS]) {
	for (int i = 1; i <= ROW; ++i) {
		for (int j = 1; j <= COL + 1; ++j) {
			show[i][j] = '#';
		}
	}
}

//��ʼ��ground
void initground(char ground[ROWS][COLS]) {
	int count = 0, x, y;
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			ground[i][j] = ' ';
		}
	}
	for (; count < WINNUM;) {
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (ground[x][y] == ' ') {
				ground[x][y] = '*';
				++count;
			}
	}
}

//��ʼ��num
void initnum(char num[ROWS][COLS], char ground[ROWS][COLS]) {
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++) {
			num[i][j] = '0';
			for (int I = i - 1; I <= i + 1; I++)
			{
				for (int J = j - 1; J <= j + 1; J++) {
					if (ground[I][J] == '*') num[i][j] += 1;
				}
			}
		}
	}
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++) {
			if (num[i][j] == '0') num[i][j] = ' ';
		}
	}
}

//չʾ��Ϸ����
void display(char show[ROWS][COLS]) {
	for (int i = 0; i <= ROW; i++)
	{
		for (int j = 0; j <= COL; j++) {
			if (show[i][j] == '0') show[i][j] = ' ';
		}
	}
		for (int i = 0; i <= ROW; i++)
		{
			for (int j = 0; j <= COL; j++) {
				printf("%c ", show[i][j]);
			}
			printf("\n");
		}
}
//չʾ��
void displaymine(char ground[ROWS][COLS]) {
	for (int i = 0; i <= ROW; i++)
	{
		for (int j = 0; j <= COL; j++) {
			printf("%c ", ground[i][j]);
		}
		printf("\n");
	}
}

//ѡ��������ڻ��ǣ����ǣ���ȡ�����
int chose(void) {
	int num;
	printf("��ѡ��0������Ϸ��1�ھ�2��ǣ���3��ǣ���4ȡ�����\n");
	scanf_s("%d", &num);
	return num;
}

//�ھ�
int mine(char show[ROWS][COLS], char ground[ROWS][COLS], char num[ROWS][COLS],int *remain) {
	int x, y;
	printf("������Ҫ�ڵ����꣬�ÿո����\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {

		if (ground[x][y] == '*') {
			show[x][y] = '*';
			display(show);
			printf("������\n");
			return 1;
		}
		else {
			show[x][y] = num[x][y];
			expand(show, num);
			initshowout(show);
			(*remain)--;
		}
		return 0;
	}
	else {
		printf("�����������������\n");
		return mine(show, ground,num,remain);
	}
}

//��ǣ�
void excalmationmark(char show[ROWS][COLS], char ground[ROWS][COLS], int *count) {
	if (*count == WINNUM) {
		printf("�ѱ�%d������������ѡ��\n",WINNUM);
	}
	else {
		int x, y;
		printf("������Ҫ��ǣ������꣬�ÿո����\n");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && y > 0 && x <= ROW && y <= COL) {
			if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
			{
				show[x][y] = '!';
				(*count)++;
			}
			else printf("��λ�����ڿ������ܱ��\n");
		}
		else {
			printf("�����������������\n");
		}
	}
}

//��ǣ�
void questionmark(char show[ROWS][COLS]) {
	int x, y;
	printf("������Ҫ��ǣ����꣬�ÿո����\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {
		if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
		{
			show[x][y] = '?';
		}
		else printf("��λ�����ڿ������ܱ��\n");
	}
	else {
		printf("�����������������\n");
	}
}

//ȡ�����
void cancelmark(char show[ROWS][COLS]) {
	int x, y;
	printf("������Ҫȡ����ǵ����꣬�ÿո����\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {
		if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
		{
			show[x][y] = '#';
		}
		else printf("��λ�����ڿ�������ȡ�����\n");
	}
	else {
		printf("�����������������\n");
	}
}

//��չ����
void expand(char show[ROWS][COLS], char num[ROWS][COLS]) {
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++)
		{
			if (show[i][j] == ' ') {
				for (int I = i - 1; I <= i + 1 && I<ROW + 1; I++)
				{
					for (int J = j - 1; J <= j + 1&&J<COL+1; J++) {
						 show[I][J] = num[I][J];
						 if (show[I][J] == ' ') EXPAND(show, num,I,J);
					}
				}
			}
		}
	}
}
void EXPAND(char show[ROWS][COLS], char num[ROWS][COLS], int i, int j) {
	for (int I = i - 1; I <= i + 1 && I < ROW + 1; I++)
	{
		for (int J = j - 1; J <= j + 1 && J < COL + 1; J++) {
			show[I][J] = num[I][J];
		}
	}
}

//�ж�Ӯ
int check(char show[ROWS][COLS], char ground[ROWS][COLS], int count) {
	if (count == WINNUM) {
		for (int i = 1; i <= ROW; i++) {
			for (int j = 0; j <= COL; j++)
			{
				if (show[i][j] == '!') {
					if (ground[i][j] != '*') {
						return 0;
					}
				}
			}
		}
		return 0;
	}
	else return 1;
}