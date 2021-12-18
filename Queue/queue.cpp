#include <iostream>
#include <stdlib.h>


class Queue
{
	int *array;
	int front,back,capacity;
	public:
		Queue(int size);
		~Queue();
		bool isFull();
		bool isEmpty();
		int getFront();
		void enqueue(int x);
		void dequeue();
		friend std::ostream& operator<<(std::ostream& out, Queue Q);
		
};

Queue::Queue(int size)
{
	try{
		array = new int[size];
	}
	catch(std::bad_alloc&)
	{
		std::cerr<<"new failed!";
		exit(1);
	}
	front = -1;
	back = -1;
	capacity = size;
}

Queue::~Queue()
{
	delete[] array;
}

bool Queue::isFull()
{
	return (front == 0 && back == capacity -1);
}

bool Queue::isEmpty()
{
	return (front == -1);
}

int Queue::getFront()
{
	if(isEmpty())
	{	
		std::cout<<"Empty Queue";
		exit(1);
	}
	else
		return array[front];
}

void Queue::enqueue(int x)
{
	if(isFull())
		std::cout<<"Queue is full";
	else
	{	if(front == -1)
			front = 0;
		back++;
		array[back] = x;
	}
}

void Queue::dequeue()
{
	if(isEmpty())
		std::cout<<"Queue is empty";
	else
	{
		if(front>=back)
		{
			front = -1;
			back = -1;
		}
		else
			front++;
	}
}

std::ostream& operator<<(std::ostream& out, Queue Q)
{
	for(int i = Q.front; i <(Q.back+1);i++)
		out<<Q.array[i]<<" ";
	return out;
}
int main(void)
{
	Queue *Q = new Queue(10);
	std::cout<<"Queue created";
	std::cout<<"\nEnqueue 1,3,5,7,10";
	int arr[] = {1,3,5,7,10};
	for(int x:arr)
		Q->enqueue(x);
	std::cout<<"\nQueue after enqueueing : \n";
	std::cout<<*Q;
	std::cout<<"\nDequeueing first 3 values: ";
	Q->dequeue();
	Q->dequeue();
	Q->dequeue();
	std::cout<<"\nQueue after dequeueing :\n";
	std::cout<<*Q;
	Q->dequeue();
	Q->dequeue();
	std::cout<<"\nQueue after dequeueing :\n";
	delete Q;
	std::cout<<"\nQueue deleted";
	return 0;
}
