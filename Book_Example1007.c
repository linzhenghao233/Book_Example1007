#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义结点类型
typedef int datatype;
typedef struct Qnode {
	datatype data;
	struct Qnode* next;
}Qnode;

//队头和队尾指针的结构体类型
typedef struct {
	Qnode* rear;	//队尾指针
	Qnode* front;	//队头指针 
}LinkQueue;

//构造一个空队列
LinkQueue* InitQueue() {
	LinkQueue* q;
	Qnode* p;
	p = (Qnode*)malloc(sizeof(Qnode));
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	p->next = NULL;
	q->front = p;
	q->rear = p;
}

//取队头元素
datatype GetHead(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("空队列\n");
		return 0;
	}
	return Q->front->next->data;
}

//入队
void EnQueue(LinkQueue* Q, datatype x) {
	Qnode* p;

	p = (Qnode*)malloc(sizeof(Qnode));
	p->data = x;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

//出队
datatype DeQueue(LinkQueue* Q) {
	Qnode* p;

	if (Q->front == Q->rear) {
		printf("队列为空，无法删除！");
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