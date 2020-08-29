#ifndef __STACK_H_
#define __STACK_H_




typedef struct Stack
{
	DataType  data[length];
    int base;
    int top;
}stack;

stack* createStack();
void Destroy(stack* st);
bool_t StackIsEmpty(stack* st);
bool_t StackIsFull(stack* st);
int push(stack* st , DataType data);
int pop(stack *st);
DataType GetTop(stack* st);
void showData(stack* st);
void showData_char(stack* st);
void showData_float(stack* st);
void showData_from_base_to_top_bstnode(stack* st);

#endif