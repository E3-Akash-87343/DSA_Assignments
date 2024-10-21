#include "stack.h"


void initStack(Stack_Data *s){
	s->top = -1;
}


int isStackEmpty(Stack_Data *s){
	return s->top == -1;
}


int isStackFull(Stack_Data *s){
	return s->top == SIZE-1;	
}

void push(Stack_Data *s, node* data){
	s->top++;
	s->arr[s->top] = data;
}


void pop(Stack_Data *s){
	s->arr[s->top] = 0;
	s->top--;
}


node* peekSP(Stack_Data *s){
	return s->arr[s->top];
}

