#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkedList;

//ͷ�巨 
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

//����k�����֮������һ��ֵx
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

//ɾ����k�����
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


//��ѯ��k������ֵ 
int getK(LinkedList L, int k){
	LinkedList p = L->next;
	for(int i=1; i<k; i++){
		p = p->next;
	} 
	return p->data;
}

//�����������ֵ 
void print(LinkedList L){
	LinkedList p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//������ 
int main(){
	LinkedList head = NULL;
	int x,k; 
//	ͷ��	
	head = headInsert(&head);
//	��
	printf("���������ӽ�㣺");
	scanf("%d",&k); 
	printf("���������ӵ�ֵ��"); 
	scanf("%d",&x); 
	add(head, k, x);
	print(head);
	
//	ɾ 
	printf("������ɾ����㣺");
	scanf("%d",&k); 
	deleteK(head, k);
	print(head); 
	
//  ��	
	printf("��������ҵĽ�㣺");
	scanf("%d",&k); 
	int num = getK(head, k);
	printf("%d",num);
}

