#define _CRT_SECURE_NO_WARNINGS 1
#include"��׺���ʽ�ļ�����ת��.h"
//��ʼ��
Stack* InitStack(void) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	}
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (s->data == NULL) {
		printf("Memory allocation failed\n");
		free(s);
		return NULL;
	}
	s->top = -1;
	return s;
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(Stack* s) {
	if (s == NULL) {
		printf("ջ������\n");
		return 1;
	}
	if (s->top == -1) {
		return 1; // ջΪ��
	}
	else
	{
		return 0;
	}
}

//ѹջ
void Push(Stack* s, ElemType e) {
	s->top++;
	s->data[s->top] = e;
}

// ��ȡջ��Ԫ�أ���������
ElemType GetTop(Stack* s) {
	if (IsEmpty(s)) return 0;
	return s->data[s->top];
}

//��ջ
ElemType Pop(Stack* s) {
	if (IsEmpty(s)) return 0;
	return s->data[s->top--];
}

//�ж�Ԫ������
contentType GetContentType(ElemType* index, char* strsta) {
	switch (*(strsta + *index)) {
	case '(':
		return LEFT;
	case ')':
		return RIGHT;
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '%':
		return MOD;
	case '\0':
		return EXP;
	case ' ':
		return SPACE;
	default:
		return NUM;
	}
}

//����ʽ�ӵ�ֵ
int Calculate(char* strsta, Stack* s) {
	if (*strsta == '\0') {
		printf("���ʽΪ��\n");
		return -1;
	}
	int index = 0;//index���ڱ����ַ���
	int temp1 = 0, temp2 = 0;//temp1��temp2���ڴ洢ջ��������Ԫ��
	int sum = 0;//sum���ڴ洢��λ����ֵ
	while (1) {
		switch (GetContentType(&index, strsta)) {
		case ADD:
			index++;
			temp2 = Pop(s);
			temp1 = Pop(s);
			Push(s, temp1 + temp2);
			break;
		case SUB:
			index++;
			temp2 = Pop(s);
			temp1 = Pop(s);
			Push(s, temp1 - temp2);
			break;
		case MUL:
			index++;
			temp2 = Pop(s);
			temp1 = Pop(s);
			Push(s, temp1 * temp2);
			break;
		case DIV:
			index++;
			temp2 = Pop(s);
			temp1 = Pop(s);
			Push(s, temp1 / temp2);
			break;
		case MOD:
			temp2 = Pop(s);
			temp1 = Pop(s);
			Push(s, temp1 % temp2);
			index++;
			break;
		case EXP:
			return Pop(s);
		case NUM:
			// �����λ��
			while (GetContentType(&index,strsta) == NUM) {
				sum = sum * 10 + (strsta[index] - '0'); // ���ַ�ת��Ϊ����
				index++;// �ƶ�����һ���ַ�
			}
			Push(s, sum);
			sum = 0; // ����sum�Դ�����һ������
			break;
		case SPACE:
			index++;
			break;
		}
	}
}

//��׺ת��׺���ʽ
char* postfix(char* str) {
	// �����ڴ沢���
	char* result = (char*)malloc(sizeof(char) * MAXSIZE);
	char* temp = (char*)malloc(sizeof(char) * MAXSIZE); // �洢�����,��s����top����ջ������
	Stack* s = InitStack(); // �洢��������ȼ���ջ

	if (result == NULL || temp == NULL || s == NULL) {
		printf("Memory allocation failed\n");
		free(result);
		free(temp);
		freeStack(s);
		return NULL;
	}
	// ��ʼ���ַ�����������'\0'��β������strcat�����
	result[0] = '\0';
	temp[0] = '\0';
	int index = 0;
	contentType type;
	while (1) {
		switch (type= GetContentType(&index, str)) {
		case LEFT:
			Push(s, InStack[LEFT]);
			temp[s->top] = str[index];
			index++;
			break;
		case RIGHT:
			while (!IsEmpty(s) && temp[s->top] != '(') {
				char op[2] = { temp[s->top], '\0' };
				strcat(result, op);
				Pop(s);
			}
			if (!IsEmpty(s)) Pop(s); // ���������ţ�����������
			index++;
			break;
		case ADD: case SUB: case MUL: case DIV: case MOD:
			while (type == ADD || type == SUB || type == DIV || type == MUL || type == MOD) {//��whileѭ������ѹ�������������
				while (s->data[s->top] >= OutStack[type]) {							//��whileѭ�����ڵ��������Ŀɵ��������
					char op[2] = { temp[s->top], '\0' };
					strcat(result, op);
					Pop(s);// ����ջ�������
				}
				Push(s, InStack[type]); // ѹ�뵱ǰ�����
				temp[s->top] = str[index]; 
				index++;
				type = GetContentType(&index, str);
			}
			break;
		case EXP:
			// ���ʽ����������ʣ�������
			while (!IsEmpty(s)) {
				char op[2] = { temp[s->top], '\0' };
				strcat(result, op);
				strcat(result, " ");
				Pop(s);
			}
			// �ͷ���Դ
			freeStack(s);
			free(temp);
			return result;
		case NUM:
			while(str[index]>='0'&&str[index]<='9'){
				char op[2] = { str[index], '\0'};
				strcat(result, op);
				index++;
			}
			strcat(result," ");
			break;

		}
	}
}

//�ͷ�ջ
void freeStack(Stack* s) {
	if (s == NULL) {
		printf("ջ������\n");
		return;
	}
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}

