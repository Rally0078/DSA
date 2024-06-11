#include "bst.h"
#include <stdio.h>
void inOrder(SearchTree T);
void postOrder(SearchTree T);
void preOrder(SearchTree T);

int main(void)
{
	SearchTree T = NULL;
	T = Insert(5,T);
	T = Insert(3,T);
	T = Insert(7,T);
	T = Insert(2,T);
	//int max = Max.number;
	//int min = Max.number;
	printf("BST is created");
	//singleNode(T);
	printf("\nInOrder\n");
	inOrder(T);
	printf("\nPreOrder\n");
	preOrder(T);
	printf("\nPostOrder\n");
	postOrder(T);
	T = MakeEmpty(T);
	return 0;
}