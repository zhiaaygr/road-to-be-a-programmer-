#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2  //��ֹԽ��
#define COLS COL+2
#define WINNUM 10

//��ӡ�˵�
int menu();

//����ģʽ
int beginnermode();

//��ʽ��Ϸ
void game(char num[ROWS][COLS], char ground[ROWS][COLS], char show[ROWS][COLS]);

//��ʼ��show
void initshow(char show[ROWS][COLS]);
//��ʼ��show�߽�
void initshowout(char show[ROWS][COLS]);
//��ʼ��show�ڲ�
void initshowin(char show[ROWS][COLS]);

//��ʼ��ground
void initground(char ground[ROWS][COLS]);

//��ʼ��num
void initnum(char num[ROWS][COLS], char ground[ROWS][COLS]);

//չʾ��Ϸ����
void display(char show[ROWS][COLS]);


//չʾ��
void displaymine(char ground[ROWS][COLS]);

//ѡ���ڻ��ǻ�ȷ��
int chose(void);

//�ھ�
int mine(char show[ROWS][COLS], char ground[ROWS][COLS], char num[ROWS][COLS],int *remain);

//��ǣ�
void excalmationmark(char show[ROWS][COLS], char ground[ROWS][COLS],int *count);

//��ǣ�
void questionmark(char show[ROWS][COLS]);

//ȡ�����
void cancelmark(char show[ROWS][COLS]);

//��չ����
void expand(char show[ROWS][COLS], char num[ROWS][COLS]);
void EXPAND(char show[ROWS][COLS], char num[ROWS][COLS],int i,int j);

//�ж�Ӯ
int check(char show[ROWS][COLS], char ground[ROWS][COLS], int count);