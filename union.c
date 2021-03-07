#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//Initlist(*L);初始化操作建立空的线性表；
//ListEmpty(L);判断线性表是否空；
//ClearList(*L);将线性表清空；
//GetElem(L,i,*e);将线性表第i个元素返回给e；

Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 ||L.length)
	{
		return ERROR;
	}
	*e=L.data(i-1);
	return OK;
}


//LocateElem(L,e);线性表L中找值与e相等的元素，返回其在表中的位置；
//ListInsert(*L,i,e);在线性表第i个位置插入元素e；
Status LlistInsert(SqList *L,int i,ElemType e)
{
	int k;
	
	if(L->length==MAXSIZE)//顺序线性表已满 
	{
		return ERROR;
	}
	if(i<1 || i>L->length+1)//当i不在范围内
	{
		return ERROR;
	}
	if(i<=L->length) //若插入的位置不在表尾 
	{
		//将插入的元素向后移动一位 
		for(k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;//将新元素输入
	L->length++;
	
	return OK; 
} 

//ListDelete(*L,i,*e);删除线性表L第i位置的元素并用e返回其值；
Status ListDelete(Sqlist *L,int i,ElemType *e)
{
	//判断是否为空表 
	if(L->length==0)
	{
		return ERROR;
	}
	//判断i是否在表中 
	if(i<1 || i>L->length)
	{
		return ERROR;
	}
	//将要删除的元素放入e中 
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
//ListLength(L);返回线性表L的元素个数； 



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

