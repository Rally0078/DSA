#include "avl.h"
#include <cstdlib>
struct AvlNode{
    int Element;
    AvlTree Left;
    AvlTree Right;
    int height;
};

static int height(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->height;
}

static int Max(int a, int b)
{
    return a > b ? a : b;
}

AvlTree Insert(int X, AvlTree T)
{
    if(T == NULL)
    {
        T = new AvlNode;
        if(T == NULL)
            exit(1);
        else
        {
            T->Element = X;
            T->height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if(height(T->Left) - height(T->Right) == 2)
        {
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if(height(T->Right) - height(T->Left) == 2)
        {
            if(X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->height = Max(height(T->Left), height(T->Right)) + 1;
    return T; 
}

static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->height = Max(height(K2->Left), height(K2->Right)) +1;
    K1->height = Max(height(K1->Left), K2->height) + 1;
    return K1;
}

static Position SingleRotateWithRight(Position K1)
{
    Position K2;
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
    K1->height = Max(height(K1->Left), height(K1->Right)) +1;
    K2->height = Max(height(K2->Left), K1->height) + 1;
    return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1)
{
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}

