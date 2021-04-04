#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkedList;

//头插法 
LinkedList headInsert(LinkedList *L){
	LinkedList p,s;
	(*L) = s = (LinkedList)malloc(sizeof(LNode));
	s->next = NULL;
	int num;
	scanf("%d", &num);
	while(num != -1){
		p = (LinkedList)malloc(sizeof(LNode));scanf("%d", &num);
		p->data = num;
		p->next = s->next;
		s->next = p;
		
	}
	return s;
}

//给第k给结点之后增加一个值x
void  add(LinkedList L, int k, int x){
	int num;
	LinkedList p,s;
	p = L->next;
	for(int i=1; i<k; i++){
		p = p->next;
	} 
	s = (LinkedList)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}

//删除第k个结点
void deleteK(LinkedList L, int k){
	LinkedList p,q;
	p = L->next;
	for(int i=1; i<k-1; i++){
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	free(q);
} 


//查询第k个结点的值 
int getK(LinkedList L, int k){
	LinkedList p = L->next;
	for(int i=1; i<k; i++){
		p = p->next;
	} 
	return p->data;
}

//输出链表所有值 
void print(LinkedList L){
	LinkedList p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//主函数 
int main(){
	LinkedList head = NULL;
	int x,k; 
//	头插	
	head = headInsert(&head);
//	增
	printf("请输入增加结点：");
	scanf("%d",&k); 
	printf("请输入增加的值："); 
	scanf("%d",&x); 
	add(head, k, x);
	print(head);
	
//	删 
	printf("请输入删除结点：");
	scanf("%d",&k); 
	deleteK(head, k);
	print(head); 
	
//  查	
	printf("请输入查找的结点：");
	scanf("%d",&k); 
	int num = getK(head, k);
	printf("%d",num);
}

