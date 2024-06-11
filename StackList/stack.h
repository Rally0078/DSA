#ifndef STACK_H
#define STACK_H
struct Node
{
	int data;
	struct Node *next;
};

struct Node* createStack();
void deleteStack(struct Node*);
int isEmpty(struct Node*);
void push(struct Node*, int);
void pop(struct Node*);
void peek(struct Node*);
#endif

