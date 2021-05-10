/*
utils
edit by hichens
*/

#include<stdlib.h>
#include<stdio.h>
#define ElemType int
#define bool short
#define true 1
#define false 0
#define MaxSize 50


/*Stack*/
typedef struct{
    ElemType data[MaxSize];
    int top;
}Stack;

//Init Stack
void InitStack(Stack *S);

//Wheather the stack is empty
bool StackEmpty(Stack S);

//Push
bool Push(Stack *S, ElemType x);


//Pop
bool Pop(Stack *S, ElemType *x);

//Get top data
bool GetTop(Stack S, ElemType *x);




/*Queue*/
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
}Queue;

//Init Queue
void InitQueue(Queue *Q);

//Wheather queue is empty
bool QueueEmpty(Queue Q);

//Wheather queue is full
bool QueueFull(Queue Q);

//EnQueue
bool EnQueue(Queue *Q, ElemType x);

//DeQueue
bool DeQueue(Queue *Q, ElemType *x);
