#include "public.h"
#include "stack.h"
#include "queue_st.h"


queuestack* CreateQueueWithStack()\
{
	queuestack* qs = NULL;
	qs = (queuestack*)malloc(sizeof(queuestack));
	if(NULL == qs)
	{
		printf("Malloc erron.\n");
		return NULL;
	}
	qs->st1 = createStack();
	qs->st2 = createStack();
	return qs;
}
void DeleteQS(queuestack* qs)
{
	Destroy(qs->st1);
	Destroy(qs->st2);
}
void Qs_showdata_int(queuestack* qs)
{
	int i = 0;


	if(!StackIsEmpty(qs->st2))
	{
		printf("st2 has:\n");
		for(i = qs->st2->top -1 ; i >= 0; --i)
		{
			printf("%d	", qs->st2->data[i]);
		}
		printf("\n");
	}
	if(!StackIsEmpty(qs->st1))
	{
		printf("st1 has:\n");
		for(i = 0 ; i < qs->st1->top; ++i)
		{
			printf("%d	", qs->st1->data[i]);
		}
		printf("\n");
	}

	printf("---------------------------\n\n");
}
int AppendTail(queuestack* qs, DataType data)
{
	if(StackIsFull(qs->st1))
	{
		printf("Queue which is completed with two stack is FULLLLL...\n");
		return -1;
	}
	push(qs->st1, data);
	return 0;
}

int DeleteHead(queuestack* qs)
{
	DataType top_val;
	if(!StackIsEmpty(qs->st2))
	{
		pop(qs->st2);
	}
	else
	{
		if(!StackIsEmpty(qs->st1))
		{
			while(!StackIsEmpty(qs->st1))
			{
				top_val = GetTop(qs->st1);
				push(qs->st2, top_val);
				pop(qs->st1);
			}
			pop(qs->st2);
		}
		else
		{
			printf("the QueusStack is empty and has no element to delete.\n");
			return -1;
		}
	}
	return 0;
}