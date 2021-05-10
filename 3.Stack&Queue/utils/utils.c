#include "utils.h"


/*Stack*/
//Init Stack
void InitStack(Stack *S){
    S->top = -1;
}


//Wheather the stack is empty
bool StackEmpty(Stack S){
    return (S.top == -1) ? true:false;
}


//Push
bool Push(Stack *S, ElemType x){
    if(S->top == MaxSize) 
        return false;
    S->data[++S->top] = x;
    return true;
}


//Pop
bool Pop(Stack *S, ElemType *x){
    if(S->top == -1)
        return false;
    *x = S->data[S->top--];
    return true;
}


//Get top data
bool GetTop(Stack S, ElemType *x){
    if(S.top == -1)
        return false;
    *x = S.data[S.top];
    return true;
}





/*Queue*/;

//Init Queue
void InitQueue(Queue *Q){
    Q->front = Q->rear = 0;
}


//Wheather queue is empty
bool QueueEmpty(Queue Q){
    if(Q.rear == Q.front) 
        return true;
    else
        return false;
}


//Wheather queue is full
bool QueueFull(Queue Q){
    if((Q.rear+1)%MaxSize == Q.front)
        return true;
    else
        return false;
}


//EnQueue
bool EnQueue(Queue *Q, ElemType x){
    if(QueueFull(*Q))
        return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1)%MaxSize;
    return true;
}


//DeQueue
bool DeQueue(Queue *Q, ElemType *x){
    if(QueueEmpty(*Q))
        return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1)%MaxSize;
    return true;
}