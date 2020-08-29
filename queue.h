#ifndef __QUEUE_H_
#define __QUEUE_H_



typedef struct Queue
{
	DataType data[length];
	int head;
	int tail;
}queue;


queue* CreateQueue();
void DeleteQueue(queue* qu);
int EnQueue(queue* qu, DataType data);
DataType DeQueue(queue* qu );
bool_t QueueIsEmpty(queue* qu);
bool_t QueueIsFull(queue* qu);
void ShowData_int(queue* qu);


#endif