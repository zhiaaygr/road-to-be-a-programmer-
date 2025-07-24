#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2  //防止越界
#define COLS COL+2
#define WINNUM 10

//打印菜单
int menu();

//初级模式
int beginnermode();

//正式游戏
void game(char num[ROWS][COLS], char ground[ROWS][COLS], char show[ROWS][COLS]);

//初始化show
void initshow(char show[ROWS][COLS]);
//初始化show边界
void initshowout(char show[ROWS][COLS]);
//初始化show内部
void initshowin(char show[ROWS][COLS]);

//初始化ground
void initground(char ground[ROWS][COLS]);

//初始化num
void initnum(char num[ROWS][COLS], char ground[ROWS][COLS]);

//展示游戏界面
void display(char show[ROWS][COLS]);


//展示雷
void displaymine(char ground[ROWS][COLS]);

//选择挖或标记或不确定
int chose(void);

//挖掘
int mine(char show[ROWS][COLS], char ground[ROWS][COLS], char num[ROWS][COLS],int *remain);

//标记！
void excalmationmark(char show[ROWS][COLS], char ground[ROWS][COLS],int *count);

//标记？
void questionmark(char show[ROWS][COLS]);

//取消标记
void cancelmark(char show[ROWS][COLS]);

//拓展雷区
void expand(char show[ROWS][COLS], char num[ROWS][COLS]);
void EXPAND(char show[ROWS][COLS], char num[ROWS][COLS],int i,int j);

//判断赢
int check(char show[ROWS][COLS], char ground[ROWS][COLS], int count);