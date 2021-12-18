#include <iostream>
#include <stdlib.h>


class Stack
{
	int *array;
	int top; 
	int capacity;
	public:
		Stack(int size);
		~Stack();
		bool isFull();
		bool isEmpty();
		int getTop();
		void push(int x);
		void pop();
		friend std::ostream& operator<<(std::ostream& out, Stack S);
		
};

Stack::Stack(int size)
{
	try
	{
			array = new int[size];
	}
	catch(std::bad_alloc&)
	{
		std::cerr<<"new failed!";
		exit(1);
	}
	capacity = size;
	top = -1;
}

Stack::~Stack()
{
	delete[] array;
}
bool Stack::isFull()
{
	return (top == capacity -1);
}

bool Stack::isEmpty()
{
	return (top == -1);
}

void Stack::push(int x)
{
	if(isFull())
		exit(1);
	top++;
	array[top] = x;
}

void Stack::pop()
{
	if(isEmpty())
		exit(1);
	--top;
}

int Stack::getTop()
{
	return top;
}

std::ostream& operator<<(std::ostream& out, Stack S)
{
	for(int i = 0; i <(S.top+1); i++)
	{
		out<<S.array[i]<<" ";
	}
	return out;
}


int main(void)
{
	Stack *S = new Stack(10);
	std::cout<<"Stack created";
	std::cout<<"\nPushing 1,3,5,7,10";
	int arr[] = {1,3,5,7,10};
	for(int x:arr)
		S->push(x);
	std::cout<<"\nStack after pushing : "<<S->getTop()<<"\n";
	std::cout<<*S;
	std::cout<<"\nPopping the top 3 values: "<<S->getTop();
	S->pop();
	S->pop();
	S->pop();
	std::cout<<"\nStack after popping : "<<S->getTop()<<"\n";
	std::cout<<*S;
	delete S;
	std::cout<<"\nStack deleted";
	return 0;
}