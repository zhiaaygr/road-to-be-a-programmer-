#define _CRT_SECURE_NO_WARNINGS 1
#include"后缀表达式的计算与转换.h"
//初始化
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

//判断栈是否为空
int IsEmpty(Stack* s) {
	if (s == NULL) {
		printf("栈不存在\n");
		return 1;
	}
	if (s->top == -1) {
		return 1; // 栈为空
	}
	else
	{
		return 0;
	}
}

//压栈
void Push(Stack* s, ElemType e) {
	s->top++;
	s->data[s->top] = e;
}

// 获取栈顶元素（不弹出）
ElemType GetTop(Stack* s) {
	if (IsEmpty(s)) return 0;
	return s->data[s->top];
}

//出栈
ElemType Pop(Stack* s) {
	if (IsEmpty(s)) return 0;
	return s->data[s->top--];
}

//判断元素类型
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

//计算式子的值
int Calculate(char* strsta, Stack* s) {
	if (*strsta == '\0') {
		printf("表达式为空\n");
		return -1;
	}
	int index = 0;//index用于遍历字符串
	int temp1 = 0, temp2 = 0;//temp1和temp2用于存储栈顶的两个元素
	int sum = 0;//sum用于存储多位数的值
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
			// 处理多位数
			while (GetContentType(&index,strsta) == NUM) {
				sum = sum * 10 + (strsta[index] - '0'); // 将字符转换为数字
				index++;// 移动到下一个字符
			}
			Push(s, sum);
			sum = 0; // 重置sum以处理下一个数字
			break;
		case SPACE:
			index++;
			break;
		}
	}
}

//中缀转后缀表达式
char* postfix(char* str) {
	// 分配内存并检查
	char* result = (char*)malloc(sizeof(char) * MAXSIZE);
	char* temp = (char*)malloc(sizeof(char) * MAXSIZE); // 存储运算符,与s共用top，起到栈的作用
	Stack* s = InitStack(); // 存储运算符优先级的栈

	if (result == NULL || temp == NULL || s == NULL) {
		printf("Memory allocation failed\n");
		free(result);
		free(temp);
		freeStack(s);
		return NULL;
	}
	// 初始化字符串（必须以'\0'结尾，否则strcat会出错）
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
			if (!IsEmpty(s)) Pop(s); // 弹出左括号（不加入结果）
			index++;
			break;
		case ADD: case SUB: case MUL: case DIV: case MOD:
			while (type == ADD || type == SUB || type == DIV || type == MUL || type == MOD) {//该while循环用于压入连续的运算符
				while (s->data[s->top] >= OutStack[type]) {							//该while循环用于弹出连续的可弹出运算符
					char op[2] = { temp[s->top], '\0' };
					strcat(result, op);
					Pop(s);// 弹出栈顶运算符
				}
				Push(s, InStack[type]); // 压入当前运算符
				temp[s->top] = str[index]; 
				index++;
				type = GetContentType(&index, str);
			}
			break;
		case EXP:
			// 表达式结束：弹出剩余运算符
			while (!IsEmpty(s)) {
				char op[2] = { temp[s->top], '\0' };
				strcat(result, op);
				strcat(result, " ");
				Pop(s);
			}
			// 释放资源
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

//释放栈
void freeStack(Stack* s) {
	if (s == NULL) {
		printf("栈不存在\n");
		return;
	}
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}

