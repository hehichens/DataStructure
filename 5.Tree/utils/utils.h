/*

*/

#ifndef __TREE_UTILS__C__
#define __TREE_UTILS__C__

#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define MaxSize 50
#define InitSize 100
#define bool short
#define true 1
#define false 0

typedef struct BiNode{
    ElemType data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

/*Binary Tree*/
//Init function
bool InitBiTree(BiTree *T);

//Create Binary Tree
void CreateBiTree(FILE *fp, BiTree *T);

//Length
int BiTreeLength(BiTree T);

//Depth
int BiTreeDepth(BiTree T);

//Locate node
BiNode *LocationBiTree(BiTree T, ElemType e);

//insert node
bool PrintTree(BiTree T);

//PreOrder
void PreOrder(BiTree T);

//InOrder
void InOrder(BiTree T);

//PostOrder
void PostOrder(BiTree T);

//LevelOrder
void LevelOrder(BiTree T);


/*Stack*/
typedef struct{
    BiNode data[MaxSize];
    int top;
}Stack;

//Init Stack
void InitStack(Stack *S);

//Wheather the stack is empty
bool StackEmpty(Stack S);

//Push
bool Push(Stack *S, BiNode x);


//Pop
bool Pop(Stack *S, BiNode *x);

//Get top data
bool GetTop(Stack S, BiNode *x);




/*Queue*/
typedef struct{
    BiNode data[MaxSize];
    int front, rear;
}Queue;

//Init Queue
void InitQueue(Queue *Q);

//Wheather queue is empty
bool QueueEmpty(Queue Q);

//Wheather queue is full
bool QueueFull(Queue Q);

//EnQueue
bool EnQueue(Queue *Q, BiNode x);

//DeQueue
bool DeQueue(Queue *Q, BiNode *x);


#endif