#ifndef  __QUEUEST_H_
#define  __QUEUEST_H_

/*��������ջʵ�ֶ���*/

typedef struct QueueStack
{
	stack* st1;
	stack* st2;
}queuestack;

queuestack* CreateQueueWithStack();
void DeleteQS(queuestack* qs);
int AppendTail(queuestack* qs, DataType val);
int DeleteHead(queuestack* qs);
void Qs_showdata_int(queuestack* qs);
#endif