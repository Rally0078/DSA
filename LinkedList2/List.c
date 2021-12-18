#include "List.h"
#include <stdlib.h>
#include <stdio.h>

List new_List(List L)
{
	
	L = malloc(sizeof(struct Node));
	if(L == NULL)
	{
		fprintf(stderr,"new_List malloc failed");
		exit(1); 
	}
	
	if(!isEmpty(L))
	{
		L->next = NULL;
	}
	
	return L;
}

void DeleteList(List L)
{
	Position P,TmpCell;
	P = L->next;
	while(P!= NULL)
	{
		TmpCell = P->next;
		free(P);
		P = TmpCell;
	}
}

void Insert(int x, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		fprintf(stderr,"Insert malloc failed");
		exit(1);
	}
	TmpCell->element = x;
	TmpCell->next = P->next;
	P->next = TmpCell;
}

void Append(int x, List L)
{
	Position P = Last(L);
	Position Tmp;
	Tmp = malloc(sizeof(struct Node));
	if(Tmp == NULL)
	{
		fprintf(stderr,"Append malloc failed");
		exit(1);
	}	
	Tmp->element = x;
	P->next = Tmp;
	Tmp->next = NULL;
}

void Delete(int x, List L)
{
	Position P, TmpCell;
	P = Find_Previous(x,L);
	if(!isLast(P,L))
	{
		TmpCell = P->next;
		P->next = TmpCell->next;
		free(TmpCell);
	}
}
int isEmpty(List L)
{
	return (L->next == NULL);
}

int isLast(Position P, List L)
{
	return (P->next ==NULL);
}

Position Last(List L)
{
	Position P;
	if(isEmpty(L))
		return L;
	P = L->next;
	while(P!=NULL && P->next!= NULL)
		P=P->next;
	return P;
}

Position Find(int x, List L)
{
	Position P;
	P = L->next;
	printf("%d\t",P->element);
	
	while(P!=NULL && P->element!=x)
	{
		printf("%d\t",P->element);
		P=P->next;
	}
	return P;
}

Position Find_Previous(int x, List L)
{
	Position P;
	P = L;
	while(P->next!=NULL && P->next->element!=x)
		P=P->next;
	return P;
}

void Print_List(List L)
{
	List toPrint = L->next;
	while(toPrint!=NULL)
	{
		printf(" %d ",toPrint->element);
		toPrint = toPrint->next;
	}
}
