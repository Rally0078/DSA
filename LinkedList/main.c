#include <stdio.h>
#include "listcustom.h"

int main(void)
{
	struct Node* head = NULL;
	append(&head, 12);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	printf("\n Created Linked list is: ");
	printList(head);
	
	return 0;
	
}