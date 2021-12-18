#include <stdio.h>
#include "List.h"

int main(void)
{
	List L;
	L = new_List(L);
	printf("\nList program:\n");
	printf("Inserting 3,5,1,-5");
	Position P;
	Append(3,L);
	Append(5,L);
	Append(1,L);
	Append(36,L);
	Append(25,L);
	Append(-5,L);
	Append(42,L);
	Append(128,L);
	Append(-16,L);
	printf("\nList before Inserting 69 after 3:");
	Print_List(L);
	P = Find(3,L);
	Insert(69,L,P);
	printf("\nList after Inserting 69 after 3:");
	Print_List(L);
	printf("\nDeleting 1:");
	Delete(1,L);
	printf("\nList after deleting 1: ");
	Print_List(L);
	printf("\nDeleting 25:");
	Delete(25,L);
	printf("\nList after deleting 25: ");
	Print_List(L);
	printf("\nPrinting List:");
	Print_List(L);
	//printf("%d", L->next->element);
	printf("\nDeleting List");
	DeleteList(L);
	return 0;
}