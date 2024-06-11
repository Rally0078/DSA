#ifndef BST_H
#define BST_H
#include <stddef.h>
#ifndef STDIO_H
#include <stdio.h>
#endif
#include <stdlib.h>
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int num, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int num, SearchTree T);
SearchTree Delete(int num, SearchTree T);
void inOrder(SearchTree T);
void preOrder(SearchTree T);
void postOrder(SearchTree T);
void singleNode(SearchTree T);
int Retrieve(Position P);
#endif