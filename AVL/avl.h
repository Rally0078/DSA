#ifndef AVL_H
#define AVL_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree);
Position Find(int, AvlTree);
Position FindMin(AvlTree);
Position FindMax(AvlTree);

AvlTree Insert(int, AvlTree);
AvlTree Delete(int, AvlTree);
int Retrieve(Position);
#endif