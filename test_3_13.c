//中缀表达式转换为后缀表达式 
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)		//栈的初始化 
{
	s->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!s->base)		//分配空间失败 
	{
		exit(0);
	}

	s->top=s->base;		//栈顶栈底相同 
	s->stackSize=STACK_INIT_SIZE;			//初始化的容量 
}

void Push(sqStack *s,ElemType e)		//压栈的操作 
{
	if(s->top - s->base >=s->stackSize)		//防止栈满后溢出 
	{
		s->base=(ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT)*sizeof(ElemType));
		if(!s->base)
		{
			exit(0);
		}
	}
	
	*(s->top)=e;
	s->top++;
}

void Pop(sqStack *s,ElemType *e)		//出栈的操作 
{
	if( s->top == s->base)		//判断是否为空栈，防止下溢出 
	{
		return;
	}
	
	*e= *--(s->top );		//将栈顶的元素弹出并修改栈顶指针 
} 

int StackLen(sqStack s)		//求当前栈的容量 
{
	return (s.top - s.base);
}

int main(int argc, char *argv[]) 
{
	sqStack s;
	char c,e;
	
	InitStack(&s);
	
	printf("请输入中缀表达式，以#作为结束标志:");
	scanf("%c",&c); 
	
	while(c!='#')
	{
		while(c>='0' && c<='9')				//对用户连续输入的数据放一起 （处理连续的数字） 
		{
			printf("%c",c);			//若是数字直接输出 
			scanf("%c",&c);
			if(c<'0' || c>'9')
			{
				printf(" ");
			}
		}
		if(')'== c)			//弹栈检验里是否有左括号 
		{
			Pop(&s,&e);
			while('('!=e)		//若没有左括号就弹出栈内数据 
			{
				printf("%c ",e);
				Pop(&s,&e);
			}
		}
		else if('+'==c || '-'==c)		//判断栈顶符号的优先级 
		{
			if(!StackLen(s))			//判断栈是否为空 
			{
				Push(&s,c);
			}
			else
			{
				do
				{
					Pop(&s,&e);
					if('('==e)
					{
						Push(&s,e);
					}
					else
					{
						printf("%c ",e);
					}
				}while(StackLen(s) && '('!=e);
				Push(&s,c);
			}
		}
		else if('*'==c || '/'==c || '('==c)
		{
			Push(&s,c);
		}
		else if('#'==c)		//用于第二次接收数据 
		{
			break;
		}
		else
		{
			printf("\n用户输入格式错误！\n");
			return -1; 
		}
		scanf("%c",&c);
		
	} 
	while(StackLen(s))
	{
		Pop(&s,&e);
		printf("%c ",e);
	}
	return 0;
}
