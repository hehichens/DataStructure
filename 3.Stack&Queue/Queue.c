

#include<stdio.h>
#include "./utils/utils.c"


int main(){
    Queue Q;
    printf("Initialize Queue...\n");
    InitQueue(&Q);
    printf("\nInsert data...\n");
    for(int i = 1; i <= 6; ++i){
        printf("EnQueue==>%d\n", 2*i);
        EnQueue(&Q, 2*i);
    }

    printf("\nGet front data...\n");
    ElemType e;

    for(int i = 1; i <= 6; ++i){
        DeQueue(&Q, &e);
        printf("DeQueue Data==>%d\n", e);
    }

    bool isEmpty = QueueEmpty(Q);
    if(isEmpty) printf("Empty!\n");
    else printf("Not Empty!\n");

    return 0;
}