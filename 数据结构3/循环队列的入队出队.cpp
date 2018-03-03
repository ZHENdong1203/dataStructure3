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
}//����ն���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}//����г���
Status EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}//���
Status DeQueue(SqQueue &Q, QElemType &e)
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return e;
}//����
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
}//��������
int main()
{
	SqQueue Q;
	int i, e;
	InitQueue(Q);
	printf("�ڶ����в���1-10ʮ����\n");
	for (i = 1; i <= 10; i++)
	{
		EnQueue(Q, i);
	}
	printf("��ʱ������Ԫ��Ϊ;\n");
	QueueTraverse(Q);
	printf("ɾ����ͷԪ��\n");
	printf("ɾ����Ԫ��Ϊ:");
	printf("%d\n",DeQueue(Q, e));
	printf("��ʱ������Ԫ��Ϊ:\n");
	QueueTraverse(Q);
	system("pause");
	return 0;
}