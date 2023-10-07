#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//����������
typedef int datatype;
typedef struct Qnode {
	datatype data;
	struct Qnode* next;
}Qnode;

//��ͷ�Ͷ�βָ��Ľṹ������
typedef struct {
	Qnode* rear;	//��βָ��
	Qnode* front;	//��ͷָ�� 
}LinkQueue;

//����һ���ն���
LinkQueue* InitQueue() {
	LinkQueue* q;
	Qnode* p;
	p = (Qnode*)malloc(sizeof(Qnode));
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	p->next = NULL;
	q->front = p;
	q->rear = p;
}

//ȡ��ͷԪ��
datatype GetHead(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("�ն���\n");
		return 0;
	}
	return Q->front->next->data;
}

//���
void EnQueue(LinkQueue* Q, datatype x) {
	Qnode* p;

	p = (Qnode*)malloc(sizeof(Qnode));
	p->data = x;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

//����
datatype DeQueue(LinkQueue* Q) {
	Qnode* p;

	if (Q->front == Q->rear) {
		printf("����Ϊ�գ��޷�ɾ����");
		return false;
	}
	p = Q->front->next;
	x = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);

	return x;
}