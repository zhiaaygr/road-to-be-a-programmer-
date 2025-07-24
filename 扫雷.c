#include"game。h.h"
#define _CRT_SECURE_NO_WARNINGS

//打印菜单
int menu() {
	int temp;
	printf("输入0结束游戏，1为初级模式，2为中级模式，为高级模式\n");
	scanf_s("%d", &temp);
	return temp;
}

//初级模式
int beginnermode() {
	char num[ROWS][COLS]; //存放周围雷的信息
	char ground[ROWS][COLS];//存放雷的位置 
	char show[ROWS][COLS]; //展示的数组
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
				//displaymine(ground);  用于检查
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
			printf("输入错误，请重新输入\n");
			break;

		}
		if (remain == WINNUM || check(show, ground, count)) {
			printf("你赢了\n");
			return 1;
		}

	}
}


//初始化show数组
void initshow(char show[ROWS][COLS]) {
	initshowout(show);
	initshowin(show);
}
//初始化show边界
void initshowout(char show[ROWS][COLS]) {
	for (int i = 0; i <= COL; i++) {
		show[i][0] = i + '0';
		show[0][i] = i + '0';
	}
}
//初始化show内部
void initshowin(char show[ROWS][COLS]) {
	for (int i = 1; i <= ROW; ++i) {
		for (int j = 1; j <= COL + 1; ++j) {
			show[i][j] = '#';
		}
	}
}

//初始化ground
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

//初始化num
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

//展示游戏界面
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
//展示雷
void displaymine(char ground[ROWS][COLS]) {
	for (int i = 0; i <= ROW; i++)
	{
		for (int j = 0; j <= COL; j++) {
			printf("%c ", ground[i][j]);
		}
		printf("\n");
	}
}

//选择结束或挖或标记！或标记？或取消标记
int chose(void) {
	int num;
	printf("请选择0结束游戏，1挖掘，2标记！，3标记？，4取消标记\n");
	scanf_s("%d", &num);
	return num;
}

//挖掘
int mine(char show[ROWS][COLS], char ground[ROWS][COLS], char num[ROWS][COLS],int *remain) {
	int x, y;
	printf("请输入要挖的坐标，用空格隔开\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {

		if (ground[x][y] == '*') {
			show[x][y] = '*';
			display(show);
			printf("你输了\n");
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
		printf("输入错误，请重新输入\n");
		return mine(show, ground,num,remain);
	}
}

//标记！
void excalmationmark(char show[ROWS][COLS], char ground[ROWS][COLS], int *count) {
	if (*count == WINNUM) {
		printf("已标%d个！，请重新选择\n",WINNUM);
	}
	else {
		int x, y;
		printf("请输入要标记！的坐标，用空格隔开\n");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && y > 0 && x <= ROW && y <= COL) {
			if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
			{
				show[x][y] = '!';
				(*count)++;
			}
			else printf("该位置已挖开，不能标记\n");
		}
		else {
			printf("输入错误，请重新输入\n");
		}
	}
}

//标记？
void questionmark(char show[ROWS][COLS]) {
	int x, y;
	printf("请输入要标记？坐标，用空格隔开\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {
		if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
		{
			show[x][y] = '?';
		}
		else printf("该位置已挖开，不能标记\n");
	}
	else {
		printf("输入错误，请重新输入\n");
	}
}

//取消标记
void cancelmark(char show[ROWS][COLS]) {
	int x, y;
	printf("请输入要取消标记的坐标，用空格隔开\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && y > 0 && x <= ROW && y <= COL) {
		if (show[x][y] == '#' || show[x][y] == '?' || show[x][y] == '!')
		{
			show[x][y] = '#';
		}
		else printf("该位置已挖开，不能取消标记\n");
	}
	else {
		printf("输入错误，请重新输入\n");
	}
}

//拓展雷区
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

//判断赢
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