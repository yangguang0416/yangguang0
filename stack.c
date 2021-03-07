//����ջ���ص㽫������ת��Ϊʮ���� 
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

void InitStack(sqStack *s)		//ջ�ĳ�ʼ�� 
{
	s->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!s->base)		//����ռ�ʧ�� 
	{
		exit(0);
	}

	s->top=s->base;		//ջ��ջ����ͬ 
	s->stackSize=STACK_INIT_SIZE;			//��ʼ�������� 
}

void Push(sqStack *s,ElemType e)		//ѹջ�Ĳ��� 
{
	if(s->top - s->base >=s->stackSize)		//��ֹջ������� 
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

void Pop(sqStack *s,ElemType *e)		//��ջ�Ĳ��� 
{
	if( s->top == s->base)		//�ж��Ƿ�Ϊ��ջ����ֹ����� 
	{
		return;
	}
	
	*e= *--(s->top );	
} 

int StackLen(sqStack s)		//��ǰջ������ 
{
	return (s.top - s.base);
}

int main() 
{
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	
	InitStack(&s); 
	
	printf("�������������������#���ű�ʾ����!\n");
	scanf("%c",&c);		//�ַ�����һ��һ����ջ
	while(c!='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	
	getchar();		//���س��ӻ�����ȥ�� 
	
	len=StackLen(s); 
	printf("ջ�ĵ�ǰ�����ǣ�%d\n",len);
	
	for(i=0;i<len;i++)
	{
		Pop(&s,&c);
		sum=sum + (c-48) * pow(2,i);
	}
	
	printf("ת��Ϊʮ�������ǣ�%d\n",sum);
	return 0;
}
