#ifndef LIST_H
#define LIST_H

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	int element;
	Position next;
};
List new_List(List L);
int isEmpty(List L);
int isLast(Position P, List L);
Position Find(int x, List L);
Position Find_Previous(int x, List L);
Position Last(List L);
void Delete(int x, List L);
void Insert(int x, List L, Position P);
void Append(int x, List L);
void Print_List(List L);
void DeleteList(List L);
void Append(int x, List L);
#endif

