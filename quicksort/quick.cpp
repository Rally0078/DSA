#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void swap(int*,int*);
void quicksort(int[],int,int);
int partition(int[],int,int);
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int A[], int low, int high)
{
	if (low>=high)
		return;
	int p = partition(A,low, high);
	quicksort(A, low, p-1);
	quicksort(A, p+1, high);;
}

int partition(int A[], int low, int high)
{
	int pivot = A[high];
	
	int i = low - 1;
	for(int j = low; j < high; j++)
	{
		if(A[j] <= pivot)
		{
			i = i+1;
			swap(&A[i],&A[j]);
		}
	}
	i = i+1;
	swap(&A[i],&A[high]);
	return i;
}
int main(void)
{
	int X[] = {1,-6, 10, 4, 5, 7, 3, 2};
	int size = sizeof(X)/sizeof(X[0]);
	for(int i: X)
		cout<<i<<" ";
	quicksort(X,0,size-1);
	cout<<endl;
	for(int i: X)
		cout<<i<<" ";
	return 0;
}