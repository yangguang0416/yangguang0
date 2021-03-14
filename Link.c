//����ʵ�ֶ��У���ʽ�洢�ṹ�� 
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
	QueuePtr front,rear;		//��ͷ��βָ�� 
}LinkQueue;

InsertQueue(LinkQueue *q,ElemType e)		//����в��� 
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

DeleteQueue(LinkQueue *q,ElemType *e)  //ɾ��������Ԫ�� 
{
	QueuePtr p;
	if(q->front==q->rear)  		//�ж����Ϊ�ն��� 
	{
		return;
	}
	p=q->front->next;
	*e=p->data;
	q->front->next=p->next;
	if(q->rear==p)				//ֻ��һ��Ԫ�ص������ȫ��ָ��ͷ��� 
	{
		q->rear=q->front;
	}
	free(p);
}
DestoryQueue(LinkQueue *q)		//����һ������ 
{
	while(q->front)		//����whileѭ������ 
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
