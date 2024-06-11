#include "bst.h"
struct TreeNode
{
	int number;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int num, SearchTree T)
{
	if(T == NULL)
		return NULL;
	if(num < T->number)
		Find(num,T->Left);
	else if(num > T->number)
		Find(num,T->Right);
	else
		return T;
}

Position FindMin(SearchTree T)
{
	if(T!=NULL)
		while(T->Left!= NULL)
			T = T->Left;
	return T;
}

Position FindMax(SearchTree T)
{
	if(T!=NULL)
		while(T->Right!=NULL)
			T = T->Right;
	return T;
}

SearchTree Insert(int num, SearchTree T)
{
	if(T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if(T == NULL)
			exit(1);
		else
		{
			T->number = num;
			T->Left = T->Right = NULL;
		}
	}
	else
		if(num < T->number)
			T->Left = Insert(num, T->Left);
	else
		if(num > T->number)
			T->Right = Insert(num, T->Right);
	return T;
}

SearchTree Delete(int num, SearchTree T)
{
	Position TmpCell;
	if(T == NULL)
		exit(1);
	else
		if(num < T->number)
			T->Left = Delete(num, T->Left);
	else
		if(num > T->number)
			T->Right = Delete(num, T->Right);
	else
		if(T->Left && T->Right)
		{
			TmpCell = FindMin(T->Right);
			T->number = TmpCell->number;
			T->Right = Delete(T->number, T->Right);
		}
	else
	{
		TmpCell = T;
		if(T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}

void inOrder(SearchTree T)
{
	if(T!=NULL)
	{
		inOrder(T->Left);
		printf("%d - ",T->number);
		inOrder(T->Right);
	}
}

void preOrder(SearchTree T)
{
	if(T!=NULL)
	{
		printf("%d - ",T->number);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}

void postOrder(SearchTree T)
{
	if(T!=NULL)
	{
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d - ",T->number);
	}
}

void singleNode(SearchTree T)
{
	printf("%d\n",T->Left->number);
	printf("%d\n",T->number);
	printf("%d\n",T->Right->number);
}