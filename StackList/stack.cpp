#include "stack.h"
#include <iostream>
#include <stdlib.h>

struct Node* createStack()
{
	struct Node *head;
	head = (struct Node*)malloc(sizeof(struct Node));
	if(head == NULL)
		return NULL;
	head->next = NULL;
	return head;
}

int isEmpty(struct Node *head)
{
	if(head == NULL)	
		return -1;
	else if(head->next == NULL)
		return 0;
	else
		return 1;
}

void push(struct Node *head, int x)
{
	int status = isEmpty(head);
	if(status == -1)
	{
		std::cout<<"Stack is not initialized";
		return;
	}
	else
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		if(node == NULL)
			return;
		node->data = x;
		node->next = head->next;
		head->next = node;
	}
}
void pop(struct Node *head)
{
	int status = isEmpty(head);
	if(status == -1)
		return;
	else if(status == 1)
	{
		struct Node *node;
		node = head->next;
		head->next = head->next->next;
		free(node);
	}
	else
		std::cout<<"Stack is empty, cannot pop";
}

void peek(struct Node *head)
{
	int status = isEmpty(head);
	if(status == -1)
		return;
	else if(status == 1)
		std::cout<<head->next->data<<" ";
	else
		std::cout<<"Stack is empty!";
}

void deleteStack(struct Node *head)
{
	struct Node *node, *tmpcell;
	node = head->next;
	while(node!=NULL)
	{
		tmpcell = node->next;
		free(node);
		node=tmpcell;
	}
	
}