#include"public.h"
#include"queue.h"



queue* CreateQueue()
{
	queue *qu = NULL;
	
	qu = (queue*)malloc(sizeof(queue));
	if(NULL == qu)
	{
		return NULL;
	}
	memset(qu->data, 0x0, sizeof(DataType)*length);
	qu->head  = 0;
	qu->tail = 0;
	
	return qu;
}

void DeleteQueue(queue* qu)
{
	if(NULL != qu)
	{
		free(qu);
		qu = NULL;
	}
}
int EnQueue(queue* qu, DataType data)
{
	if(QueueIsFull(qu))
	{
		printf("Queue is Full..when enqueue....\n");
		return -1;
	}

	if(qu->tail  > qu->head)
	{
		if(qu->tail + 1 == length)
		{		
			qu->data[qu->tail] = data;
			qu->tail = 0;
		}
		else
		{
			qu->data[qu->tail++]  = data;
		}
	}
	else
	{
		qu->data[qu->tail++] = data; 
	}

	return 0;
}
DataType DeQueue(queue* qu )
{
	DataType p = (DataType)NULL;

	if(QueueIsEmpty(qu))
	{
		printf("Queue is Empty when dequeue.\n");
		return (DataType)NULL;
	}

	p = qu->data[qu->head];

	if(qu->head < qu->tail)
	{
		++qu->head;
	}
	else
	{
		if(qu->head + 1 == length)
		{
			qu->head = 0;
		}
		else
		{
			++qu->head;
		}
	}
	return p;
}
bool_t QueueIsEmpty(queue* qu)
{
	if(qu->tail == qu->head)
	{
		return 1;
	}
	return 0;
}
bool_t QueueIsFull(queue* qu)
{
	if(( (qu->tail + 1) == qu->head ) ||((qu->head == 0) && (qu->tail+1 == length)))
	{
		return 1;
	}
	return 0;
}
void ShowData_int(queue* qu)
{
	int i = 0;
	if(QueueIsEmpty(qu))
	{
		printf("Queue has NULL.\n");
		return;
	}
	if(qu->head < qu->tail)
	{
		for(i = qu->head; i < qu->tail; ++i)
		{
			printf("%d	",qu->data[i]);
		}
		printf("\n");
	}
	if(qu->head > qu->tail)
	{
		for(i = qu->head; i < length;++i)
		{
			printf("%d	",qu->data[i]);
		}
		for(i = 0; i< qu->tail; ++i)
		{
			printf("%d	",qu->data[i]);
		}
	}
		printf("--------------------------------------------------\n\n");
}