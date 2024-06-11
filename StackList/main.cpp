#include <iostream>
#include "stack.h"
int main(void)
{
	struct Node *stack;
	stack = createStack();
	std::cout<<"Pushing 3,5,8,9:\n";
	push(stack,3);
	peek(stack);
	push(stack,5);
	peek(stack);
	push(stack,8);
	peek(stack);
	push(stack,9);
	peek(stack);
	std::cout<<"\nPopping stack four times\n";
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	peek(stack);
	std::cout<<"\nDeleting stack";
	deleteStack(stack);
	std::cout<<"\nStack deleted";
	return 0;
}
