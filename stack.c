
#include"public.h"
#include "stack.h"



stack* createStack()
{
	stack *st = (stack*)malloc(sizeof(stack));
	if(NULL == st)
	{
		return NULL;
	}
	st->base = st->top = 0;
	memset(st->data, 0x0, sizeof(DataType)*length);
	
    return st;
}


void Destroy(stack* st)
{
	if(NULL != st)
	{
		free(st);
	}
}

bool_t StackIsEmpty(stack* st)
{
	if(st->top == st->base || st->top == 0)
	{
		return 1;
	}
	return 0;
}
bool_t StackIsFull(stack* st)
{
	if(st->top == length)
	{
		return 1;
	}
	return 0;
}
DataType GetTop(stack* st)
{
	DataType ret = (DataType)-1;
	if(!StackIsEmpty(st))
	{
		return st->data[st->top -1];
	}
	else
	{
//		printf("Stack is empty,so has no top.\n");
		return ret;
	}
}
int push(stack* st , DataType data)
{
	if(st->top +1 > length)
	{
		printf("Stack is Full!!!\n");
		return -1;
	}
	
	st->data[st->top++] = data;
	return 0;
}

int pop(stack *st)
{
	if( st->top <= 0)
	{
		return -1;
	}
	--st->top;
	return 0;
}

void showData(stack* st)
{
	int i = st->base;
	
	for(; i < st->top; ++i)
	{
		printf("%d	", st->data[i]);
	}
	printf("\n");
}
void showData_char(stack* st)
{
	int i = st->base;
	
	for(; i < st->top; ++i)
	{
		printf("%c  ", st->data[i]);
	}
	printf("\n");
}
void showData_float(stack* st)
{
	int i = st->base;
	
	for(; i < st->top; ++i)
	{
		printf("%f  ", st->data[i]);
	}
	printf("\n");
}
void showData_from_base_to_top_bstnode(stack* st, int n)
{
	int i = st->base;
	printf("Show Path (%d):", n);
	for(; i < st->top; ++i)
	{
		if(NULL == st->data[i] )
		{
			printf("error print bstNode!\n\n");
			return;
		}
		printf("%d  ", st->data[i]->data);
	}
	printf("\n\n");
}