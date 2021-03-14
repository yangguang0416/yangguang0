//链表实现队列（列式存储结构） 
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
 
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
} QNode,*QueuePtr;


typedef struct
{
	QueuePtr front,rear;		//对头，尾指针 
}LinkQueue;

InsertQueue(LinkQueue *q,ElemType e)		//入队列操作 
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(p==NULL)
	{
		exit(0);
	}
	
	p->data=e;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

DeleteQueue(LinkQueue *q,ElemType *e)  //删除队列中元素 
{
	QueuePtr p;
	if(q->front==q->rear)  		//判断书否为空队列 
	{
		return;
	}
	p=q->front->next;
	*e=p->data;
	q->front->next=p->next;
	if(q->rear==p)				//只有一个元素的情况，全部指向头结点 
	{
		q->rear=q->front;
	}
	free(p);
}
DestoryQueue(LinkQueue *q)		//销毁一个队列 
{
	while(q->front)		//利用while循环迭代 
	{
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
}

int main(int argc, char *argv[]) 
{
	return 0;
}
