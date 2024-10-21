#ifndef __STACK_h
#define __STACK_h
#define SIZE 30
#include"bst.h"


typedef struct{
	node *arr[SIZE];
	int top;

}Stack_Data;


void pop(Stack_Data *);
void initStack(Stack_Data *);
void push(Stack_Data *s, node*);
int isStackEmpty(Stack_Data *);
int isStackFull(Stack_Data *);
node* peekSP(Stack_Data *);

#endif
