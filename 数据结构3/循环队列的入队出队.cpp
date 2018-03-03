#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define MAXQSIZE 100
#define OVERFLOW -2
#define OK 1
typedef int Status;
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue &Q)
{
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return OK;
}//构造空队列
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}//求队列长度
Status EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}//入队
Status DeQueue(SqQueue &Q, QElemType &e)
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return e;
}//出队
void QueueTraverse(SqQueue Q)
{
	int i, k;
	k = QueueLength(Q);
	for (i = 1; i <= k; i++)
	{
		printf("%d ", Q.base[Q.front]);
		Q.front = (Q.front + 1) % MAXQSIZE;
	}
	printf("\n");
}//遍历队列
int main()
{
	SqQueue Q;
	int i, e;
	InitQueue(Q);
	printf("在队列中插入1-10十个数\n");
	for (i = 1; i <= 10; i++)
	{
		EnQueue(Q, i);
	}
	printf("此时队列中元素为;\n");
	QueueTraverse(Q);
	printf("删除队头元素\n");
	printf("删除的元素为:");
	printf("%d\n",DeQueue(Q, e));
	printf("此时队列中元素为:\n");
	QueueTraverse(Q);
	system("pause");
	return 0;
}