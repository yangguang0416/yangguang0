#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//Initlist(*L);��ʼ�����������յ����Ա�
//ListEmpty(L);�ж����Ա��Ƿ�գ�
//ClearList(*L);�����Ա���գ�
//GetElem(L,i,*e);�����Ա��i��Ԫ�ط��ظ�e��

Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 ||L.length)
	{
		return ERROR;
	}
	*e=L.data(i-1);
	return OK;
}


//LocateElem(L,e);���Ա�L����ֵ��e��ȵ�Ԫ�أ��������ڱ��е�λ�ã�
//ListInsert(*L,i,e);�����Ա��i��λ�ò���Ԫ��e��
Status LlistInsert(SqList *L,int i,ElemType e)
{
	int k;
	
	if(L->length==MAXSIZE)//˳�����Ա����� 
	{
		return ERROR;
	}
	if(i<1 || i>L->length+1)//��i���ڷ�Χ��
	{
		return ERROR;
	}
	if(i<=L->length) //�������λ�ò��ڱ�β 
	{
		//�������Ԫ������ƶ�һλ 
		for(k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;//����Ԫ������
	L->length++;
	
	return OK; 
} 

//ListDelete(*L,i,*e);ɾ�����Ա�L��iλ�õ�Ԫ�ز���e������ֵ��
Status ListDelete(Sqlist *L,int i,ElemType *e)
{
	//�ж��Ƿ�Ϊ�ձ� 
	if(L->length==0)
	{
		return ERROR;
	}
	//�ж�i�Ƿ��ڱ��� 
	if(i<1 || i>L->length)
	{
		return ERROR;
	}
	//��Ҫɾ����Ԫ�ط���e�� 
	*e=L->length[i-1];
	if(i<L->length)
	{
		for(k=i;k<L->length;k++)
		{
			L->data[k-i]=L->data[k];
		}
	}
	L->length--;
} 
//ListLength(L);�������Ա�L��Ԫ�ظ����� 



void unionL(List *La,list Lb)
{
	int La_len,Lb_len,i;
	ElemType e;
	La_len=ListLength(*La);
	for(i=1;i<Lb;i++)
	{
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e))
		{
			ListInsert(La,++La_len,e);
		}
	}
 } 
int main(int argc, char *argv[]) 
{
	
	return 0;
}

