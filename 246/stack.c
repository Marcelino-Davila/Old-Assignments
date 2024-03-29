#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100



struct stackType {
	int* data;
	int top;
};

stack createStack(){
	stack s = malloc(sizeof(struct stackType));
	s->data = malloc(MAX_SIZE*sizeof(int));
	s->top = -1;
	return s;
}

void freeStack(stack s) {
	free(s->data);
	free(s);
}

void push(stack s, int n) {
	if(isFull(s)) {
		printf("full stack\n");
		exit(EXIT_FAILURE);
	}
	s->top++;
	s->data[s->top] = n;
}

void pop(stack s) {
	if(isEmpty(s)) {
		printf("empty stack\n");
		exit(EXIT_FAILURE);
	}
	s->top--;
	}

bool isEmpty(stack s) {
	if(s->top == -1) {
		return true;
	}
	return false;
}

bool isFull(stack s) {
	if(s->top == MAX_SIZE-1) {
		return true;
	}
	return false;
}

int size(stack s) { return s->top+1; }

int getItem(stack s, int i) {
	return s->data[i]; 
}
void setItem(stack s, int i, int n) { 
if(isEmpty(s)) {
	push(s,n);
}
else{
s->data[i] = n;
}
}

int top(stack s) {
	if(isEmpty(s)) {
		printf("empty stack\n");
		exit(EXIT_FAILURE);
	}
	return s->data[s->top];
}