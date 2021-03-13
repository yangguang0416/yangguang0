//��׺���ʽת��Ϊ��׺���ʽ 
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
	
	*e= *--(s->top );		//��ջ����Ԫ�ص������޸�ջ��ָ�� 
} 

int StackLen(sqStack s)		//��ǰջ������ 
{
	return (s.top - s.base);
}

int main(int argc, char *argv[]) 
{
	sqStack s;
	char c,e;
	
	InitStack(&s);
	
	printf("��������׺���ʽ����#��Ϊ������־:");
	scanf("%c",&c); 
	
	while(c!='#')
	{
		while(c>='0' && c<='9')				//���û�������������ݷ�һ�� ���������������֣� 
		{
			printf("%c",c);			//��������ֱ����� 
			scanf("%c",&c);
			if(c<'0' || c>'9')
			{
				printf(" ");
			}
		}
		if(')'== c)			//��ջ�������Ƿ��������� 
		{
			Pop(&s,&e);
			while('('!=e)		//��û�������ž͵���ջ������ 
			{
				printf("%c ",e);
				Pop(&s,&e);
			}
		}
		else if('+'==c || '-'==c)		//�ж�ջ�����ŵ����ȼ� 
		{
			if(!StackLen(s))			//�ж�ջ�Ƿ�Ϊ�� 
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
		else if('#'==c)		//���ڵڶ��ν������� 
		{
			break;
		}
		else
		{
			printf("\n�û������ʽ����\n");
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
