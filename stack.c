//利用栈的特点将二进制转化为十进制 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	
	*e= *--(s->top );	
} 

int StackLen(sqStack s)		//求当前栈的容量 
{
	return (s.top - s.base);
}

int main() 
{
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	
	InitStack(&s); 
	
	printf("请输入二进制数，输入#符号表示结束!\n");
	scanf("%c",&c);		//字符输入一个一个进栈
	while(c!='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	
	getchar();		//将回车从缓冲区去掉 
	
	len=StackLen(s); 
	printf("栈的当前容量是：%d\n",len);
	
	for(i=0;i<len;i++)
	{
		Pop(&s,&c);
		sum=sum + (c-48) * pow(2,i);
	}
	
	printf("转化为十进制数是：%d\n",sum);
	return 0;
}
